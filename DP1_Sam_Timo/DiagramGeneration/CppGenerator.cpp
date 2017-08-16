#include "CppGenerator.h"

namespace DiagramGeneration
{
	CppGenerator::CppGenerator()
	{
		InitFileTemplate();
	}

	void CppGenerator::InitFileTemplate()
	{
		std::ifstream file(styleFile);
		std::stringstream stream;
		stream << file.rdbuf();
		auto style = stream.str();
		file.close();

		std::string gates[7] = {"AND", "NAND", "NOR", "NOT", "OR", "XNOR", "XOR"};
		std::string legend = "<section class='nodes'>";
		for(auto gate : gates)
		{
			legend += R"(
				<div>
					<img src="../../img/)" + gate + R"(.png"/>
					<span class="name">)" + gate + R"(</span>
				</div>
			)";
		}
		legend += R"(</section>)";

		htmlFileDataBegin = R"(
	<!DOCTYPE HTML>

	<html>
		<head>
			<meta name="generator" content="Microsoft Visual Studio">
			<title>Diagram</title>
			<link href='../../styles/legend.css' rel='stylesheet'>
			<style>)" + style + R"(</style>
		</head>
		<body>)" + legend
		;

		htmlFileDataEnd = R"(
		</body>
	</html>)"
		;
	}

	void CppGenerator::GenerateData(Circuit& circuit)
	{
		InitVisualNodes(circuit);
		CreateColumns(circuit);
		CreateEdges();
		DeduceSvgSize();
		GenerateSvgContent();
	}

	// creates columns based on next and previous connections for the visual representation
	void CppGenerator::CreateColumns(Circuit& circuit)
	{
		std::vector<Composite*> usedComponents; // components placed in a column
		std::vector<Composite*> components; // components ready to be put in a column
		for(auto input : circuit.GetInputs())
			components.push_back(input);
		std::vector<Composite*> additionComponents; // components to add, after loop
		std::vector<Composite*> additionUsedComponents; // used components to add, after loop

		auto transferVector = [](std::vector<Composite*>& components, std::vector<Composite*>& addition)
		{
			components.insert(components.begin(), addition.begin(), addition.end());
			addition.clear();
		};

		while(components.size() != 0)
		{
			Column column;

			for (auto it = components.begin(); it != components.end(); )
			{
				auto* pComponent = *it;
				auto& node = visualNodes[pComponent];

				// test if all components that call this one have passed
				bool isEarly = false;
				for(auto previous : node.previous)
				{
					if(isEarly = std::find(usedComponents.begin(), usedComponents.end(), previous) == usedComponents.end())
						break;
				}

				// runs if all previous components have been placed
				if(!isEarly) 
				{
					node.columnIndex = columns.size();
					node.index = column.components.size();
					node.position.y = node.index * (NODE_SIZE + SPACE);

					column.components.push_back(pComponent);	
					additionUsedComponents.push_back(pComponent);

					// add next components if they haven't before
					for(auto next : node.next)
					{
						bool exists = 
							std::find(usedComponents.begin(), usedComponents.end(), next) != usedComponents.end() ||
							std::find(components.begin(), components.end(), next) != components.end() ||
							std::find(additionComponents.begin(), additionComponents.end(), next) != additionComponents.end()
						;

						// is added if didn't exist in any of the containers
						if(!exists)	
							additionComponents.push_back(next);
					}
					it = components.erase(it);
				}
				else 
					++it;
			}
			transferVector(components, additionComponents);
			transferVector(usedComponents, additionUsedComponents);

			DeduceColumnPosition(column);
			for(auto* pComponent : column.components)
				visualNodes[pComponent].position.x = column.x;
			columns.push_back(column);
		}
	}

	void CppGenerator::InitVisualNodes(Circuit& circuit)
	{
		std::function<void(Composite*)> addVisualNode;
		addVisualNode = [&](Composite* pComponent)
		{
			if(pComponent && visualNodes.find(pComponent) == visualNodes.end())
			{
				auto& node = visualNodes[pComponent];

				// assigne next relations to node
				auto nextComponents = pComponent->GetNext();
				if(nextComponents.size() != 0)
					node.next = nextComponents[0]->GetNext();

				// assigne previous relations to node
				auto previousComponents = pComponent->GetPrevious();
				for(auto previous : previousComponents)
				{
					auto previous2 = previous->GetPrevious()[0];
					node.previous.push_back(previous2);
				}

				for(auto* next : node.next)
					addVisualNode(next);
			}
		};

		for(Composite* pComponent : circuit.GetInputs())
			addVisualNode(pComponent);
	}

	// deduce x based on current and previous column connections
	void CppGenerator::DeduceColumnPosition(Column& column)
	{
		// deduce x
		if(columns.size() > 0)
		{
			// previous column, next connections
			auto previousColumn = columns.end()[-1];
			unsigned int x = previousColumn.x + NODE_SIZE + SPACE;

			for(auto pComponent : previousColumn.components)
			{
				auto& node = visualNodes[pComponent];
				auto& nextComponents = node.next;

				if(nextComponents.size() == 1)
				{
					auto nextNode = visualNodes[nextComponents[0]];
					if(!(node.columnIndex == nextNode.columnIndex && node.index == nextNode.index))
						x += SPACE;
				}
				else if(nextComponents.size() > 1)
					x += SPACE;
			}

			// current column, previous connections
			std::vector<int> previousColumns; // columns from which the component is called, ignore duplicates because they use the same line

			for(auto pComponent : column.components)
			{
				auto& node = visualNodes[pComponent];
				auto& previousComponents = node.previous;

				for(auto* pPreviousComponent : previousComponents)
				{
					auto& previousNode = visualNodes[pPreviousComponent];
					if(std::find(previousColumns.begin(), previousColumns.end(), previousNode.columnIndex) != previousColumns.end())
						previousColumns.push_back(previousNode.columnIndex);
				}
			}
			x += SPACE * previousColumns.size();

			column.x = x;
		}
		else
			column.x = 0;
		column.edgeX = column.x + NODE_SIZE + SPACE;

		// deduce y
		column.height = column.components.size() * (NODE_SIZE + SPACE) - SPACE;
		EdgePopulation population;
		population.bottom = 0;
		population.top = column.height;
		column.edgeYPopulations.push_back(population);
	}

	void CppGenerator::CreateEdges()
	{
		// test if single neightbour, only next column, or further
		for(auto column : columns)
		{
			for(auto pComponent : column.components)	
			{
				if(!pComponent)
					continue;

				auto node = visualNodes[pComponent];

				if(node.next.size() == 0)
					continue;

				bool done = false;
				bool firstLineSegment = false;
				Vector vectorOrigin;
			
				// test if there's a 'next' node right next to current
				for(auto* pNextComponent : node.next)
				{
					auto nextNode = visualNodes[pNextComponent];

					if(node.columnIndex + 1 == nextNode.columnIndex && node.index == nextNode.index)
					{
						auto entries = nextNode.previous.size() + 1;
						auto entryIndex = std::distance(nextNode.previous.begin(), std::find(nextNode.previous.begin(), nextNode.previous.end(), pComponent));
						auto part = NODE_SIZE / entries;
						auto y = nextNode.position.y + part + part * entryIndex;

						if(node.next.size() == 1)
						{
							lineSegmentBuilder.SetBeginX(node.position.x + NODE_SIZE / 2);
							lineSegmentBuilder.SetBeginY(y);
							lineSegmentBuilder.SetEndX(nextNode.position.x + NODE_SIZE / 2);
							lineSegmentBuilder.SetEndY(y);
							lineSegmentBuilder.SetColorBlue();
							lineSegments.push_back(lineSegmentBuilder);
							done = true;
							continue;
						}
						else if(*pComponent != Input::NAME)
						{
							firstLineSegment = true;
							lineSegmentBuilder.SetBeginX(node.position.x + NODE_SIZE / 2);
							lineSegmentBuilder.SetBeginY(y);
							lineSegmentBuilder.SetEndX(column.edgeX);
							lineSegmentBuilder.SetEndY(y);
							lineSegmentBuilder.SetColorBlue();
							auto lineSegment = lineSegmentBuilder.GetResult();
							lineSegments.push_back(lineSegment);
							column.edgeX += SPACE;
							vectorOrigin = lineSegment.end;
							break;
						}
					}
				}

				if(done)
					continue;

				if(!firstLineSegment)
				{
					lineSegmentBuilder.SetBeginX(node.position.x + NODE_SIZE / 2);
					lineSegmentBuilder.SetBeginY(node.position.y + NODE_SIZE / 2);
					lineSegmentBuilder.SetEndX(column.edgeX);
					lineSegmentBuilder.SetEndY(node.position.y + NODE_SIZE / 2);
					lineSegmentBuilder.SetColorBlue();
					auto lineSegment = lineSegmentBuilder.GetResult();
					lineSegments.push_back(lineSegment);
					vectorOrigin = lineSegment.end;
					column.edgeX += SPACE;
				}

				Vector vectorBottom = vectorOrigin;	
				Vector vectorTop = vectorOrigin;	
				unsigned int lastColumnIndex = 0;

				for(auto* pNextComponent : node.next)
				{
					auto& nextNode = visualNodes[pNextComponent];

					if(nextNode.columnIndex > lastColumnIndex)
						lastColumnIndex = nextNode.columnIndex;
				}

				Vector vectorRight;
				bool hasTravelLine = false;

				lastColumnIndex--;
				if(lastColumnIndex >= node.columnIndex + 1)
				{
					vectorRight.x = columns[lastColumnIndex].edgeX;		
					vectorTop.y = GetTravelY(node.columnIndex + 1, lastColumnIndex);
					vectorRight.y = vectorTop.y;
					hasTravelLine = true;
				}

				for(auto* pNextComponent : node.next)
				{
					auto& nextNode = visualNodes[pNextComponent];

					auto entries = nextNode.previous.size() + 1;
					auto entryIndex = std::distance(nextNode.previous.begin(), std::find(nextNode.previous.begin(), nextNode.previous.end(), pComponent));
					auto part = NODE_SIZE / entries;
					auto y = nextNode.position.y + part + part * entryIndex;
				
					// component in next column
					if(node.columnIndex + 1 == nextNode.columnIndex)
					{
						lineSegmentBuilder.SetBeginX(vectorOrigin.x);
						lineSegmentBuilder.SetBeginY(y);
						lineSegmentBuilder.SetEndX(nextNode.position.x + NODE_SIZE / 2);
						lineSegmentBuilder.SetEndY(y);
						lineSegmentBuilder.SetColorBlue();
						auto lineSegment = lineSegmentBuilder.GetResult();
						lineSegments.push_back(lineSegment);

						if(vectorBottom.y > lineSegment.begin.y)
							vectorBottom = lineSegment.begin;

						if(vectorTop.y < lineSegment.begin.y)
							vectorTop = lineSegment.begin;
					}
					// component in other column
					else
					{
						auto& nextColumn = columns[nextNode.columnIndex - 1];
						lineSegmentBuilder.SetBeginX(nextColumn.edgeX);		
						lineSegmentBuilder.SetBeginY(vectorTop.y);		
						lineSegmentBuilder.SetEndX(nextColumn.edgeX);
						lineSegmentBuilder.SetEndY(y);
						lineSegmentBuilder.SetColorBlack();
						auto lineSegment = lineSegmentBuilder.GetResult();
						lineSegments.push_back(lineSegment);
						nextColumn.edgeX += SPACE;

						lineSegmentBuilder.SetBegin(lineSegment.end);
						lineSegmentBuilder.SetEndX(nextNode.position.x + NODE_SIZE / 2);
						lineSegmentBuilder.SetColorBlue();
						lineSegments.push_back(lineSegmentBuilder);
					}
				}

				lineSegmentBuilder.SetBegin(vectorBottom);
				lineSegmentBuilder.SetEnd(vectorTop);
				lineSegmentBuilder.SetColorBlack();
				lineSegments.push_back(lineSegmentBuilder);

				if(hasTravelLine)
				{
					lineSegmentBuilder.SetBegin(vectorTop);
					lineSegmentBuilder.SetEnd(vectorRight);
					lineSegmentBuilder.SetColorBlack();
					lineSegments.push_back(lineSegmentBuilder);
				}
			}
		}
	}

	unsigned int CppGenerator::GetTravelY(unsigned int firstColumnIndex, unsigned int lastColumnIndex)
	{
		unsigned int y = 0;

		// find y
		while(true)
		{
			bool travelYFound = false;

			for(unsigned int i = firstColumnIndex; i <= lastColumnIndex; i++)
			{
				auto& column = columns[i];

				for(unsigned j = 0; j < column.edgeYPopulations.size(); j++)
				{
					auto& population = column.edgeYPopulations[j];

					travelYFound = y < population.bottom || y > population.top;

					if(!travelYFound)
						break;
				}

				if(!travelYFound)
					break;
			}

			if(travelYFound)
				break;

			y += SPACE;
		}

		// add to population or add new population
		for(unsigned int i = firstColumnIndex; i <= lastColumnIndex; i++)
		{
			auto& populations = columns[i].edgeYPopulations;
			bool added = false;

			for(auto& population : populations)
			{
				if(y == population.bottom - SPACE)
				{
					population.bottom -= SPACE;
					added = true;
					break;
				}
				else if(y == population.top + SPACE)
				{
					population.top += SPACE;
					added = true;
					break;	
				}
			}

			if(!added)
			{
				EdgePopulation newPopulation;
				newPopulation.bottom = y;
				newPopulation.top = y;
				populations.push_back(newPopulation);
			}
		}

		// merging populations
		for(unsigned int i = firstColumnIndex; i < lastColumnIndex; i++)
		{
			auto& populations = columns[i].edgeYPopulations;
			std::vector<std::pair<unsigned int, EdgePopulation>> newPopulations; // index, population

			for(unsigned int j = 0; j < populations.size() - 1; j++)
			{
				auto& population1 = populations[j];
				auto& population2 = populations[j+1];

				if(population1.top == population2.bottom)
				{
					EdgePopulation newPopulation;
					newPopulation.bottom = population1.bottom;	
					newPopulation.top = population2.top;	
					newPopulations.push_back(std::pair<unsigned int, EdgePopulation>(j, newPopulation));
				}
			}

			for(auto& newPopulation : newPopulations)
			{
				auto index = newPopulation.first;
				auto population = newPopulation.second;
				populations.erase(populations.begin() + index, populations.begin() + index + 1);	
				populations.insert(populations.begin() + index, population);
			}
		}

		return y;
	}

	void CppGenerator::GenerateSvgContent()
	{
		std::stringstream stream;
		stream << "<svg width = '" << svg.width << "' height='" << svg.height << "' xmlns='http://www.w3.org/2000/svg' xmlns:xlink='http://www.w3.org/1999/xlink'>";

		for(auto& lineSegment : lineSegments)
		{
			stream << "<line x1='" << lineSegment.begin.x << "' y1='" << lineSegment.begin.y << "' x2='" << lineSegment.end.x << "' y2='" << lineSegment.end.y << "' stroke='" << lineSegment.color << "' stroke-width='1'/>";
		}

		for (auto const& iteration : visualNodes)
		{
			auto* pComponent = iteration.first;
			const auto& node = iteration.second;

			if(!pComponent)
				continue;

			if(*pComponent == Input::NAME || *pComponent == Probe::NAME)
			{
				Vector circle;
				circle.x = node.position.x + NODE_SIZE / 2;
				circle.y = node.position.y + NODE_SIZE / 2;
				stream << "<circle cx='" << circle.x << "' cy='" << circle.y << "' r='10'/>";	
			}
			else
			{
				stream << "<rect class='gate' x='" << node.position.x << "' y='" << node.position.y << "' width='" << NODE_SIZE << "' height='" << NODE_SIZE << "'/>";
				stream << "<image xlink:href='../../img/" << *pComponent << ".png' x='" << node.position.x + 10 << "' y='" << node.position.y + 25 << "' width='60' height='30px'/>";
			}

			Vector vector;
			vector.x = node.position.x + 20;
			vector.y = node.position.y + 20;

			stream << "<text x='" << vector.x << "' y='" << vector.y << "'>" << pComponent->GetId() << "</text>";

			vector.x = node.position.x + 35;
			vector.y = node.position.y + NODE_SIZE / 2 + 30;
			auto value = std::to_string(pComponent->GetValues().size() > 0 ? pComponent->GetValues()[0] : 0);
			stream << "<text x='" << vector.x << "' y='" << vector.y << "'>" << value << "</text>";
		}

		stream << "</svg>";
		svg.content += stream.str();
	}

	void CppGenerator::DeduceSvgSize()
	{
		svg.width = columns.end()[-1].x + NODE_SIZE + SPACE;

		for(auto& column : columns)
		{
			for(auto& population : column.edgeYPopulations)
			{
				if(svg.height < population.top)
					svg.height = population.top;
			}
		}
		svg.height += SPACE;
	}

	void CppGenerator::WriteInputs()
	{
		std::string contents = htmlFileDataBegin + svg.content + htmlFileDataEnd;
		std::ofstream file(htmlFile);
		file << contents;
		file.close();
	}

	void CppGenerator::Show()
	{
		ShellExecute(NULL, "open", htmlFile.c_str(), NULL, NULL, SW_SHOWNORMAL);
	}
}
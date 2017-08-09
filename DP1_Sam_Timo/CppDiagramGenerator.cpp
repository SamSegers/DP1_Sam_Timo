#include "CppDiagramGenerator.h"

void CppDiagramGenerator::GenerateData(Circuit& circuit)
{
	// TODO read + regex replace svg part
	svg.content = HTML_FILE_DATA_BEGIN;

	CreateColumns(circuit);
	CreateEdges();

	std::stringstream stream;
	stream << "<svg width = '" << svg.width << "' height='" << svg.height << "'>";

	for(auto column : columns)
	{
		unsigned int i = 0;

		for(auto component : column.components)
		{
			unsigned int y = i * (COMPONENT_SIZE + SPACE);
			stream << "<rect class='gate' x='" << column.x << "' y='" << y << "' width='" << COMPONENT_SIZE << "' height='" << COMPONENT_SIZE << "'/>";
			i++;
		}
	}

	stream << "</svg>";
	svg.content += stream.str();

	svg.content += HTML_FILE_DATA_END;
}

// creates columns based on next and previous connections for the visual representation
void CppDiagramGenerator::CreateColumns(Circuit& circuit)
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
			auto a = components.size();
			auto component = *it;

			// test if all components that call this one have passed
			bool isEarly = false;
			auto previousComponents = component->GetPrevious();
			for(auto previous : previousComponents)
			{
				auto previous2 = previous->GetPrevious()[0];
				if(isEarly = std::find(usedComponents.begin(), usedComponents.end(), previous2) == usedComponents.end())
					break;
			}

			// runs if all previous components have been placed
			if(!isEarly) 
			{
				column.components.push_back(component);	
				additionUsedComponents.push_back(component);
				// add next components if they haven't before
				auto nextComponents = component->GetNext();
				if(nextComponents.size() != 0)
				{
					nextComponents = nextComponents[0]->GetNext();
					for(auto next : nextComponents)
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
				}
				it = components.erase(it);
			}
			else 
				++it;
		}
		transferVector(components, additionComponents);
		transferVector(usedComponents, additionUsedComponents);

		DeduceColumnPosition(column);
		columns.push_back(column);

		if(svg.height < column.y)
			svg.height = column.y;
	}

	svg.width = columns.end()[-1].x + COMPONENT_SIZE + SPACE;
}

// deduce x based on current and previous column connections
void CppDiagramGenerator::DeduceColumnPosition(Column& column)
{
	// deduce x
	if(columns.size() > 0)
	{
		auto previousColumn = columns.end()[-1];
		unsigned int x = previousColumn.x + COMPONENT_SIZE + SPACE;

		for(auto pComponent : previousColumn.components)
			x += pComponent->GetNext().size() * SPACE;

		x += column.components.size() * SPACE;
		column.x = x;
	}
	else
		column.x = 0;

	// deduce y
	column.y = column.components.size() * (COMPONENT_SIZE + SPACE);
}

void CppDiagramGenerator::CreateEdges()
{

}

void CppDiagramGenerator::WriteInputs()
{
	std::ofstream file(HTML_FILE);
	file << svg.content;
	file.close();
}

void CppDiagramGenerator::Show()
{
	ShellExecute(NULL, "open", HTML_FILE, NULL, NULL, SW_SHOWNORMAL);
}
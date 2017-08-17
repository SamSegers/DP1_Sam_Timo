#include "stdafx.h"
#include "Comparison.h"

#define private public
#define protected public

#include "../DP1_Sam_Timo/DiagramGeneration/Column.h"
#include "../DP1_Sam_Timo/DiagramGeneration/CppGenerator.h"

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestDiagramGeneration)
	{
	public:
		TEST_METHOD(TestEdgePopulations1)
		{
			// 1. arrange
			DiagramGeneration::CppGenerator cppGenerator;
			DiagramGeneration::Column column;
			DiagramGeneration::EdgePopulation population;
			Comparison<unsigned int> travelY(200);

			// 1.1 column 1
			Comparison<unsigned int> column1Populations(2);
			Comparison<unsigned int> column1Population1Bottom(0);
			Comparison<unsigned int> column1Population1Top(120);
			Comparison<unsigned int> column1Population2Bottom(200);
			Comparison<unsigned int> column1Population2Top(200);

			population.bottom = 0;
			population.top = 60;
			column.edgeYPopulations.push_back(population);
			population.bottom = 60;
			population.top = 120;
			column.edgeYPopulations.push_back(population);
			cppGenerator.columns.push_back(column);

			// 1.2 column 2
			Comparison<unsigned int> column2Populations(2);
			Comparison<unsigned int> column2Population1Bottom(40);
			Comparison<unsigned int> column2Population1Top(160);
			Comparison<unsigned int> column2Population2Bottom(200);
			Comparison<unsigned int> column2Population2Top(200);

			population.bottom = 40;
			population.top = 160;
			column.edgeYPopulations.clear();
			column.edgeYPopulations.push_back(population);
			cppGenerator.columns.push_back(column);

			// 1.3 column 3
			Comparison<unsigned int> column3Populations(1);
			Comparison<unsigned int> column3Population1Bottom(200);
			Comparison<unsigned int> column3Population1Top(260);

			population.bottom = 220;
			population.top = 260;
			column.edgeYPopulations.clear();
			column.edgeYPopulations.push_back(population);
			cppGenerator.columns.push_back(column);

			// 1.4 column 4
			Comparison<unsigned int> column4Populations(1);
			Comparison<unsigned int> column4Population1Bottom(100);
			Comparison<unsigned int> column4Population1Top(200);

			population.bottom = 100;
			population.top = 180;
			column.edgeYPopulations.clear();
			column.edgeYPopulations.push_back(population);
			cppGenerator.columns.push_back(column);

			// 2. act
			travelY = cppGenerator.GetTravelY(0, 3);

			column1Populations = cppGenerator.columns[0].edgeYPopulations.size();
			column1Population1Bottom = cppGenerator.columns[0].edgeYPopulations[0].bottom;
			column1Population1Top = cppGenerator.columns[0].edgeYPopulations[0].top;
			column1Population2Bottom = cppGenerator.columns[0].edgeYPopulations[1].bottom;
			column1Population2Top = cppGenerator.columns[0].edgeYPopulations[1].top;

			column2Populations = cppGenerator.columns[1].edgeYPopulations.size();
			column2Population1Bottom = cppGenerator.columns[1].edgeYPopulations[0].bottom;
			column2Population1Top = cppGenerator.columns[1].edgeYPopulations[0].top;
			column2Population2Bottom = cppGenerator.columns[1].edgeYPopulations[1].bottom;
			column2Population2Top = cppGenerator.columns[1].edgeYPopulations[1].top;

			column3Populations = cppGenerator.columns[2].edgeYPopulations.size();
			column3Population1Bottom = cppGenerator.columns[2].edgeYPopulations[0].bottom;
			column3Population1Top = cppGenerator.columns[2].edgeYPopulations[0].top;

			column4Populations = cppGenerator.columns[3].edgeYPopulations.size();
			column4Population1Bottom = cppGenerator.columns[3].edgeYPopulations[0].bottom;
			column4Population1Top = cppGenerator.columns[3].edgeYPopulations[0].top;

			// 3. assert
			travelY.assert();

			column1Populations.assert();
			column1Population1Bottom.assert();
			column1Population1Top.assert();
			column1Population2Bottom.assert();
			column1Population2Top.assert();

			column2Populations.assert();
			column2Population1Bottom.assert();
			column2Population1Top.assert();
			column2Population2Bottom.assert();
			column2Population2Top.assert();

			column3Populations.assert();
			column3Population1Bottom.assert();
			column3Population1Top.assert();

			column4Populations.assert();
			column4Population1Bottom.assert();
			column4Population1Top.assert();
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestEdgePopulations1)
			TEST_METHOD_ATTRIBUTE(L"DiagramGeneration", L"EdgePopulations")
		END_TEST_METHOD_ATTRIBUTE()
	};
}
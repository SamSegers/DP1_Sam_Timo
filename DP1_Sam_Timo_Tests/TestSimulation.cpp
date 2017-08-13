#include "stdafx.h"
#include "CppUnitTest.h"
#include "Comparison.h"
#include "../DP1_Sam_Timo/Simulation.h"

#include <fstream>
#include <regex>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestSimulation)
	{
		std::string GetDirectoryName(std::string path){
			const size_t last_slash_idx = path.rfind("\\dp1_sam_timo_tests");
			return std::string::npos != last_slash_idx ? path.substr(0, last_slash_idx + 1) : "";
		}

		std::string ReadCircuit(std::string fileName)
		{
			std::ifstream file;
			std::string filePath = GetDirectoryName(__FILE__) + "dp1_sam_timo\\circuits\\" + fileName;
			file.open(filePath);
			std::stringstream stream;
			stream << file.rdbuf();
			return stream.str();
		}

		void InitFactory()
		{
			// vul de factory met classes die we mogelijk willen gebruiken.
			Factory::instance()->AddComponent(new Node());
			Factory::instance()->AddComponent(new Edge());
			Factory::instance()->AddComponent(new Input());
			Factory::instance()->AddComponent(new Probe());
			Factory::instance()->AddComponent(new AND());
			Factory::instance()->AddComponent(new NAND());
			Factory::instance()->AddComponent(new NOR());
			Factory::instance()->AddComponent(new NOT());
			Factory::instance()->AddComponent(new OR());
			Factory::instance()->AddComponent(new XNOR());
			Factory::instance()->AddComponent(new XOR());
		}

	public:
		TEST_METHOD(TestCircuit1)
		{
			// arange
			Simulation simulation;
			InitFactory();

			std::vector<Comparison<std::string>> idComparisons;
			idComparisons.push_back(Comparison<std::string>("Cout"));
			idComparisons.push_back(Comparison<std::string>("S"));
			std::vector<Comparison<int>> valueComparisons;
			valueComparisons.push_back(Comparison<int>(1));
			valueComparisons.push_back(Comparison<int>(0));

			// TODO use FileReader
			auto circuit = ReadCircuit("Circuit1_FullAdder.txt");
			std::vector<Probe*> probes = simulation.StartTest(circuit);

			// act
			idComparisons[0] = probes[0]->GetId();
			valueComparisons[0] = probes[0]->GetValues()[0];
			idComparisons[1] = probes[1]->GetId();
			valueComparisons[1] = probes[1]->GetValues()[0];

			// assert
			for(auto& comparison : idComparisons)
				Assert::AreEqual(comparison.expected, comparison.actual, L"message", LINE_INFO());
			for(auto& comparison : valueComparisons)
				Assert::AreEqual(comparison.expected, comparison.actual, L"message", LINE_INFO());
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestCircuit1)
			TEST_METHOD_ATTRIBUTE(L"Circuit", L"1")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

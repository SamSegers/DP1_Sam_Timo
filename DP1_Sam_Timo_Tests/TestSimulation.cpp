#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/Simulation.h"

#include <fstream>
#include <regex>
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestSimulation)
	{
		std::string getDirectoryName(std::string path){
			const size_t last_slash_idx = path.rfind("\\dp1_sam_timo_tests");
			return std::string::npos != last_slash_idx ? path.substr(0, last_slash_idx + 1) : "";
		}

	public:
		TEST_METHOD(TestCircuit1)
		{
			// arange
			Simulation simulation;

			std::string expectedProbe1Id = "Cout";
			int expectedProbe1Value = 1;

			std::string expectedProbe2Id = "S";
			int expectedProbe2Value = 0;

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

			std::ifstream file;
			std::string filePath = getDirectoryName(__FILE__) + "dp1_sam_timo\\circuits\\circuit1.txt";
			file.open(filePath);
			std::stringstream stream;
			stream << file.rdbuf();
			std::string arg = stream.str();
			std::vector<Probe*> probes = simulation.StartTest(arg);

			// act
			std::string actualProbe1Id = probes[0]->GetId();
			int actualProbe1Value = probes[0]->GetValues()[0];

			std::string actualProbe2Id = probes[1]->GetId();
			int actualProbe2Value = probes[1]->GetValues()[0];

			// assert
			Assert::AreEqual(expectedProbe1Id, actualProbe1Id, L"message", LINE_INFO());
			Assert::AreEqual(expectedProbe1Value, actualProbe1Value, L"message", LINE_INFO());

			Assert::AreEqual(expectedProbe2Id, actualProbe2Id, L"message", LINE_INFO());
			Assert::AreEqual(expectedProbe2Value, actualProbe2Value, L"message", LINE_INFO());
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestCircuit1)
			TEST_METHOD_ATTRIBUTE(L"Circuit", L"1")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/Simulation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestSimulation)
	{
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

			std::vector<Probe *> probes = simulation.StartTest("# Circuit1.txt\n\
# \n\
# Full-adder. Deze file bevat een correct circuit\n\
# \n\
#\n\
#\n\
# Description of all the nodes\n\
#\n\
A:	INPUT_HIGH;\n\
B:	INPUT_HIGH;\n\
Cin: 	INPUT_LOW;\n\
Cout:	PROBE;\n\
S:	PROBE;\n\
NODE1:	OR;\n\
NODE2:	AND;\n\
NODE3:	AND;\n\
NODE4:	NOT;\n\
NODE5:	AND;\n\
NODE6:	OR;\n\
NODE7:	NOT;\n\
NODE8:	NOT;\n\
NODE9:	AND;\n\
NODE10:	AND;\n\
NODE11:	OR;\n\
\n\
#\n\
#\n\
# Description of all the edges\n\
#\n\
Cin:	NODE3,NODE7,NODE10;\n\
A:	NODE1,NODE2;\n\
B:	NODE1,NODE2;\n\
NODE1:	NODE3,NODE5;\n\
NODE2:	NODE4,NODE6;\n\
NODE3:	NODE6;\n\
NODE4:	NODE5;\n\
NODE5:	NODE8,NODE9;\n\
NODE6:	Cout;\n\
NODE7:	NODE9;\n\
NODE8:	NODE10;\n\
NODE9:	NODE11;\n\
NODE10:	NODE11;\n\
NODE11:	S;\n");

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

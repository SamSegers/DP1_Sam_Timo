#include "stdafx.h"
#include "../DP1_Sam_Timo/Nodes/NOT.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestNOT), public TestNode
	{
	public:
		TestNOT::TestNOT() 
		{
			TestNode::node = std::make_shared<NOT>();
		}

		TEST_METHOD(TestNOT1)
		{
			// arange
			int insertValue = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue, expectedValue);
		}

		TEST_METHOD(TestNOT2)
		{
			// arange
			int insertValue = 1;
			int expectedValue = 0;
			NOT not;

			// act, assert
			Test(insertValue, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOT1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOT")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOT2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOT")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

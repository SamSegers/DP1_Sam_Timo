#include "stdafx.h"
#include "../DP1_Sam_Timo/Nodes/NOR.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestNOR), public TestNode
	{
	public:
		TestNOR::TestNOR() 
		{
			TestNode::node = std::make_shared<NOR>();
		}

		TEST_METHOD(TestNOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;
			NOR nor;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOR1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOR2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOR3)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOR4)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOR")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

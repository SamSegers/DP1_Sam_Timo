#include "stdafx.h"
#include "../DP1_Sam_Timo/Nodes/OR.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestOR), public TestNode
	{
	public:
		TestOR::TestOR()
		{
			TestNode::node = std::make_shared<OR>();
		}

		TEST_METHOD(TestOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestOR1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"OR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestOR2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"OR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestOR3)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"OR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestOR4)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"OR")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

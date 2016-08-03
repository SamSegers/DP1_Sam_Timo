#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/AND.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestAND), public TestNode
	{
	public:
		TestAND::TestAND()
		{
			TestNode::node = new AND();
		}

		TEST_METHOD(TestAND1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestAND2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestAND3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestAND4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestAND1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"AND")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestAND2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"AND")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestAND3)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"AND")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestAND4)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"AND")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

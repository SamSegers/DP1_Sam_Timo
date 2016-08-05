#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/XOR.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestXOR), public TestNode
	{
	public:
		TestXOR::TestXOR()
		{
			TestNode::node = new XOR();
		}

		TEST_METHOD(TestXOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXOR1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXOR2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXOR3)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXOR4)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XOR")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

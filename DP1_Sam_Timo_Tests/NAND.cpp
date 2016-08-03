#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/NAND.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestNAND), public TestNode
	{
	public:
		TestNAND::TestNAND()
		{
			TestNode::node = new NAND();
		}

		TEST_METHOD(TestNAND1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNAND2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNAND3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNAND4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNAND1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NAND")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNAND2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NAND")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNAND3)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NAND")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNAND4)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NAND")
		END_TEST_METHOD_ATTRIBUTE()
	};
}

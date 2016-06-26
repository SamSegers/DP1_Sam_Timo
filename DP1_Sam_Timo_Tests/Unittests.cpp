#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/AND.h"
#include "../DP1_Sam_Timo/NAND.h"
#include "../DP1_Sam_Timo/NOR.h"
#include "../DP1_Sam_Timo/NOT.h"
#include "../DP1_Sam_Timo/OR.h"
#include "../DP1_Sam_Timo/XNOR.h"
#include "../DP1_Sam_Timo/XOR.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{		
	TEST_CLASS(TestOperations)
	{
	public:

#pragma region AND

		void TestAND(int insertValue1, int insertValue2, int expectedValue) 
		{
			// arange
			AND and;

			// act
			and.InsertValue(insertValue1);
			and.InsertValue(insertValue2);
			and.ExecuteOperation();
			int actualValue = and.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestAND1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			TestAND(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestAND2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			TestAND(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestAND3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			TestAND(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestAND4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			TestAND(insertValue1, insertValue2, expectedValue);
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

#pragma endregion AND

#pragma region NAND

		void TestNAND(int insertValue1, int insertValue2, int expectedValue) 
		{
			// arrange
			NAND nand;

			// act
			nand.InsertValue(insertValue1);
			nand.InsertValue(insertValue2);
			nand.ExecuteOperation();
			int actualValue = nand.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNAND1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			TestNAND(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNAND2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			TestNAND(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNAND3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			TestNAND(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNAND4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			TestNAND(insertValue1, insertValue2, expectedValue);
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

#pragma endregion NAND

#pragma region NOR

		void TestNOR(int insertValue1, int insertValue2, int expectedValue) 
		{
			// arrange
			NOR nor;

			// act
			nor.InsertValue(insertValue1);
			nor.InsertValue(insertValue2);
			nor.ExecuteOperation();
			int actualValue = nor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			TestNOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			TestNOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;
			NOR nor;

			// act, assert
			TestNOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestNOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			TestNOR(insertValue1, insertValue2, expectedValue);
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

#pragma endregion NOR

#pragma region NOT

		void TestNOT(int insertValue, int expectedValue) 
		{
			// arrange
			NOT not;

			// act
			not.InsertValue(insertValue);
			not.ExecuteOperation();
			int actualValue = not.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}
		
		TEST_METHOD(TestNOT1)
		{
			// arange
			int insertValue = 0;
			int expectedValue = 1;

			// act, assert
			TestNOT(insertValue, expectedValue);
		}

		TEST_METHOD(TestNOT2)
		{
			// arange
			int insertValue = 1;
			int expectedValue = 0;
			NOT not;

			// act, assert
			TestNOT(insertValue, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOT1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOT")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestNOT2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"NOT")
		END_TEST_METHOD_ATTRIBUTE()

#pragma endregion NOT

#pragma region OR

		void TestOR(int insertValue1, int insertValue2, int expectedValue)
		{
			// arrange
			OR or;

			// act
			or.InsertValue(insertValue1);
			or.InsertValue(insertValue2);
			or.ExecuteOperation();
			int actualValue = or.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			TestOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			TestOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			TestOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			TestOR(insertValue1, insertValue2, expectedValue);
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

#pragma endregion OR

#pragma region XNOR

		void TestXNOR(int insertValue1, int insertValue2, int expectedValue) 
		{
			// arrange
			XNOR xnor;

			// act
			xnor.InsertValue(insertValue1);
			xnor.InsertValue(insertValue2);
			xnor.ExecuteOperation();
			int actualValue = xnor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXNOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			TestXNOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXNOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			TestXNOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXNOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			TestXNOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXNOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			TestXNOR(insertValue1, insertValue2, expectedValue);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXNOR1)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XNOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXNOR2)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XNOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXNOR3)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XNOR")
		END_TEST_METHOD_ATTRIBUTE()

		BEGIN_TEST_METHOD_ATTRIBUTE(TestXNOR4)
			TEST_METHOD_ATTRIBUTE(L"Operation", L"XNOR")
		END_TEST_METHOD_ATTRIBUTE()

#pragma endregion XNOR

#pragma region XOR

		void TestXOR(int insertValue1, int insertValue2, int expectedValue) 
		{
			// arrange
			XOR xor;

			// act
			xor.InsertValue(insertValue1);
			xor.InsertValue(insertValue2);
			xor.ExecuteOperation();
			int actualValue = xor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());

		}

		TEST_METHOD(TestXOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			TestXOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			TestXOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			TestXOR(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			TestXOR(insertValue1, insertValue2, expectedValue);
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

#pragma endregion XOR

	};
}
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

		TEST_METHOD(TestAND1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;
			AND and;

			// act
			and.InsertValue(insertValue1);
			and.InsertValue(insertValue2);
			and.ExecuteOperation();
			int actualValue = and.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestAND2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;
			AND and;

			// act
			and.InsertValue(insertValue1);
			and.InsertValue(insertValue2);
			and.ExecuteOperation();
			int actualValue = and.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestAND3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;
			AND and;

			// act
			and.InsertValue(insertValue1);
			and.InsertValue(insertValue2);
			and.ExecuteOperation();
			int actualValue = and.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestAND4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;
			AND and;

			// act
			and.InsertValue(insertValue1);
			and.InsertValue(insertValue2);
			and.ExecuteOperation();
			int actualValue = and.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion AND

#pragma region NAND

		TEST_METHOD(TestNAND1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;
			NAND nand;

			// act
			nand.InsertValue(insertValue1);
			nand.InsertValue(insertValue2);
			nand.ExecuteOperation();
			int actualValue = nand.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNAND2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;
			NAND nand;

			// act
			nand.InsertValue(insertValue1);
			nand.InsertValue(insertValue2);
			nand.ExecuteOperation();
			int actualValue = nand.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNAND3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;
			NAND nand;

			// act
			nand.InsertValue(insertValue1);
			nand.InsertValue(insertValue2);
			nand.ExecuteOperation();
			int actualValue = nand.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNAND4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;
			NAND nand;

			// act
			nand.InsertValue(insertValue1);
			nand.InsertValue(insertValue2);
			nand.ExecuteOperation();
			int actualValue = nand.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion NAND

#pragma region NOR

		TEST_METHOD(TestNOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;
			NOR nor;

			// act
			nor.InsertValue(insertValue1);
			nor.InsertValue(insertValue2);
			nor.ExecuteOperation();
			int actualValue = nor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;
			NOR nor;

			// act
			nor.InsertValue(insertValue1);
			nor.InsertValue(insertValue2);
			nor.ExecuteOperation();
			int actualValue = nor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;
			NOR nor;

			// act
			nor.InsertValue(insertValue1);
			nor.InsertValue(insertValue2);
			nor.ExecuteOperation();
			int actualValue = nor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;
			NOR nor;

			// act
			nor.InsertValue(insertValue1);
			nor.InsertValue(insertValue2);
			nor.ExecuteOperation();
			int actualValue = nor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion NOR

#pragma region NOT
		
		TEST_METHOD(TestNOT1)
		{
			// arange
			int insertValue = 0;
			int expectedValue = 1;
			NOT not;

			// act
			not.InsertValue(insertValue);
			not.ExecuteOperation();
			int actualValue = not.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestNOT2)
		{
			// arange
			int insertValue = 1;
			int expectedValue = 0;
			NOT not;

			// act
			not.InsertValue(insertValue);
			not.ExecuteOperation();
			int actualValue = not.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion NOT

#pragma region OR

		TEST_METHOD(TestOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;
			OR or;

			// act
			or.InsertValue(insertValue1);
			or.InsertValue(insertValue2);
			or.ExecuteOperation();
			int actualValue = or.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;
			OR or;

			// act
			or.InsertValue(insertValue1);
			or.InsertValue(insertValue2);
			or.ExecuteOperation();
			int actualValue = or.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;
			OR or;

			// act
			or.InsertValue(insertValue1);
			or.InsertValue(insertValue2);
			or.ExecuteOperation();
			int actualValue = or.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;
			OR or;

			// act
			or.InsertValue(insertValue1);
			or.InsertValue(insertValue2);
			or.ExecuteOperation();
			int actualValue = or.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion OR

#pragma region XNOR

		TEST_METHOD(TestXNOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;
			XNOR xnor;

			// act
			xnor.InsertValue(insertValue1);
			xnor.InsertValue(insertValue2);
			xnor.ExecuteOperation();
			int actualValue = xnor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXNOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;
			XNOR xnor;

			// act
			xnor.InsertValue(insertValue1);
			xnor.InsertValue(insertValue2);
			xnor.ExecuteOperation();
			int actualValue = xnor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXNOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;
			XNOR xnor;

			// act
			xnor.InsertValue(insertValue1);
			xnor.InsertValue(insertValue2);
			xnor.ExecuteOperation();
			int actualValue = xnor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXNOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;
			XNOR xnor;

			// act
			xnor.InsertValue(insertValue1);
			xnor.InsertValue(insertValue2);
			xnor.ExecuteOperation();
			int actualValue = xnor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion XNOR

#pragma region XOR

		TEST_METHOD(TestXOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 0;
			XOR xor;

			// act
			xor.InsertValue(insertValue1);
			xor.InsertValue(insertValue2);
			xor.ExecuteOperation();
			int actualValue = xor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 1;
			XOR xor;

			// act
			xor.InsertValue(insertValue1);
			xor.InsertValue(insertValue2);
			xor.ExecuteOperation();
			int actualValue = xor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 1;
			XOR xor;

			// act
			xor.InsertValue(insertValue1);
			xor.InsertValue(insertValue2);
			xor.ExecuteOperation();
			int actualValue = xor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

		TEST_METHOD(TestXOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 0;
			XOR xor;

			// act
			xor.InsertValue(insertValue1);
			xor.InsertValue(insertValue2);
			xor.ExecuteOperation();
			int actualValue = xor.GetValue();

			// assert
			Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
		}

#pragma endregion XOR

	};
}
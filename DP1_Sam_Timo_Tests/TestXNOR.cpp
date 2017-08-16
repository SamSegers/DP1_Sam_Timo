#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/Nodes/XNOR.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	TEST_CLASS(TestXNOR), public TestNode
	{
	public:
		TestXNOR::TestXNOR() 
		{
			TestNode::node = std::make_shared<XNOR>();
		}

		TEST_METHOD(TestXNOR1)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 0;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXNOR2)
		{
			// arange
			int insertValue1 = 0;
			int insertValue2 = 1;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXNOR3)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 0;
			int expectedValue = 0;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
		}

		TEST_METHOD(TestXNOR4)
		{
			// arange
			int insertValue1 = 1;
			int insertValue2 = 1;
			int expectedValue = 1;

			// act, assert
			Test(insertValue1, insertValue2, expectedValue);
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
	};
}

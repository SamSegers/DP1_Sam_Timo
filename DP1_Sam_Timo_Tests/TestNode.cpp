#include "stdafx.h"
#include "CppUnitTest.h"
#include "../DP1_Sam_Timo/XOR.h"
#include "Node.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

TestNode::TestNode(){}

TestNode::~TestNode(){}

void TestNode::Test(int insertValue, int expectedValue)
{
	// act
	node->InsertValue(insertValue);
	node->ExecuteOperation();
	int actualValue = node->GetValue();

	// assert
	Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
}

void TestNode::Test(int insertValue1, int insertValue2, int expectedValue)
{
	// act
	node->InsertValue(insertValue1);
	node->InsertValue(insertValue2);
	node->ExecuteOperation();
	int actualValue = node->GetValue();

	// assert
	Assert::AreEqual(expectedValue, actualValue, L"message", LINE_INFO());
}
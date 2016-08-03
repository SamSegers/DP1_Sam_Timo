#pragma once

class TestNode
{
public:
	Node* node;

	TestNode();
	virtual ~TestNode();
	void Test(int insertValue, int expectedValue);
	void Test(int insertValue1, int insertValue2, int expectedValue);
};


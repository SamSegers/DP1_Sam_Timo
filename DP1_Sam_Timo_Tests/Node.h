#pragma once

class TestNode
{
public:
	std::shared_ptr<Node> node;

	TestNode();
	virtual ~TestNode();
	void Test(int insertValue, int expectedValue);
	void Test(int insertValue1, int insertValue2, int expectedValue);
};


#pragma once

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DP1_Sam_Timo_Tests
{
	template<typename T>
	class Comparison
	{
	private:
		T expected;	
		T actual;

	public:
		Comparison(T expected)
		{
			this->expected = expected;
		}

		const T operator=(const T& actual)
		{
			this->actual = actual;
			return this->actual;
		}

		void assert()
		{
			Assert::AreEqual(expected, actual, L"message", LINE_INFO());
		}
	};
}
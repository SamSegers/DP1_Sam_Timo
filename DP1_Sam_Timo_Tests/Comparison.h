#pragma once

namespace DP1_Sam_Timo_Tests
{
	template<typename T>
	struct Comparison
	{
		Comparison(T expected)
		{
			this->expected = expected;
		}

		const T operator=(const T& actual)
		{
			this->actual = actual;
			return this->actual;
		}

		T expected;	
		T actual;
	};
}
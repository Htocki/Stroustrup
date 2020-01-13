#pragma once
#include <iostream>



namespace Chrono 
{
	class Year {
		static constexpr int _min = 0;
		static constexpr int _max = 10000;

	public:
		class Invalid {};

		Year(int);
		int number() const { return _number; }
		friend std::ostream& operator<<(std::ostream&, const Year&);

	private:
		int _number;

		bool is_valid();
	};
}
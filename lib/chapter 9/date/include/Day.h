#pragma once
#include <iostream>



namespace Chrono
{
	class Day {
		static constexpr int _min = 1;
		int _max = 0;

	public:
		class Invalid {};

		Day(int);	// Intermediate constructor.
		Day(int, int);
		int number() const { return _number; }
		friend std::ostream& operator<< (std::ostream&, const Day&);

	private:
		int _number;

		bool is_valid();
	};
}
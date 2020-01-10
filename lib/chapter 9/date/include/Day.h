#pragma once
#include <iostream>



namespace Chrono
{
	class Day {
	public:
		Day(int);
		friend std::ostream& operator<< (std::ostream&, const Day&);

	private:
		int _day;
	};
}
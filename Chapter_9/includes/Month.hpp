#pragma once
#include <iostream>



namespace Chrono
{
	enum class Month {
		January = 1,
		February,
		March,
		April,
		May,
		June,
		July,
		August,
		September,
		October,
		November,
		December
	};


	Month int_to_month(int);

	Month operator++(Month&);

	std::ostream& operator<<(std::ostream&, const Month&);
	std::istream& operator>>(std::istream&, Month&);
}
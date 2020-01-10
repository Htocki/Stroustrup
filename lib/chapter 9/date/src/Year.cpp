#include "Year.h"



namespace Chrono
{
	Year::Year(int number)
		: _number(number)
	{}

	std::ostream& operator<< (std::ostream& os, const Year& year) {
		os << year._number;
		return os;
	}
}
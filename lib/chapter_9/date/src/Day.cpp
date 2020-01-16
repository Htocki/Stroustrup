#include "Day.h"



namespace Chrono
{
	// Intermediate constructor.
	Day::Day(int number)
		: _number(number)
	{}

	Day::Day(int number, int max = 0)
		: _number(number)
		, _max(max)
	{
		if (!is_valid()) throw Invalid{};
	}

	bool Day::is_valid() {
		if (_number < _min || _number > _max)
			return false;
		else
			return true;
	}

	std::ostream& operator<<(std::ostream& os, const Day& day) {
		os << day._number;
		return os;
	}
}
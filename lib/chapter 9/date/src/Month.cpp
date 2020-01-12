#include "Month.h"



namespace Chrono
{
	Month::Month(int number)
		: _number(number)
	{
		if (!is_valid()) throw Invalid{};
	}

	Month::Month(::Month name)
		: _number(static_cast<int>(name))
	{}

	std::ostream& operator<< (std::ostream& os, const Month& month) {
		os << month._number;
		return os;
	}

	bool Month::is_valid()
	{
		if (_number < _min || _number > _max)
			return false;
		else
			return true;
	}
}
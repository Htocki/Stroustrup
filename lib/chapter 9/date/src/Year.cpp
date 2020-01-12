#include "Year.h"



namespace Chrono
{
	Year::Year(int number)
		: _number(number)
	{
		if (!is_valid()) throw Invalid{};
	}

	std::ostream& operator<< (std::ostream& os, const Year& year) {
		os << year._number;
		return os;
	}

	bool Year::is_valid() {
		if (_number < _min || _number > _max) 
			return false;
		else 
			return true;
	}
}
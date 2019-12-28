#include "Year.h"



namespace Chrono
{
	Year::Year(int number) 
		: _number(number) 
	{
		if (number < min || number > max) throw Invalid{};
	}

	bool Year::isLeap() {
		if (_number % 4 == 0) {
			if ((_number % 100 == 0) && (_number % 400 != 0))
				return false;
			return true;
		}
		else return false;
	}

	Year& Year::operator++() {
		int number = _number;
		++number;
		if (number > max) throw Invalid{};
		else ++_number;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Year& y) {
		return os << y.number();
	}

	std::istream& operator>>(std::istream& is, Year& y) {
		return is >> y._number;
	}

	bool operator==(const Year& lhs, const Year& rhs) {
		if (lhs.number() == rhs.number())
			return true;
		else
			return false;
	}

	bool operator!=(const Year& lhs, const Year& rhs) {
		if (lhs.number() != rhs.number()) return true;
		else return false;
	}

	int operator%(const Year& y, const int number) {
		return y.number() % number;
	}
}
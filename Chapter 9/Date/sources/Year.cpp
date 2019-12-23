#include "Year.h"



namespace Chrono
{
	Year::Year(int year) : _year(year) {
		if (year < min || year >= max) throw Invalid{};
	}

	Year& Year::operator++() {
		// Тут должна быть добавлена проверка
		++_year;
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Year& y) {
		return os << y.year();
	}

	std::istream& operator>>(std::istream& is, const Year& y) {
		return is >> y.year();
	}

	bool operator==(const Year& lhs, const Year& rhs) {
		if (lhs.year() == rhs.year())
			return true;
		else
			return false;
	}

	bool operator!=(const Year& lhs, const Year& rhs) {
		if (lhs.year() != rhs.year())
			return true;
		else
			return false;
	}

	int operator%(const Year& lhs, int rhs) {
		return lhs.year() % rhs;
	}
}
#include "Day.h"



namespace Chrono
{
	Day::Day(int number)
		: _number(number)
	{}
	/*
	Day& Day::operator++() {
		// Тут должа быть добавлена проверка
		++_number;
		return *this;
	}

	bool operator==(const Day& lhs, const Day& rhs) {
		if (lhs.number() == rhs.number())
			return true;
		else
			return false;
	}

	bool operator!=(const Day& lhs, const Day& rhs) {
		if (lhs.number() != rhs.number()) return true;
		else return false;
	}

	std::ostream& operator<<(std::ostream& os, const Day& d) {
		return os << d.number;
	}

	std::istream& operator>>(std::istream& is, Day& d) {
		return is >> d._number;
	}
	*/
}
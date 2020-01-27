#include "Year.h"



namespace Chrono
{
	Year::Year(int number)
		: number(number)
	{
		if (!is_valid()) throw Invalid{};
	}

	Year& Year::operator++() {
		if (number == max) throw Invalid{};
		else ++number;
		return *this;
	}

	bool Year::is_valid() {
		if (number < min || number > max) return false;
		else return true;
	}

	std::ostream& operator<<(std::ostream& os, const Year& year) {
		os << year.getNumber();
		return os;
	}

	bool operator==(const Year& left, const Year& right) {
		if (left.getNumber() == right.getNumber()) return true;
		else return false;
	}

	bool operator!=(const Year& left, const Year& right) {
		return !operator==(left, right);
	}
}
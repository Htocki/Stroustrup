#include "Day.h"



// Intermediate constructor.
Day::Day(int number)
	: number(number)
{}

Day::Day(int number, int max)
	: number(number)
	, max(max)
{
	if (!is_valid()) throw Invalid{};
}

Day& Day::operator++() {
	if (number == max) number = min;
	else ++number;
	return *this;
}

bool Day::is_valid() {
	if (number < min || number > max) return false;
	else return true;
}

std::ostream& operator<<(std::ostream& os, const Day& day) {
	os << day.getNumber();
	return os;
}

bool operator==(const Day& left, const Day& right) {
	if (left.getNumber() == right.getNumber()) return true;
	else return false;
}

bool operator!=(const Day& left, const Day& right) {
	return !operator==(left, right);
}
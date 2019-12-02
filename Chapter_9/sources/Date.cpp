#include "includes/Date.hpp"

Date::Date(Year yy, Month mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if (!is_valid()) throw Invalid{};
}

bool Date::is_valid() {
    if (int(m)<1 || int(m)>12) return false;
    else return true;
}

std::ostream& operator<<(std::ostream &os, const Date &date) {
    return os 
		<< date.y << "."
		<< date.m << "."
		<< date.d;
}

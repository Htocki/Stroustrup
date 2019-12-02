#include "includes/Date.hpp"

Date::Date(int yy, int mm, int dd)
    : y{yy}, m{mm}, d{dd}
{
    if (!is_valid()) throw Invalid{};
}

bool Date::is_valid() {
    if (m<1 || m>12) return false;
    else return true;
}

std::ostream & operator << (std::ostream &out, const Date &date) {
    out
        << date.y << "." 
        << date.m << "." 
        << date.d;
    return out;
}
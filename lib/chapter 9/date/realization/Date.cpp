#include "Date.h"



namespace Chrono
{
    Date::Date(Year year, Month month, Day day)
        : _year (year)
        , _month(month)
        , _day(day)
    {}

    void Date::print() {
        std::cout
            << "[" << _year
            << "." << _month
            << "." << _day
            << "]" << std::endl;
    }
}
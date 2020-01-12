#include "Date.h"



namespace Chrono
{
    Date::Date()
        : _year(default_date().year())
        , _month(default_date().month())
        , _day(default_date().day())
    {}

    Date::Date(Year year, Month month, Day day)
        : _year(year)
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

    std::ostream& operator<< (std::ostream& os, const Date& date) {
        os << date._year << "." << date._month << "." << date._day;
        return os;
    }

    // Secondary functions.
    bool leapyear(int number) {
        if (number % 4 == 0) {
            if (number % 100 == 0 && number % 400 != 0) return false;
            else return true;
        }
        else return false;
    }

    const Date& default_date() {
        static Date date(2001, 1, 1);
        return date;
    }
}
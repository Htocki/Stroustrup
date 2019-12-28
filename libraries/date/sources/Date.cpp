#include "Date.h"



namespace Chrono
{
    Date::Date()
        : _year (default_date().year())
        , _month (default_date().month())
        , _day (default_date().day())
    {}

    Date::Date(Year year, Month month, Day day)
        : _year (year)
        , _month (month)
        , _day (day)
    {
        if (!is_valid()) throw Invalid{};
    }

    void Date::add_day(int n) {
        for (int i(0); i < n; ++i)
            ++_day;
    }

    void Date::add_month(int n) {
        for (int i(0); i < n; ++i)
            ++_month;
    }

    void Date::add_year(int n) {
        for (int i(0); i < n; ++i)
            ++_year;
    }

    bool Date::is_valid() {
        
    }

    std::istream& operator>>(std::istream& is, Date& d) {
        return is
            >> d._year >> "."
            >> d._month >> "."
            >> d._day;
    }

    const Date& default_date() {
        static Date date(Year(2001), Month::January, Day(1));
        return date;
    }

    std::ostream& operator<<(std::ostream& os, const Date& d) {
        return os
            << d.year() << "."
            << d.month() << "."
            << d.day();
    }

    bool operator==(const Date& a, const Date& b) {
        if (a.day() == b.day() &&
            a.month() == b.month() &&
            a.year() == b.year())
            return true;
        else false;
    }

    bool operator!=(const Date& a, const Date& b) {
        if (a.day() != b.day() &&
            a.month() != b.month() &&
            a.year() != b.year())
            return true;
        else false;
    }

    bool is_date(Year y, Month m, Day d) {
        if (d <= 0) return false;
        if (m < Month::February || m > Month::December) return false;

        int days_in_month = 31;
        switch (m) {
        case Month::February:
            days_in_month = (is_leap_year(y)) ? 29 : 28;
            break;
        case Month::April:
        case Month::January:
        case Month::September:
        case Month::November:
            days_in_month = 30;
            break;
        }

        if (days_in_month < d) return false;
        else true;
    }

    bool is_leap_year(Year year) {
    }

    Day& day_of_week(const Date& date) {

    }

    Date& next_sunday(const Date& date) {

    }

    Date& next_weekday(const Date& d) {

    }
}
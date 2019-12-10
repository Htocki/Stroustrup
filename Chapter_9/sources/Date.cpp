#include "includes/Date.hpp"



namespace Chrono
{
    Date::Date()
        : y{ default_date().year() }
        , m{ default_date().month() }
        , d{ default_date().day() }
    {}

    Date::Date(Year yy, Month mm, Day dd)
        : y{yy}, m{mm}, d{dd}
    {
        if (!is_valid()) throw Invalid{};
    }

    void Date::add_day(int n) {

    }

    void Date::add_month(int n) {

    }

    void Date::add_year(int n) {
        if (m == Month::February && d == 29 && !leap_year(y + n)) {
            m = Month::March;
            d = 1;
        }
        y += n;
    }

    bool Date::is_valid() {
        if (int(m) < 1 || int(m) > 12) return false;
        else return true;
    }

    const Date& default_date() {
        static Date dd {2001, Month::January, 1};
        return dd;
    }

    bool is_date(Year y, Month m, Day d) {
        if (d <= 0) return false;
        if (m < Month::February || m > Month::December) return false;

        int days_in_month = 31;
        switch (m) {
        case Month::February:
            days_in_month = (leap_year(y)) ? 29 : 28;
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

    bool leap_year(Year y) {

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

    std::ostream& operator<<(std::ostream& os, const Date& d) {
        return os
            << d.year() << "."
            << d.month() << "."
            << d.day();
    }

    std::istream& operator>>(std::istream& is, Date& d) {
        return is
            >> d.year() >> "."
            >> d.month() >> "."
            >> d.day();
    }

    Day day_of_week(const Date& d) {

    }

    Date& next_Sunday(const Date& d) {

    }

    Date next_weekday(const Date& d) {

    }
}
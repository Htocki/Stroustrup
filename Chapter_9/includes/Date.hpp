#pragma once
#include "includes/Year.hpp"
#include "includes/Month.hpp"
#include "includes/Day.hpp"
#include <iostream>


namespace Chrono
{
    class Date {
    public:
        class Invalid {};   // Used for exception.

        Date();
        Date(Year y, Month m, Day d);   // Check and initialize the date.

        Year year() const   { return y; }   // Inline.
        Month month() const { return m; }   // Inline.
        Day day() const     { return d; }   // Inline.

        void add_day(int);
        void add_month(int);
        void add_year(int);

    private:
        Year y;
        Month m;
        Day d;

        bool is_valid();    // If the date is correct, returns true.
    };

    const Date& default_date();
    bool is_date(Year, Month, Day);
    bool leap_year(Year);
    bool operator==(const Date&, const Date&);
    bool operator!=(const Date&, const Date&);
    std::ostream& operator<<(std::ostream&, const Date&);
    std::istream& operator>>(std::istream&, Date&);
    Day day_of_week(const Date&);
    Date& next_Sunday(const Date&);
    Date next_weekday(const Date&);
}
#pragma once
#include "Year.h"
#include "Month.h"
#include "Day.h"
#include <iostream>



namespace Chrono
{
    class Date {
    public:
        class Invalid {};   // Used for exception.

        Date();
        Date(Year, Month, Day);   // Check and initialize the date.

        Year year() const   { return _year; }
        Month month() const { return _month; }
        Day day() const     { return _day; }

        // void add_day(int);
        // void add_month(int);
        // void add_year(int);


    private:
        Year _year;
        Month _month;
        Day _day;

        bool is_valid();

        // friend std::istream& operator>>(std::istream&, Date&);
    };

    const Date& default_date();

    // std::ostream& operator<<(std::ostream&, const Date&);
    // bool operator==(const Date&, const Date&);
    // bool operator!=(const Date&, const Date&);

    // bool is_date(Year, Month, Day);
    // bool is_leap_year(Year);

    // Day& day_of_week(const Date&);
    // Date& next_sunday(const Date&);
    // Date& next_weekday(const Date&);
}
#pragma once
#include <iostream>
#include <vector>
#include "Year.h"
#include "Month.h"
#include "Day.h"



namespace Chrono
{
    class Date {
    public:
        Date();
        Date(Year, Month, Day);

        Year year() const { return _year; }
        Month month() const { return _month; }
        Day day() const { return _day; }

        void print();

        friend std::ostream& operator<<(std::ostream&, const Date&);

    private:
        Year _year;
        Month _month;
        Day _day;
    };

    // Secondary functions.
    bool leapyear(Year);
    const Date& default_date();
    int days_in_month(Year, Month);
}
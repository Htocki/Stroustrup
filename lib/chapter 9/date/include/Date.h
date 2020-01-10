#pragma once
#include <iostream>
#include "Year.h"
#include "Month.h"
#include "Day.h"



namespace Chrono
{
    class Date {
    public:
        Date(Year, Month, Day);

        Year year() { return _year; }
        Month month() { return _month; }
        Day day() { return _day; }

        void print();

        friend std::ostream& operator<< (std::ostream&, const Date&);

    private:
        Year _year;
        Month _month;
        Day _day;
    };


    // Secondary functions.
    bool leapyear(int);
}
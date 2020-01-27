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

        void add_year(int);
        void add_month(int);
        void add_day(int);

        void print();

        friend std::ostream& operator<<(std::ostream&, const Date&);
        friend std::istream& operator>>(std::istream&, Date&);

    private:
        Year _year;
        Month _month;
        Day _day;
    };

    bool operator==(const Date&, const Date&);
    bool operator!=(const Date&, const Date&);
    bool leapyear(Year);
    const Date& default_date();
    int days_in_month(Year, Month);
    ::Day day_of_week(const Date&);
}
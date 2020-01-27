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

        Year getYear() const { return this->year; }
        Month getMonth() const { return this->month; }
        Day getDay() const { return this->day; }

        void add_year(int);
        void add_month(int);
        void add_day(int);

        void print();

        friend std::istream& operator>>(std::istream&, Date&);

    private:
        Year year;
        Month month;
        Day day;
    };
    
    std::ostream& operator<<(std::ostream&, const Date&);
    bool operator==(const Date&, const Date&);
    bool operator!=(const Date&, const Date&);
    bool leapyear(Year);
    const Date& default_date();
    int days_in_month(Year, Month);
    ::Day day_of_week(const Date&);
    Date next_sunday(const Date&);
    Date next_weekday(const Date&);
}
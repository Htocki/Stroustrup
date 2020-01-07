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
        void print();

    private:
        Year _year;
        Month _month;
        Day _day;
    };
}
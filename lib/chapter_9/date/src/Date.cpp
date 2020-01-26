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
        , _day(day.getNumber(), days_in_month(year, month))
    {}

    void Date::add_year(int yearsAmount) {
        Date fakeDate(*this);

        while (yearsAmount) {
            ++fakeDate._year;
            --yearsAmount;
        }
        
        *this = fakeDate;
    }

    void Date::add_month(int monthsAmount) {
        Date fakeDate(*this);

        while (monthsAmount) {
            ++fakeDate._month;
            --monthsAmount;
            if (fakeDate.month().getNumber() == 1)
                fakeDate.add_year(1);
        }
        
        *this = fakeDate;
    }

    void Date::add_day(int daysAmount) {
        Date fakeDate(*this);

        while (daysAmount) {
            ++fakeDate._day;
            --daysAmount;
            if (fakeDate.day().getNumber() == 1) {
                fakeDate.add_month(1);
                fakeDate._day.setMax(
                    days_in_month(fakeDate.year(), fakeDate.month())
                );
            }
        }

        *this = fakeDate;   
    }

    void Date::print() {
        std::cout
            << "[" << _year
            << "." << _month
            << "." << _day
            << "]" << std::endl;
    }

    std::ostream& operator<<(std::ostream& os, const Date& date) {
        os << date._year << "." << date._month << "." << date._day;
        return os;
    }

    bool operator==(const Date& left, const Date& right) {
        if (left.day() == right.day() &&
            left.month() == right.month() &&
            left.year() == right.year())
            return true;
        else
            return false;
    }

    bool operator!=(const Date& left, const Date& right) {
        return !operator==(left, right);
    }


    bool leapyear(Year year) {
        if (year.getNumber() % 4 == 0) {
            if (year.getNumber() % 100 == 0 && year.getNumber() % 400 != 0) 
                return false;
            else 
                return true;
        }
        else return false;
    }

    const Date& default_date() {
        static Date date(2001, 1, 1);
        return date;
    }

    int days_in_month(Year year, Month month) {
        std::vector<int> months {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 
        };

        if (leapyear(year)) months[1] = 29;

        return months.at(month.getNumber() - 1);
    }
}
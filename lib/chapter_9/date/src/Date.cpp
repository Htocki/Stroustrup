#include "Date.h"



Date::Date()
    : year(default_date().getYear())
    , month(default_date().getMonth())
    , day(default_date().getDay())
{}

Date::Date(Year year, Month month, Day day)
    : year(year)
    , month(month)
    , day(day.getNumber(), days_in_month(year, month))
{}

void Date::add_year(int yearsAmount) {
    Date fakeDate(*this);

    while (yearsAmount) {
        ++fakeDate.year;
        --yearsAmount;
    }
        
    *this = fakeDate;
}

void Date::add_month(int monthsAmount) {
    Date fakeDate(*this);

    while (monthsAmount) {
        ++fakeDate.month;
        --monthsAmount;
        if (fakeDate.getMonth().getNumber() == 1)
            fakeDate.add_year(1);
    }
        
    *this = fakeDate;
}

void Date::add_day(int daysAmount) {
    Date fakeDate(*this);

    while (daysAmount) {
        ++fakeDate.day;
        --daysAmount;
        if (fakeDate.getDay().getNumber() == 1) {
            fakeDate.add_month(1);
            fakeDate.day.setMax(
                days_in_month(fakeDate.getYear(), fakeDate.getMonth())
            );
        }
    }

    *this = fakeDate;   
}

void Date::print() {
    std::cout
        << "[" << year
        << "." << month
        << "." << day
        << "]" << std::endl;
}

std::istream& operator>>(std::istream& is, Date& date) {
    int year, month, day;
    std::cout << "Input year number: "; is >> year;
    std::cout << "Input month number: "; is >> month;
    std::cout << "Input day number: "; is >> day;
    Date fakeDate(year, month, day);
    date = fakeDate;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Date& date) {
    os  << date.getYear() << "." 
        << date.getMonth() << "." 
        << date.getDay();
    return os;
}

bool operator==(const Date& left, const Date& right) {
    if (left.getDay() == right.getDay() &&
        left.getMonth() == right.getMonth() &&
        left.getYear() == right.getYear())
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

Day::Name day_of_week(const Date& date) {
    int day = date.getDay().getNumber();
    int month = date.getMonth().getNumber();
    int year = date.getYear().getNumber();

    if (month < 3u) {
        --year;
        month += 10u;
    }
    else
        month -= 2u;

    return static_cast<Day::Name>(
        (day + 31u * month / 12u + year + year / 4u - year / 100u
            + year / 400u) % 7u
        );
}

Date next_sunday(const Date& date) {
    Date fakeDate(date);
    do fakeDate.add_day(1);
    while (day_of_week(fakeDate) != Day::Name::Sunday);
    return fakeDate;
}

Date next_weekday(const Date& date) {
    Date fakeDate(date);
    do fakeDate.add_day(1);
    while (day_of_week(fakeDate) == Day::Name::Saturday
        || day_of_week(fakeDate) == Day::Name::Sunday);
    return fakeDate;
}
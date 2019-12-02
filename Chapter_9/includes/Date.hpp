#pragma once
#include <iostream>



enum class Month {
    jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

enum class Day {
    monday, tuesday, wednesday, thursday, friday, saturday, sunday
};



class Date {
public:
    class Invalid {};   // Used for exception.

    Date(int y, int m, int d);  // Check and initialize the date.
    
    int month() { return m; }   // Inline.
    int day()   { return d; }   // Inline.
    int year()  { return y; }   // Inline.

    friend std::ostream & operator << (std::ostream &out, const Date &d);

public:
    int y, m, d;

    bool is_valid();    // If the date is correct, returns true. 
};
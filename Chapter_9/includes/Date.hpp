#pragma once
#include "includes/Year.hpp"
#include "includes/Month.hpp"
#include <iostream>



class Date {
public:
    class Invalid {};   // Used for exception.


    Date(Year y, Month m, int d);  // Check and initialize the date.
    
	Year year()		{ return y; }   // Inline.
	Month month()	{ return m; }   // Inline.
    int day()		{ return d; }   // Inline.

    friend std::ostream& operator<<(std::ostream&, const Date&);

public:
	Year y;
	Month m;
	int d;

    bool is_valid();    // If the date is correct, returns true.

};
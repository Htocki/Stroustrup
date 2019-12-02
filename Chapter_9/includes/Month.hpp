#pragma once
#include <ostream>


enum class Month {
	jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};


Month int_to_month(int x); 

Month operator++(Month& m);

std::ostream& operator<<(std::ostream& os, Month m);
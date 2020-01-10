#include "Date.h"
#include <string>
#include <iostream>



int main() {
	Chrono::Date d(1220, 2, 23);
	d.print();

	std::cout << "Current data: "
		<< d.year() << "."
		<< d.month() << "."
		<< d.day() << std::endl;

	Chrono::Date d1(1777, 0, 0); 
	std::cout
		<< "Leap year [" << d1 << "]: "
		<< Chrono::leap_year(d1.year().number())
		<< std::endl;

	Chrono::Date d2(1512, 0, 0);
	std::cout 
		<< "Leap year [" << d2 << "]: "
		<< Chrono::leap_year(d2.year().number()) 
		<< std::endl;

	Chrono::Date d3(1100, 0, 0);
	std::cout
		<< "Leap year [" << d3 << "]: "
		<< Chrono::leap_year(d3.year().number())
		<< std::endl;

	Chrono::Date d4(2000, 0, 0);
	std::cout
		<< "Leap year [" << d4 << "]: "
		<< Chrono::leap_year(d4.year().number())
		<< std::endl;

	std::string s;
	std::getline(std::cin, s);
}
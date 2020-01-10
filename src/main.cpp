#include "Date.h"
#include <string>
#include <iostream>



int main() {
	try {
		Chrono::Date d(1220, 2, 23);
		d.print();

		Chrono::Date d0(1800, Month::March, 23);
		d0.print();

		std::cout << "Current data: "
			<< d.year() << "."
			<< d.month() << "."
			<< d.day() << std::endl;

		Chrono::Date d1(1777, 1, 0);
		std::cout
			<< "Leap year [" << d1 << "]: "
			<< Chrono::leapyear(d1.year().number())
			<< std::endl;

		Chrono::Date d2(1512, 2, 0);
		std::cout
			<< "Leap year [" << d2 << "]: "
			<< Chrono::leapyear(d2.year().number())
			<< std::endl;

		Chrono::Date d3(1100, 3, 0);
		std::cout
			<< "Leap year [" << d3 << "]: "
			<< Chrono::leapyear(d3.year().number())
			<< std::endl;

		Chrono::Date d4(2000, 4, 0);
		std::cout
			<< "Leap year [" << d4 << "]: "
			<< Chrono::leapyear(d4.year().number())
			<< std::endl;
	}
	catch (Chrono::Date::Invalid) {
		std::cerr << "Exception: Date is incorrect." << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown exception." << std::endl;
	}
	
	std::string s;
	std::getline(std::cin, s);
}

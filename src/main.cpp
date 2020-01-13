#include "Date.h"
#include <string>
#include <iostream>



int main() {
	try {
		Chrono::Date d(1820, 1, 23);
		d.print();

		Chrono::Date d01(1800, Month::March, 23);
		d01.print();

		Chrono::Date d02;
		d02.print();

		std::cout << "Current data: "
			<< d.year() << "."
			<< d.month() << "."
			<< d.day() << std::endl;

		Chrono::Date d1(2200, 2, 28);
		std::cout
			<< "Leap year [" << d1 << "]: "
			<< Chrono::leapyear(d1.year().number())
			<< std::endl;

		Chrono::Date d2(1912, 3, 29);
		std::cout
			<< "Leap year [" << d2 << "]: "
			<< Chrono::leapyear(d2.year().number())
			<< std::endl;

		Chrono::Date d3(1900, 2, 28);
		std::cout
			<< "Leap year [" << d3 << "]: "
			<< Chrono::leapyear(d3.year().number())
			<< std::endl;

		Chrono::Date d4(2000, 2, 29);
		std::cout
			<< "Leap year [" << d4 << "]: "
			<< Chrono::leapyear(d4.year().number())
			<< std::endl;
	}
	catch (Chrono::Year::Invalid) {
		std::cerr << "Exception: year is incorrect." << std::endl;
	}
	catch (Chrono::Month::Invalid) {
		std::cerr << "Exception: month is incorrect." << std::endl;
	}
	catch (Chrono::Day::Invalid) {
		std::cerr << "Exception: day is incorrect." << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown exception." << std::endl;
	}
	
	std::string s;
	std::getline(std::cin, s);
}

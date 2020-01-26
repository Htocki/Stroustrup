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
			<< Chrono::leapyear(d1.year().getNumber())
			<< std::endl;

		Chrono::Date d2(1912, 3, 29);
		std::cout
			<< "Leap year [" << d2 << "]: "
			<< Chrono::leapyear(d2.year().getNumber())
			<< std::endl;

		Chrono::Date d3(1900, 2, 28);
		std::cout
			<< "Leap year [" << d3 << "]: "
			<< Chrono::leapyear(d3.year().getNumber())
			<< std::endl;

		Chrono::Date d4(2000, 2, 29);
		std::cout
			<< "Leap year [" << d4 << "]: "
			<< Chrono::leapyear(d4.year().getNumber())
			<< std::endl;


		std::cout << std::endl << std::endl;

		Chrono::Date addDate(2020, 1, 17);
		addDate.print();

		addDate.add_year(5);
		addDate.print();

		addDate.add_month(14);
		addDate.print();

		addDate.add_day(365);
		addDate.print();

		addDate.add_day(366);
		addDate.print();

		addDate.add_day(17);
		addDate.print();

		addDate.add_day(366);
		addDate.print();

		addDate.add_day(366);
		addDate.print();

		addDate.add_day(366);
		addDate.print();


		std::cout << std::endl << std::endl;
		Chrono::Date eq1, eq2;
		eq1.print();
		eq2.print();
		std::cout << "Equality operator: " << (eq1 == eq2) << std::endl;
		std::cout << "Inequality operator: " << (eq1 != eq2) << std::endl;
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

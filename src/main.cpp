#include <string>
#include <iostream>
#include "Date.h"
#include "Name_pairs.h"
#include "Book.h"



using namespace Chrono;



int main() {
	/*
	try {
		Date d(1820, 1, 23);
		d.print();

		Date d01(1800, Month::Name::March, 23);
		d01.print();

		Date d02;
		d02.print();

		std::cout << "Current data: "
			<< d.getYear() << "."
			<< d.getMonth() << "."
			<< d.getDay() << std::endl;


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
		Date eq1, eq2;
		eq1.print();
		eq2.print();
		std::cout << "Equality operator: " << (eq1 == eq2) << std::endl;
		std::cout << "Inequality operator: " << (eq1 != eq2) << std::endl;


		std::cout << std::endl << std::endl;
		std::cout << "Entering date..." << std::endl;
		Date inputDate;
		std::cin >> inputDate;
		inputDate.print();

	}
	catch (Year::Invalid) {
		std::cerr << "Exception: year is incorrect." << std::endl;
	}
	catch (Month::Invalid) {
		std::cerr << "Exception: month is incorrect." << std::endl;
	}
	catch (Day::Invalid) {
		std::cerr << "Exception: day is incorrect." << std::endl;
	}
	catch (...) {
		std::cerr << "Unknown exception." << std::endl;
	}*/


	/*
	std::cout << std::endl << std::endl;
	Name_pairs pairs;
	pairs.read_names();
	pairs.read_ages();
	pairs.print();
	pairs.sort();
	std::cout << pairs << std::endl;
	Name_pairs left{ {"Adolf", 45}, {"Michal", 56} };
	Name_pairs right{ {"Adolf", 45}, {"Michal", 56} };
	std::cout << "left == right: " << operator==(left, right) << std::endl;
	std::cout << "left != right: szz" << operator!=(left, right) << std::endl;
	*/


	try {
		Book book{
			"Hustoruua Bielarusiu",
			"Uanus Alieuskiu",
			"2423-2234-2304-D",
			Date(2020, 12, 1)
		};

	}
	catch (...) {
		std::cerr << "Exception... :(" << std::endl;
	}

	std::string s;
	std::getline(std::cin, s);
}

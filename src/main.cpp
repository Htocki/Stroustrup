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

	std::string s;
	std::getline(std::cin, s);
}
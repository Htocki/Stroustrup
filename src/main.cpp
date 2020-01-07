#include "Date.h"
#include <string>
#include <iostream>


int main() {
	Chrono::Date d(1220, 2, 23);
	d.print();
	std::string s;
	std::getline(std::cin, s);
}
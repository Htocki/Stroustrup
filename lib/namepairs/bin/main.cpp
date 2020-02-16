#include <iostream>
#include <string>

#include "Namepairs.h"

int main() {
	Namepairs n;
	n = Namepairs{
		{"Adam", 9},
		{"Rejtan", 16}
	};
	n.ReadNames();
	n.ReadNames();
	n.ReadAges();
	n.ReadNames();
	n.ReadAges();
	
	std::cout << n << std::endl;

	std::string s;
	std::getline(std::cin, s);
}
#include <iostream>

#include "Money.h"

int main() {
	try {
		Money a;
		Money b{ 1.325, Currency::USD };
		Money c{ 1.325, Currency::DKK };

		std::cout
			<< "a: " << a << "\n"
			<< "b: " << b << "\n"
			<< "c: " << c << "\n"
			<< "sum: " << b + c << "\n"
			<< "sum: " << c + b << "\n"
			<< std::endl;

		Money d;
		std::cin >> d;
		std::cout << d << "\n"
			<< std::endl;
	}
	catch (Money::IncorrectInput) {
		std::cerr << 
			"\nException: Money::IncorrectInput" << std::endl;
	}

	return 0;
}
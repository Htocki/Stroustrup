#include "Rational.h"

int main() {
	Rational a;
	Rational b{ 3, 2 };
	Rational c{ 2, 3 };

	std::cout
		<< "rational b: " << b << std::endl
		<< "rational c: " << c << std::endl
		<< "double b: " << b.ToDouble() << std::endl
		<< "double c: " << c.ToDouble() << std::endl
		<< std::endl;

	return 0;
}
#include "Rational.h"

int main() {
	Rational default;
	Rational a{ 3, 2 };
	Rational b{ 2, 3 };

	std::cout
		<< "rational a: " << a << std::endl
		<< "rational b: " << b << std::endl
		<< "double a: " << a.ToDouble() << std::endl
		<< "double b: " << b.ToDouble() << std::endl
		<< std::endl;

	return 0;
}
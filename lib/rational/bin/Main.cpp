#include "Rational.h"

int main() {
	Rational r;
	Rational lhs{ 3, 2 };
	Rational rhs{ 2, 3 };

	std::cout << "lhs: " << lhs << std::endl
		<< "rhs: " << rhs << std::endl;

	return 0;
}
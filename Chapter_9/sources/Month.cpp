#include "includes/Month.hpp"



Month int_to_month(int x) {
	if (x < int(Month::jan) || int(Month::dec) < x)
		std::cerr << "Wrong month!" << std::endl;
	return Month(x);
}

Month operator++(Month& m)
{
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

std::ostream& operator<<(std::ostream& os, const Month m) {
	return os << int(m);
}
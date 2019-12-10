#include "includes/Month.hpp"


namespace Chrono
{
	Month int_to_month(int x) {
		if (x < int(Month::January) || int(Month::December) < x)
			std::cerr << "Wrong month!" << std::endl;
		return Month(x);
	}

	Month operator++(Month& m)
	{
		m = (m == Month::December)
			? Month::January
			: Month(int(m) + 1);
		return m;
	}

	std::ostream& operator<<(std::ostream& os, const Month& m) {
		return os << int(m);
	}

	std::istream& operator>>(std::istream& is, Month m) {
		return is >> int(m);
	}
}
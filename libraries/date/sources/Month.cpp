#include "Month.h"


namespace Chrono
{
	Month::Month(Name name, Year year)
		: _name(name)
	{
		if (year.leap()) { // Если год високосный
			_name = 
		}
	}

	Month int_to_month(int number) {
		if (number < int(Month::Name::January) || int(Month::Name::December) < number)
			std::cerr << "Wrong month!" << std::endl;
		return Month::Name(number);
	}

	Month operator++(Month& month)
	{
		month = (month.name() == Month::Name::December)
			? Month::Name::January	
			: Month(int(month) + 1);
		return m;
	}

	std::ostream& operator<<(std::ostream& os, const Month& m) {
		return os << int(m);
	}

	std::istream& operator>>(std::istream& is, Month m) {
		return is >> int(m);
	}
}
#include "Month.h"


namespace Chrono
{
	Month::Month(Name name, Year year)
	{
		if (year.isLeap()) {
			_months.push_back(std::pair{ Name::January, 31 });
			_months.push_back(std::pair{ Name::February, 29 });
			_months.push_back(std::pair{ Name::March, 31 });
			_months.push_back(std::pair{ Name::April, 30 });
			_months.push_back(std::pair{ Name::May, 31 });
			_months.push_back(std::pair{ Name::June, 30 });
			_months.push_back(std::pair{ Name::July, 31 });
			_months.push_back(std::pair{ Name::August, 31 });
			_months.push_back(std::pair{ Name::September, 30 });
			_months.push_back(std::pair{ Name::October, 31 });
			_months.push_back(std::pair{ Name::November, 30 });
			_months.push_back(std::pair{ Name::December, 31 });
		}
		else {
			_months.push_back(std::pair{ Name::January, 31 });
			_months.push_back(std::pair{ Name::February, 28 });
			_months.push_back(std::pair{ Name::March, 31 });
			_months.push_back(std::pair{ Name::April, 30 });
			_months.push_back(std::pair{ Name::May, 31 });
			_months.push_back(std::pair{ Name::June, 30 });
			_months.push_back(std::pair{ Name::July, 31 });
			_months.push_back(std::pair{ Name::August, 31 });
			_months.push_back(std::pair{ Name::September, 30 });
			_months.push_back(std::pair{ Name::October, 31 });
			_months.push_back(std::pair{ Name::November, 30 });
			_months.push_back(std::pair{ Name::December, 31 });
		}
	}
	/*
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
	*/
}
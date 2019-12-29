#pragma once
#include <cstddef>
#include <iostream>
#include <vector>
#include "Year.h"



namespace Chrono
{
	class Month {
	public:
		enum class Name {
			January = 1,
			February,
			March,
			April,
			May,
			June,
			July,
			August,
			September,
			October,
			November,
			December
		};

		Month(Name){}
		Month(Name, Year);
		
		// Name name() const;
		// int days_count() const;

		// Month& operator++();

	private:
		std::vector<std::pair<Name, std::size_t>> _months;
		Name _current_month = Name::January;
	};

	// Month int_to_month(int);

	// Month operator++(Month&);

	// std::ostream& operator<<(std::ostream&, const Month&);
	// std::istream& operator>>(std::istream&, Month&);
}
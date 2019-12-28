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
			January,
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

		Month(Name, Year);
		
		Name name() const;
		int days_count() const;

		Month& operator++();

	private:
		Name		_name;
		std::size_t _days_count;
	};

	Month int_to_month(int);

	Month operator++(Month&);

	std::ostream& operator<<(std::ostream&, const Month&);
	std::istream& operator>>(std::istream&, Month&);
}
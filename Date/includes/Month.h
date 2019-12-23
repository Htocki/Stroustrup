#pragma once
#include <iostream>



namespace Chrono
{
	class Month {
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

	public:
		Month();
		
		Name name() const;
		int days_count() const;

		Month& operator++();

	private:
		Name _name;
		int _days_count;
	};


	Month int_to_month(int);

	Month operator++(Month&);

	std::ostream& operator<<(std::ostream&, const Month&);
	std::istream& operator>>(std::istream&, Month&);
}
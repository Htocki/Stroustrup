#pragma once
#include <iostream>


namespace Chrono
{
	class Year {
		static constexpr int min = 1800;
		static constexpr int max = 2200;

	public:
		class Invalid {};

		Year(int);
		int year() const { return _year; }
		
		// Учесть максимальное значение
		Year& operator++(); 


	private:
		int _year;

		friend std::istream& operator>>(std::istream&, Year&);

	};

	std::ostream& operator<<(std::ostream&, const Year&);
	bool operator==(const Year&, const Year&);
	bool operator!=(const Year&, const Year&);
	int operator%(Year y, int);
}
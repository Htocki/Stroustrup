#pragma once
#include <iostream>



namespace Chrono 
{
	class Day {
		static constexpr int min = 1;
		static int max;

	public:
		Day(int);

		int number() const { return _number; }

		// Учесть максимальное значение
		// Day& operator++();


	private:
		int _number;

		// friend std::istream& operator>>(std::istream&, Day&);
	};

	// std::ostream& operator<<(std::ostream&, const Day&);
	// bool operator==(const Day&, const Day&);
	// bool operator!=(const Day&, const Day&);
}
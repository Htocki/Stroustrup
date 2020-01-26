#pragma once
#include <iostream>



namespace Chrono
{
	class Day {
		static constexpr int min = 1;
		int max = 0;

	public:
		class Invalid {};

		Day(int);	// Intermediate constructor.
		Day(int, int);

		int getNumber() const { return number; }

		void setMax(int max) { this->max = max; }

		Day& operator++();

		friend std::ostream& operator<<(std::ostream&, const Day&);

	private:
		int number;
	};

	bool operator==(const Day&, const Day&);
	bool operator!=(const Day&, const Day&);
}
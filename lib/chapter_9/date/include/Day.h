#pragma once
#include <iostream>



namespace Chrono
{
	class Day {
	public:
		enum class Name {
			Sunday,
			Monday,
			Tuesday,
			Wednesday,
			Thursday,
			Friday,
			Saturday
		};

	private:
		static constexpr int min = 1;
		int max = 0;

	public:
		class Invalid {};

		Day(int);	// Intermediate constructor.
		Day(int, int);

		int getNumber() const { return number; }

		void setMax(int max) { this->max = max; }

		Day& operator++();

	private:
		bool is_valid();

		int number;
	};

	std::ostream& operator<<(std::ostream&, const Day&);
	bool operator==(const Day&, const Day&);
	bool operator!=(const Day&, const Day&);
}
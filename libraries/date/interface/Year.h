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
		int number() const { return _number; }	
		bool isLeap();
		Year& operator++();

	private:
		int _number;

		friend std::istream& operator>>(std::istream&, Year&);
	};

	std::ostream& operator<<(std::ostream&, const Year&);
	bool operator==(const Year&, const Year&);
	bool operator!=(const Year&, const Year&);
	int operator%(const Year&, const int);
}
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
		int year() const { return y; }

	private:
		int y;
	};

	std::ostream& operator<<(std::ostream&, const Year&);
	std::istream& operator>>(std::istream&, Year&);
}

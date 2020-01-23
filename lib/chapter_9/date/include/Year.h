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

		int getNumber() const { return number; }

		Year& operator++();

		friend std::ostream& operator<<(std::ostream&, const Year&);

	private:
		int number;
	};
}
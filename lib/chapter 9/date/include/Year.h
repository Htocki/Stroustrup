#pragma once
#include <iostream>



namespace Chrono 
{
	class Year {
		static constexpr int _min = 1800;
		static constexpr int _max = 2200;

	public:
		class Invalid {};

		Year(int);
		int number() { return _number; }
		friend std::ostream& operator<< (std::ostream&, const Year&);

	private:
		int _number;

		bool is_valid();
	};
}
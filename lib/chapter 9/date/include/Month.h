#pragma once
#include <iostream>



enum class Month {
	January = 1,
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



namespace Chrono
{
	class Month {
		static constexpr int _min = 1;
		static constexpr int _max = 12;

	public:
		class Invalid {};

		Month(int);
		Month(::Month);
		int number() const { return _number; }
		friend std::ostream& operator<< (std::ostream&, const Month&);

	private:
		int _number;

		bool is_valid();
	};
}
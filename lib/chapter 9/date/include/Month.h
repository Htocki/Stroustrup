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
	public:
		Month(int);
		Month(::Month);
		int number() { return _number; }
		friend std::ostream& operator<< (std::ostream&, const Month&);

	private:
		int _number;
	};
}
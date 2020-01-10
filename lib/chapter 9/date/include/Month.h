#pragma once
#include <iostream>



namespace Chrono
{
	class Month {
	public:
		Month(int);
		int number() { return _number; }
		friend std::ostream& operator<< (std::ostream&, const Month&);

	private:
		int _number;
	};
}
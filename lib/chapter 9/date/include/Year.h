#pragma once
#include <iostream>



namespace Chrono 
{
	class Year {
	public:
		Year(int);
		int number() { return _number; }
		friend std::ostream& operator<< (std::ostream&, const Year&);

	private:
		int _number;
	};
}
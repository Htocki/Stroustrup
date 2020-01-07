#pragma once
#include <iostream>



namespace Chrono 
{
	class Year {
	public:
		Year(int);
		friend std::ostream& operator<< (std::ostream&, const Year&);

	private:
		int _year;
	};
}
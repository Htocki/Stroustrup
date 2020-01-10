#pragma once
#include <iostream>



namespace Chrono
{
	class Month {
	public:
		Month(int);
		friend std::ostream& operator<< (std::ostream&, const Month&);

	private:
		int _month;
	};
}
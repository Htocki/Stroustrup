#include "includes/Date.hpp"
#include "includes/Pause.hpp"

#include <iostream>




int main() {
    try {
        Date d {2009, Month::sep, 12};
        std::cout << d << std::endl;
    }
    catch (Date::Invalid) {
        std::cerr << "Invalid date." << std::endl;
    }
	catch (Year::Invalid) {
		std::cerr << "Invalid year." << std::endl;
	}

	Month m = Month::sep;
	++m;	// oct
	++m;	// nov
	++m;	// dec
	++m;	// jan

	pause();
}


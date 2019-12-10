#include "includes/Date.hpp"
#include "includes/Pause.hpp"

#include <iostream>




int main() {
    try {
		Chrono::Date today {1963, Chrono::Month::May, 19};
		today.add_day(1);
		Chrono::Date tomorrow = today;
		std::cout << today << std::endl;
		std::cout << tomorrow << std::endl;
    }
    catch (Chrono::Date::Invalid) {
        std::cerr << "Invalid date." << std::endl;
    }
	catch (Chrono::Year::Invalid) {
		std::cerr << "Invalid year." << std::endl;
	}

	pause();
}


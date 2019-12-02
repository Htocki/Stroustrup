#include "includes/Date.hpp"
#include <iostream>



int main() {
    try {
        Date d {2009, 45, 12};
        std::cout << d << std::endl;
    }
    catch (Date::Invalid) {
        std::cerr << "Invalid date." << std::endl;
    }
}
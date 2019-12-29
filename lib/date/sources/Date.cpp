#include "Date.h"



namespace Chrono
{
    Date::Date()
        : a(1)
        , b(2)
        , c(3)
    {}

    void Date::print() {
        std::cout
            << "a: " << a << std::endl
            << "b: " << b << std::endl
            << "c: " << c << std::endl
            << std::endl;
    }
}
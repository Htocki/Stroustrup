#include "includes/Year.hpp"



Year::Year(int x) : y{ x } {
	if (x < min || x >= max) throw Invalid{};
}

std::ostream& operator<<(std::ostream& os, const Year& year) {
	return os << year.y;
}
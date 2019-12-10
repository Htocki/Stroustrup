#include "includes/Year.hpp"



namespace Chrono
{
	Year::Year(int x) : y{ x } {
		if (x < min || x >= max) throw Invalid{};
	}

	std::ostream& operator<<(std::ostream& os, const Year& y) {
		return os << y.year();
	}

	std::istream& operator>>(std::istream& is, const Year& y) {
		return is >> y.year();
	}
}
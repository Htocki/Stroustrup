#pragma once

#include <cstdint>
#include <iosfwd>

class Rational {
public:
	Rational() = default;
	Rational(std::int64_t numerator, std::int64_t denominator);

	Rational& operator+=(const Rational other);
	Rational& operator-=(const Rational other);
	Rational& operator*=(const Rational other);
	Rational& operator/=(const Rational other);

	double ToDouble();

	friend std::ostream& operator<<(
		std::ostream& os,
		const Rational other
	);

	friend bool operator==(const Rational lhs, const Rational rhs);
	friend bool operator!=(const Rational lhs, const Rational rhs);

private:
	auto Print(std::ostream& os) const ->std::ostream&;
	void Reduce();

	std::int64_t numerator_ = { 1 };
	std::int64_t denominator_ = { 1 };
};

Rational operator+(const Rational lhs, const Rational rhs);
Rational operator-(const Rational lhs, const Rational rhs);
Rational operator*(const Rational lhs, const Rational rhs);
Rational operator/(const Rational lhs, const Rational rhs);
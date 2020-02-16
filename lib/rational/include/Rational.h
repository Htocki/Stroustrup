#pragma once

#include <iostream>

class Rational {
public:
	Rational() = default;
	Rational(int numerator, int denominator);

	Rational operator+=(const Rational other);
	Rational operator-=(const Rational other);
	Rational operator*=(const Rational other);
	Rational operator/=(const Rational other);

	double ToDouble();

	friend std::ostream& operator<<(
		std::ostream& os,
		const Rational
	);

	friend bool operator==(const Rational lhs, const Rational rhs);
	friend bool operator!=(const Rational lhs, const Rational rhs);

private:
	auto Print(std::ostream& os) const ->std::ostream&;
	Rational Reduce() const;

	int numerator = { 1 };
	int denominator = { 1 };
};

Rational operator+(const Rational lhs, const Rational rhs);
Rational operator-(const Rational lhs, const Rational rhs);
Rational operator*(const Rational lhs, const Rational rhs);
Rational operator/(const Rational lhs, const Rational rhs);
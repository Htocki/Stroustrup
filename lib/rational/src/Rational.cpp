#include "Rational.h"


namespace {
	int gcd(int a, int b);
	int lcm(int a, int b);
}


Rational::Rational(int numerator, int denominator)
	: numerator(numerator)
	, denominator(denominator)
{}

Rational Rational::operator+=(const Rational other) {
	Rational a = (*this).Reduce();
	Rational b = other.Reduce();

	int multiple = lcm(a.denominator, b.denominator);

	a.numerator *= multiple / a.denominator;
	b.numerator *= multiple / b.denominator;

	Rational temp(
		a.numerator + b.numerator,
		multiple
	);
	temp.Reduce();
	*this = temp;

	return *this;
}

Rational Rational::operator-=(const Rational other) {
	Rational a = (*this).Reduce();
	Rational b = other.Reduce();

	int multiple = lcm(a.denominator, b.denominator);

	a.numerator *= multiple / a.denominator;
	b.numerator *= multiple / b.denominator;

	Rational temp(
		a.numerator - b.numerator,
		multiple
	);
	temp.Reduce();
	*this = temp;

	return *this;
}

Rational Rational::operator*=(const Rational other) {
	Rational temp(
		this->numerator * other.numerator,
		this->denominator * other.denominator
	);
	temp.Reduce();
	this->numerator = temp.numerator;
	this->denominator = temp.denominator;
	return *this;
}

Rational Rational::operator/=(const Rational other) {
	Rational temp(
		this->numerator * other.denominator,
		this->denominator * other.numerator
	);
	temp.Reduce();
	this->numerator = temp.numerator;
	this->denominator = temp.denominator;
	return *this;
}

double Rational::ToDouble() {
	return double{ numerator } /
		double{ denominator };
}

bool operator==(const Rational lhs, const Rational rhs) {
	Rational a = lhs.Reduce();
	Rational b = rhs.Reduce();

	if (a.numerator == b.numerator &&
		a.denominator == b.denominator)
		return true;
	else
		return false;
}

Rational Rational::Reduce() const {
	int divisor = ::gcd(this->numerator, this->denominator);
	return Rational{
		this->numerator / divisor,
		this->denominator / divisor
	};
}

Rational operator+(const Rational a, const Rational b) {
	Rational temp(a);
	temp += b;
	return temp;
}

Rational operator-(const Rational a, const Rational b) {
	Rational temp(a);
	temp -= b;
	return temp;
}

Rational operator*(const Rational a, const Rational b) {
	Rational temp(a);
	temp *= b;
	return temp;
}

Rational operator/(const Rational a, const Rational b) {
	Rational temp(a);
	temp /= b;
	return temp;
}

namespace {
	// Calculates the Greatest Common Divisor.
	int gcd(int a, int b) {
		if (a == 0 || b == 0)
			return 0;
		else if (a == b)
			return a;
		else if (a > b)
			return gcd(a - b, b);
		else return gcd(a, b - a);
	}

	// Calculates the Least Common Multiple.
	int lcm(int a, int b) {
		return a * b / gcd(a, b);
	}
}
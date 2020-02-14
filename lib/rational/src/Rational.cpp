#include "Rational.h"



Rational::Rational() {}

Rational::Rational(int numerator, int denominator)
	: numerator(numerator)
	, denominator(denominator)
{}

Rational& Rational::operator+=(const Rational& other) {
	Rational a = (*this).reduce();
	Rational b = other.reduce();

	int multiple = lcm(a.denominator, b.denominator);

	a.numerator *= multiple / a.denominator;
	b.numerator *= multiple / b.denominator;

	Rational rez(
		a.numerator + b.numerator,
		multiple
	);

	rez.reduce();
	this->numerator = rez.numerator;
	this->denominator = rez.denominator;

	return rez;
}

Rational& Rational::operator-=(const Rational& other) {
	Rational a = (*this).reduce();
	Rational b = other.reduce();

	int multiple = lcm(a.denominator, b.denominator);

	a.numerator *= multiple / a.denominator;
	b.numerator *= multiple / b.denominator;

	Rational rez(
		a.numerator - b.numerator,
		multiple
	);
	rez.reduce();
	this->numerator = rez.numerator;
	this->denominator = rez.denominator;
	
	return rez;
}

Rational& Rational::operator*=(const Rational& other) {
	Rational rez(
		this->numerator * other.numerator,
		this->denominator * other.denominator
	);
	rez.reduce();
	this->numerator = rez.numerator;
	this->denominator = rez.denominator;
	
	return rez;
}

Rational& Rational::operator/=(const Rational& other) {
	Rational rez(
		this->numerator * other.denominator,
		this->denominator * other.numerator
	);
	rez.reduce();
	this->numerator = rez.numerator;
	this->denominator = rez.denominator;

	return rez;
}

double Rational::toDouble() {
	return static_cast<double> (numerator) /
		static_cast<double> (denominator);
}

bool operator==(const Rational& left, const Rational& right) {
	Rational a = left.reduce();
	Rational b = right.reduce();

	if (a.numerator == b.numerator &&
		a.denominator == b.denominator)
		return true;
	else
		return false;
}

Rational Rational::reduce() const {
	int divisor = gcd(this->numerator, this->denominator);
	return Rational{
		this->numerator / divisor,
		this->denominator / divisor
	};
}

Rational operator+(const Rational& a, const Rational b) {
	Rational temp(a);
	temp += b;
	return temp;
}

Rational operator-(const Rational& a, const Rational b) {
	Rational temp(a);
	temp -= b;
	return temp;
}

Rational operator*(const Rational& a, const Rational b) {
	Rational temp(a);
	temp *= b;
	return temp;
}

Rational operator/(const Rational& a, const Rational b) {
	Rational temp(a);
	temp /= b;
	return temp;
}

int gcd(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	else if (a == b)
		return a;
	else if (a > b)
		return gcd(a - b, b);
	else return gcd(a, b - a);
}

int lcm(int a, int b) {
	return a * b / gcd(a, b);
}
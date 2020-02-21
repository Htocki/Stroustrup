#include "Rational.h"

#include <iostream>

namespace {
	// Calculates the Greatest Common Divisor.
	std::int64_t Gcd(std::int64_t a, std::int64_t b) {
		if (a == 0 || b == 0)
			return 0;
		else if (a == b)
			return a;
		else if (a > b)
			return Gcd(a - b, b);
		else return Gcd(a, b - a);
	}

	// Calculates the Least Common Multiple.
	std::int64_t Lcm(std::int64_t a, std::int64_t b) {
		return a * b / Gcd(a, b);
	}
}

Rational::Rational(
	std::int64_t numerator, 
	std::int64_t denominator
)
	: numerator_(numerator)
	, denominator_(denominator)
{
	this->Reduce();
}

Rational& Rational::operator+=(const Rational other) {
	Rational a = *this;
	Rational b = other;
	
	const auto multiple = Lcm(denominator_, b.denominator_);
	a.numerator_ *= multiple / a.denominator_;
	b.numerator_ *= multiple / b.denominator_;

	Rational temp(
		a.numerator_ + b.numerator_,
		multiple
	);
	temp.Reduce();
	*this = temp;
	return *this;
}

Rational& Rational::operator-=(const Rational other) {
	Rational a = *this;
	Rational b = other;
	
	const auto multiple = Lcm(a.denominator_, b.denominator_);

	a.numerator_ *= multiple / a.denominator_;
	b.numerator_ *= multiple / b.denominator_;

	Rational temp(
		a.numerator_ - b.numerator_,
		multiple
	);
	temp.Reduce();
	*this = temp;
	return *this;
}

Rational& Rational::operator*=(const Rational other) {
	Rational temp(
		numerator_ * other.numerator_,
		denominator_ * other.denominator_
	);
	temp.Reduce();
	numerator_ = temp.numerator_;
	denominator_ = temp.denominator_;
	return *this;
}

Rational& Rational::operator/=(const Rational other) {
	Rational temp(
		numerator_ * other.denominator_,
		denominator_ * other.numerator_
	);
	temp.Reduce();
	numerator_ = temp.numerator_;
	denominator_ = temp.denominator_;
	return *this;
}

double Rational::ToDouble() {
	return double(numerator_) /
		denominator_;
}

std::ostream& operator<<(std::ostream& os, const Rational other) {
	return other.Print(os);
}

bool operator==(const Rational lhs, const Rational rhs) {
	return 
		rhs.numerator_ == lhs.numerator_ &&
		rhs.denominator_ == lhs.denominator_;
}

bool operator!=(const Rational lhs, const Rational rhs) {
	return !operator==(lhs, rhs);
}

auto Rational::Print(std::ostream& os) const->std::ostream& {
	os << numerator_ << "/" << denominator_;
	return os;
}

void Rational::Reduce() {
	const auto divisor = Gcd(numerator_, denominator_);
	Rational temp = *this;
	temp.numerator_ /= divisor;
	temp.denominator_ /= divisor;
	*this = temp;
}

Rational operator+(const Rational lhs, const Rational rhs) {
	Rational temp(lhs);
	temp += rhs;
	return temp;
}

Rational operator-(const Rational lhs, const Rational rhs) {
	Rational temp(lhs);
	temp -= rhs;
	return temp;
}

Rational operator*(const Rational lhs, const Rational rhs) {
	Rational temp(lhs);
	temp *= rhs;
	return temp;
}

Rational operator/(const Rational lhs, const Rational rhs) {
	Rational temp(lhs);
	temp /= rhs;
	return temp;
}
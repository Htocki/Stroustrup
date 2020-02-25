#include "Money.h"

#include <iostream>
#include <string>

#include "Conversions.h"

Money::Money(double amount, Currency currency)
	: USCAmount_(ConvertToUSC(amount, currency))
	, currency_(currency)
{}

Money& Money::operator+=(const Money other) {
	USCAmount_ += other.USCAmount_;
	return *this;
}

Money& Money::operator-=(const Money other) {
	USCAmount_ -= other.USCAmount_;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Money other) {
	return other.Print(os);
}

std::istream& operator>>(std::istream& is, Money& other) {
	std::string value; 
	is >> value;

	std::string currency = value.substr(0, 3);
	if (!(currency == "USD" || currency == "DKK")) {
		throw Money::IncorrectInput{};
	}

	double amount = { 0.0 };
	try {
		amount = std::stod(value.substr(3, value.size()));
	}
	catch (...) {
		throw Money::IncorrectInput{};
	}

	if (currency == "USD") {
		other = Money{ amount, Currency::USD };
	}
	if (currency == "DKK") {
		other = Money{ amount, Currency::DKK };
	}
	return is;
}

bool operator==(const Money lhs, const Money rhs) {
	return
		lhs.USCAmount_ == rhs.USCAmount_ &&
		lhs.currency_ == rhs.currency_;
}

bool operator!=(const Money lhs, const Money rhs) {
	return !operator==(lhs, rhs);
}

auto Money::Print(std::ostream& os) const -> std::ostream& {
	switch (currency_) {
	case Currency::USD:
		os << "USD" << ConvertFromUSCToUSD(
			USCAmount_);
		break;
	case Currency::DKK:
		os << "DKK" << ConvertFromUSCToDKK(
			USCAmount_);
		break;
	}
	return os;
}

Money operator+(const Money lhs, const Money rhs) {
	Money temp(lhs);
	temp += rhs;
	return temp;
}

Money operator-(const Money lhs, const Money rhs) {
	Money temp(rhs);
	temp -= rhs;
	return temp;
}
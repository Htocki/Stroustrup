#include "Money.h"

#include <iostream>

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
	std::cout << "Input currency (USD, DKK): ";
	std::string currency; 
	std::cin >> currency;
	if (!(currency == "USD" || currency == "DKK")) {
		throw Money::IncorrectInput{};
	}
	
	std::cout << "Input amount: ";
	double amount; 
	if (!(std::cin >> amount)) {
		throw Money::IncorrectInput{};
	}

	if (currency == "USD") {
		other.currency_ = Currency::USD;
		other.USCAmount_ = ConvertToUSC(
			amount,
			other.currency_
		);
	}
	if (currency == "DKK") {
		other.currency_ = Currency::DKK;
		other.USCAmount_ = ConvertToUSC(
			amount,
			other.currency_
		);
	}
	return is;
}

bool operator==(const Money lhs, const Money rhs) {
	return
		lhs.USCAmount_ == lhs.USCAmount_ &&
		lhs.currency_ == lhs.currency_;
}

bool operator!=(const Money lhs, const Money rhs) {
	return !operator==(lhs, rhs);
}

auto Money::Print(std::ostream& os) const -> std::ostream& {
	switch (currency_) {
	case Currency::USD:
		os << "USD " << ConvertFromUSCToUSD(
			USCAmount_);
		break;
	case Currency::DKK:
		os << "DKK " << ConvertFromUSCToDKK(
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
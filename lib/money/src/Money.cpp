#include "Money.h"

Money::Money(double amount, Currency currency)
	: USCAmount(converter.ConvertToUSC(amount, currency))
	, currency(currency)
{}

Money Money::operator+=(const Money other) {
	this->USCAmount += other.USCAmount;
	return *this;
}

Money Money::operator-=(const Money other) {
	this->USCAmount -= other.USCAmount;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Money other) {
	return other.Print(os);
}

std::istream& operator>>(std::istream& is, Money& other) {
	std::cout << "Input currency (USD, DKK): ";
	std::string currency; 
	std::cin >> currency;
	if (!(currency == "USD" || currency == "DKK"))
		throw Money::IncorrectInput{};
	
	std::cout << "Input amount: ";
	double amount; 
	if (!(std::cin >> amount)) 
		throw Money::IncorrectInput{};

	if (currency == "USD") {
		other.currency = Currency::USD;
		other.USCAmount = other.converter.ConvertToUSC(
			amount,
			other.currency
		);
	}
	if (currency == "DKK") {
		other.currency = Currency::DKK;
		other.USCAmount = other.converter.ConvertToUSC(
			amount,
			other.currency
		);
	}
	return is;
}

bool operator==(const Money lhs, const Money rhs) {
	if (lhs.USCAmount == lhs.USCAmount &&
		lhs.currency == lhs.currency)
		return true;
	else
		return false;
}

bool operator!=(const Money lhs, const Money rhs) {
	return !operator==(lhs, rhs);
}

auto Money::Print(std::ostream& os) const -> std::ostream& {
	switch (currency) {
	case Currency::USD:
		os << "USD " << converter.ConvertFromUSCToUSD(USCAmount);
		break;
	case Currency::DKK:
		os << "DKK " << converter.ConvertFromUSCToDKK(USCAmount);
		break;
	}
	return os;
}

Money operator+(const Money lhs, const Money rhs) {
	auto temp(lhs);
	temp += rhs;
	return temp;
}

Money operator-(const Money lhs, const Money rhs) {
	auto temp(rhs);
	temp -= rhs;
	return temp;
}
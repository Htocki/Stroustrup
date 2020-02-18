#pragma once

#include <iostream>
#include <string>

#include "Converter.h"
#include "Currency.h"

class Money {
public:
	class IncorrectInput{};

	Money() = default;
	Money(double dollars, Currency currency);

	Money operator+=(const Money other);
	Money operator-=(const Money other);

	friend std::ostream& operator<<(
		std::ostream& os, 
		const Money other
	);

	friend std::istream& operator>>(
		std::istream& is,
		Money& other
		);

	friend bool operator==(const Money lhs, const Money rhs);
	friend bool operator!=(const Money lhs, const Money rhs);

private:
	auto Print(std::ostream& os) const -> std::ostream&;

	Converter converter;
	Currency currency = { Currency::USD };
	long USCAmount = { 0 };
};

Money operator+(const Money lhs, const Money rhs);
Money operator-(const Money lhs, const Money rhs);
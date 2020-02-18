#pragma once

#include <cmath>

#include "Currency.h"

class Converter {
	static struct Coefficient {
		const double USD_USC = { 100 };
		const double USC_USD = { 1 / USD_USC };
		const double USD_DKK = { 1.5 };
		const double DKK_USD = { 1 / USD_DKK };
		const double DKK_USC = { DKK_USD * USD_USC };
		const double USC_DKK = { USC_USD * USD_DKK };
	};

public:
	Converter() = default;
	long ConvertToUSC(double amount, Currency currency) const;
	double ConvertFromUSCToUSD(long amount) const;
	double ConvertFromUSCToDKK(long amount) const;

private:
	Coefficient coefficient;
};
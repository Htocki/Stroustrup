#include <cmath>

#include "Conversions.h"

namespace {
	struct Coefficient {
		static constexpr double USD_USC = { 100 };
		static constexpr double USC_USD = { 1 / USD_USC };
		static constexpr double USD_DKK = { 1.5 };
		static constexpr double DKK_USD = { 1 / USD_DKK };
		static constexpr double DKK_USC = { DKK_USD * USD_USC };
		static constexpr double USC_DKK = { USC_USD * USD_DKK };
	} coef;
}
long ConvertToUSC(
	double amount, Currency currency)
{
	switch (currency) {
	case Currency::USD:
		return std::lround(amount * coef.USD_USC);
		break;
	case Currency::DKK:
		return std::lround(amount * coef.DKK_USC);
		break;
	default:
		return 0;
	}
}

double ConvertFromUSCToUSD(long amount) {
	return amount * coef.USC_USD;
}

double ConvertFromUSCToDKK(long amount) {
	return amount * coef.USC_DKK;
}
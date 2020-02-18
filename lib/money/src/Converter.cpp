#include "Converter.h"

long Converter::ConvertToUSC(
	double amount, Currency currency
) const {
	long USCAmount = { 0 };
	switch (currency) {
	case Currency::USD:
		USCAmount = static_cast<long>(
			std::round(amount * coefficient.USD_USC)
			);
		break;
	case Currency::DKK:
		USCAmount = static_cast<long>(
			std::round(amount * coefficient.DKK_USC)
			);
		break;
	}

	return USCAmount;
}

double Converter::ConvertFromUSCToUSD(long amount) const {
	return static_cast<double>(amount)*
		coefficient.USC_USD;
}

double Converter::ConvertFromUSCToDKK(long amount) const {
	return static_cast<double>(amount)*
		coefficient.USC_DKK;
}
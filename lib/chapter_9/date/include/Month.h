#pragma once
#include <iostream>



enum class Month {
	January = 1,
	February,
	March,
	April,
	May,
	June,
	July,
	August,
	September,
	October,
	November,
	December
};



namespace Chrono
{
	class Month {
		static constexpr int min = 1;
		static constexpr int max = 12;

	public:
		class Invalid {};

		Month(int);
		Month(::Month);

		int getNumber() const { return number; }

		Month& operator++();
		
		friend std::ostream& operator<<(std::ostream&, const Month&);
		friend std::istream& operator>>(std::istream&, Month&);

	private:
		bool is_valid();

		int number;
	};

	bool operator==(const Month&, const Month&);
	bool operator!=(const Month&, const Month&);
}
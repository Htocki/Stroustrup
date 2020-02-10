#pragma once



class Rational {
public:
	Rational();
	Rational(int numerator, int denominator);

	Rational operator+(const Rational& other);
	Rational operator-(const Rational& other);
	Rational operator*(const Rational& other);
	Rational operator/(const Rational& other);

	double toDouble();

	friend bool operator==(const Rational& left, const Rational& right);

private:
	Rational reduce() const;

	int numerator = 1;
	int denominator = 1;
};



// Calculates the Greatest Common Divisor.
int gcd(int a, int b);
// Calculates the Least Common Multiple.
int lcm(int a, int b);



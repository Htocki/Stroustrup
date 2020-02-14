#pragma once



class Rational {
public:
    Rational();
    explicit Rational(int numerator, int denominator);

    Rational& operator+=(const Rational& other);
    Rational& operator-=(const Rational& other);
    Rational& operator*=(const Rational& other);
    Rational& operator/=(const Rational& other);

    double toDouble();

    friend bool operator==(const Rational& lhs, const Rational& rhs);

private:
    Rational reduce() const;

    int numerator = 1;
    int denominator = 1;
};

Rational operator+(const Rational& lhs, const Rational rhs);
Rational operator-(const Rational& lhs, const Rational rhs);
Rational operator*(const Rational& lhs, const Rational rhs);
Rational operator/(const Rational& lhs, const Rational rhs);

// Calculates the Greatest Common Divisor.
int gcd(int lhs, int rhs);
// Calculates the Least Common Multiple.
int lcm(int lhs, int rhs);

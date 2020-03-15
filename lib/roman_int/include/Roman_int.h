#pragma once
#include <cstdint>
#include <iosfwd>
#include <string>

class Roman_int {
public:
    class IncorrectInput{};

    Roman_int() = default;
    explicit Roman_int(const std::string& roman_integer);

    auto AsInt() const ->std::int64_t { return integer_; };

    Roman_int& operator+=(const Roman_int other);
    Roman_int& operator-=(const Roman_int other);
    Roman_int& operator*=(const Roman_int other);
    Roman_int& operator/=(const Roman_int other);

    friend std::istream& operator>>(
        std::istream& is,
        Roman_int& other
    );

    friend std::ostream& operator<<(
        std::ostream& os,
        const Roman_int other
    );

    friend bool operator==(const Roman_int lhs, const Roman_int rhs);
    friend bool operator!=(const Roman_int lhs, const Roman_int rhs);

private:
    auto Print(std::ostream& os) const->std::ostream&;

    std::int64_t integer_ = { 1 };
};

Roman_int operator+(const Roman_int lhs, const Roman_int rhs);
Roman_int operator-(const Roman_int lhs, const Roman_int rhs);
Roman_int operator*(const Roman_int lhs, const Roman_int rhs);
Roman_int operator/(const Roman_int lhs, const Roman_int rhs);
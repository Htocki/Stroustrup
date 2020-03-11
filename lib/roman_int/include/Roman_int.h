#pragma once
#include <cstdint>
#include <iosfwd>
#include <string>

class Roman_int {
public:
    Roman_int() = default;
    explicit Roman_int(const std::string& roman_value);

    auto AsInt() const ->std::int64_t { return value_; };

    Roman_int& operator+=(const Roman_int other);
    Roman_int& operator-=(const Roman_int other);
    Roman_int& operator*=(const Roman_int other);
    Roman_int& operator/=(const Roman_int other);

    friend std::ostream& operator<<(
        std::ostream& os,
        const Roman_int other
    );

    friend bool operator==(const Roman_int lhs, const Roman_int rhs);
    friend bool operator!=(const Roman_int lhs, const Roman_int rhs);

private:
    auto Print(std::ostream& os) const->std::ostream&;
    auto ToInt(std::string roman_value)->std::int64_t;
    auto ToRoman(std::int64_t value)->std::string;

    std::int64_t value_ = { 0 };
};

Roman_int operator+(const Roman_int lhs, const Roman_int rhs);
Roman_int operator-(const Roman_int lhs, const Roman_int rhs);
Roman_int operator*(const Roman_int lhs, const Roman_int rhs);
Roman_int operator/(const Roman_int lhs, const Roman_int rhs);
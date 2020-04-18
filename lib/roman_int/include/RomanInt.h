#pragma once
#include <cstdint>
#include <iosfwd>
#include <string>

class RomanInt {
 public:
  RomanInt() = default;
  explicit RomanInt(std::string roman);

  std::int64_t AsInt() const { return integer_; }

  RomanInt& operator+=(const RomanInt other);
  RomanInt& operator-=(const RomanInt other);
  RomanInt& operator*=(const RomanInt other);
  RomanInt& operator/=(const RomanInt other);

  friend std::istream& operator>>(std::istream& is, RomanInt& other);
  friend std::ostream& operator<<(std::ostream& os, const RomanInt other);

  friend bool operator==(const RomanInt lhs, const RomanInt rhs);
  friend bool operator!=(const RomanInt lhs, const RomanInt rhs);

 private:
  std::ostream& Print(std::ostream& os) const;

  std::int64_t integer_ { 1 };
};

RomanInt operator+(const RomanInt lhs, const RomanInt rhs);
RomanInt operator-(const RomanInt lhs, const RomanInt rhs);
RomanInt operator*(const RomanInt lhs, const RomanInt rhs);
RomanInt operator/(const RomanInt lhs, const RomanInt rhs);

#include "RomanInt.h"

#include <exception>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string_view>
#include <vector>
#include <utility>

namespace {
// Equivalent roman numbers (hard form, simple form)
const std::vector<std::pair<std::string_view, std::string_view>>
  equivalents {
  { "IV", "IIII", },
  { "IX", "VIIII", },
  { "XL", "XXXX", },
  { "XC", "LXXXX", },
  { "CD", "CCCC", },
  { "CM", "DCCCC", }
};

bool IsRomanInteger(const std::string_view roman) {
  // Checks whether all characters of a given string are part
  // of a Roman numeric set.
  const std::string_view roman_numerals_set { "IVXLCDM" };

  for (const auto c : roman) {
    bool key = { false };
    for (const auto n : roman_numerals_set) {
      if (c == n) {
        key = true;
        break;
      }
    }

    if (key == false) {
      return false;
    }
  }

  // Checks the order of the digits in the number.
  const std::vector<std::pair<std::string_view, std::string_view>> pairs {
    { "CM", " 900 " },
    { "CD", " 400 " },
    { "XC", " 90 " },
    { "XL", " 40 " },
    { "IX", " 9 " },
    { "IV", " 4 " },
    { "M",  " 1000 " },
    { "D",  " 500 " },
    { "C",  " 100 " },
    { "L",  " 50 " },
    { "X",  " 10 " },
    { "V",  " 5 " },
    { "I",  " 1 " }
  };

  // Converting a string containing Roman numerals to a string
  // containing the corresponding Arabic numbers.
  // Numbers are separated by spaces.
  std::string formatted_string { roman.begin(), roman.end() };

  for (const auto& pair : pairs) {
    auto position = formatted_string.find(pair.first);
    while (position != std::string::npos) {
      formatted_string.erase(position, pair.first.length());
      formatted_string.insert(position, pair.second);
      position = formatted_string.find(pair.first);
    }
  }

  // Filling a vector with numbers from a string.
  std::stringstream ss;
  ss << formatted_string;
  std::vector<std::int64_t> numbers;
  for (std::int64_t number; ss >> number;) {
    numbers.push_back(number);
  }

  // Checking the adjacent numbers of a vector for whether
  // the left one is larger than the right one.
  for (decltype(numbers.size()) i { 1 }; i < numbers.size(); ++i) {
    if (numbers.at(i-1) < numbers.at(i)) {
      return false;
    }
  }

  // If all checks are passed, returns true.
  return true;
}

std::int64_t ToIntegerNumeral(const char roman_numeral) {
  const std::vector<std::pair<char, std::int64_t>> values {
    { 'M',  1000 },
    { 'D',  500 },
    { 'C',  100 },
    { 'L',  50 },
    { 'X',  10 },
    { 'V',  5 },
    { 'I',  1 }
  };

  for (const auto& value : values) {
    if (roman_numeral == value.first) {
      return value.second;
    }
  }

  throw std::logic_error {
    "The invariant is not respected in the class."
  };
}

// Removes the subtraction rule.
std::string ToSimpleForm(std::string complex_form) {
  for (const auto& equivalent : equivalents) {
    auto position = complex_form.find(equivalent.first);
    if (position != std::string::npos) {
      complex_form.erase(position, equivalent.first.length());
      complex_form.insert(position, equivalent.second);
    }
  }
  return complex_form;
}

// Adds the subtraction rule.
std::string ToComplexForm(std::string simple_form) {
  for (const auto& equivalent : equivalents) {
    auto position = simple_form.find(equivalent.second);
    if (position != std::string::npos) {
      simple_form.erase(position, equivalent.second.length());
      simple_form.insert(position, equivalent.first);
    }
  }
  return simple_form;
}

std::int64_t ToInteger(std::string roman) {
  auto simple_form = ToSimpleForm(std::move(roman));
  std::vector<std::int64_t> integers(simple_form.size());
  for (decltype(integers.size()) i{ 0 }; i < integers.size(); ++i) {
    integers.at(i) = ToIntegerNumeral(simple_form.at(i));
  }
  return std::accumulate(integers.begin(), integers.end(), 0);
}

std::string ToRoman(std::int64_t integer) {
  const std::vector<std::pair<std::string_view, std::int64_t>> values {
    { "M",  1000 },
    { "CM", 900 },
    { "D",  500 },
    { "CD", 400 },
    { "C",  100 },
    { "XC", 90 },
    { "L",  50 },
    { "XL", 40 },
    { "X",  10 },
    { "IX", 9 },
    { "V",  5 },
    { "I",  1 }
  };

  std::string roman;
  for (const auto value : values) {
    while (integer / value.second) {
      integer -= value.second;
      roman += value.first;
    }
  }
  return ToComplexForm(std::move(roman));
}
}  // namespace

RomanInt::RomanInt(std::string roman)
    : integer_(ToInteger(std::move(roman))) {
  if (!IsRomanInteger(roman)) {
    throw std::invalid_argument {
      "The indicated value is not a roman number."
    };
  }
}

RomanInt& RomanInt::operator+=(const RomanInt other) {
  integer_ += other.integer_;
  return *this;
}

RomanInt& RomanInt::operator-=(const RomanInt other) {
  integer_ -= other.integer_;
  return *this;
}

RomanInt& RomanInt::operator*=(const RomanInt other) {
  integer_ *= other.integer_;
  return *this;
}

RomanInt& RomanInt::operator/=(const RomanInt other) {
  integer_ /= other.integer_;
  return *this;
}

std::istream& operator>>(std::istream& is, RomanInt& other) {
  std::string roman;
  is >> roman;
  if (!IsRomanInteger(roman)) {
    throw std::invalid_argument {
      "The indicated value is not a roman number."
    };
  }
  other.integer_ = ToInteger(roman);
  return is;
}

std::ostream& operator<<(std::ostream& os, const RomanInt other) {
  return other.Print(os);
}

bool operator==(const RomanInt lhs, const RomanInt rhs) {
  return lhs.integer_ == rhs.integer_;
}

bool operator!=(const RomanInt lhs, const RomanInt rhs) {
  return !operator==(lhs, rhs);
}

std::ostream& RomanInt::Print(std::ostream& os) const {
    return os << ToRoman(integer_);
}

RomanInt operator+(const RomanInt lhs, const RomanInt rhs) {
  RomanInt temp(lhs);
  temp += rhs;
  return temp;
}

RomanInt operator-(const RomanInt lhs, const RomanInt rhs) {
  RomanInt temp(lhs);
  temp -= rhs;
  return temp;
}

RomanInt operator*(const RomanInt lhs, const RomanInt rhs) {
  RomanInt temp(lhs);
  temp *= rhs;
  return temp;
}

RomanInt operator/(const RomanInt lhs, const RomanInt rhs) {
  RomanInt temp(lhs);
  temp /= rhs;
  return temp;
}

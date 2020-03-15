#include "Roman_int.h"

#include <iostream>
#include <sstream>
#include <vector>

namespace {
    struct Value {
        std::string roman_integer;
        std::int64_t integer;
    };

    const std::vector<Value> values = {        
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

    struct Pair {
        std::string roman_integer;
        std::string equivalent;
    };

    std::vector<Pair> pairs = {
        { "IV", "IIII", },
        { "IX", "VIIII", },
        { "XL", "XXXX", },
        { "XC", "LXXXX", },
        { "CD", "CCCC", },
        { "CM", "DCCCC", }
    };

    bool IsRomanInteger(const std::string& roman_integer) {
       // Checks whether all characters of a given string are part 
       // of a Roman numeric set.
       const std::string roman_numerals_set = { "IVXLCDM" };

       for (const auto c : roman_integer) {
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
        auto roman_copy = roman_integer;

        struct Pair {
            std::string roman_integer;
            std::string integer;
        };

        std::vector<Pair> pairs = {
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

        for (const auto pair : pairs) {
            auto position = roman_copy.find(pair.roman_integer);
            while (position != std::string::npos) {
                roman_copy.erase(position, pair.roman_integer.length());
                roman_copy.insert(position, pair.integer);
                position = roman_copy.find(pair.roman_integer);
            }
        }

        std::stringstream ss;
        ss << roman_copy;
        std::vector<std::int64_t> numbers;
        std::int64_t number;
        while (ss >> number) {
            numbers.push_back(number);
        } 

        for (std::size_t i = 1; i < numbers.size(); ++i) {
            if (numbers.at(i-1) < numbers.at(i)) {
                return false;
            }
        }

        // If all checks are passed, returns true.
        return true;
    }

    auto GetInteger(const std::string& roman_integer) -> 
    std::int64_t {
        for (const auto value : values) {
            if (roman_integer == value.roman_integer) {
                return value.integer;
            }
        }
        // The next line is added so that the compiler does not cry. 
        // The program should not get here. Never...
        return -1;
    }

    // Removes the subtraction rule.
    auto RemoveSubtractionRule(const std::string& roman_integer)->
    std::string {
        auto new_roman_integer = roman_integer;

        for (const auto pair : pairs) {
            auto position = new_roman_integer.find(pair.roman_integer);
            if (position != std::string::npos) {
                new_roman_integer.erase(position, pair.roman_integer.length());
                new_roman_integer.insert(position, pair.equivalent);
            }
        }

        return new_roman_integer;
    }

    // Adds the subtraction rule.
    auto AddSubtractionRule(const std::string& roman_integer)->
    std::string {
        auto new_roman_integer = roman_integer;

        for (const auto pair : pairs) {
            auto position = new_roman_integer.find(pair.equivalent);
            if (position != std::string::npos) {
                new_roman_integer.erase(position, pair.equivalent.length());
                new_roman_integer.insert(position, pair.roman_integer);
            }
        }

        return new_roman_integer;
    }

    auto ToInteger(const std::string& roman_integer) ->
    std::int64_t {
        std::int64_t integer = { 0 };
        auto new_roman_integer = RemoveSubtractionRule(roman_integer);

        for (const auto roman_numeral : new_roman_integer) {
            integer += GetInteger(std::string{ roman_numeral });
        }

        return integer;
    }

    auto ToRomanInteger(const std::int64_t integer) ->
    std::string {
        auto integer_copy = integer;
        std::string roman_integer;

        for (const auto value : values) {
            while (integer_copy / value.integer) {
                integer_copy -= value.integer;
                roman_integer += value.roman_integer;
            }
        }

        return AddSubtractionRule(roman_integer);
    }
}

Roman_int::Roman_int(const std::string& roman_integer)
    : integer_(ToInteger(roman_integer))
{
    if (!IsRomanInteger(roman_integer)) {
        throw IncorrectInput{};
    };
}

Roman_int& Roman_int::operator+=(const Roman_int other) {
    this->integer_ += other.integer_;
    return *this;
}

Roman_int& Roman_int::operator-=(const Roman_int other) {
    this->integer_ -= other.integer_;
    return *this;
}

Roman_int& Roman_int::operator*=(const Roman_int other) {
    this->integer_ *= other.integer_;
    return *this;
}

Roman_int& Roman_int::operator/=(const Roman_int other) {
    this->integer_ /= other.integer_;
    return *this;
}

std::istream& operator>>(std::istream& is, Roman_int& other) {
    std::string roman_integer;
    is >> roman_integer;
    if(!IsRomanInteger(roman_integer)) {
        throw Roman_int::IncorrectInput{};
    }
    other.integer_ = ToInteger(roman_integer);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Roman_int other) {
    return other.Print(os);
}

bool operator==(const Roman_int lhs, const Roman_int rhs) {
    return lhs.integer_ == rhs.integer_;
}

bool operator!=(const Roman_int lhs, const Roman_int rhs) {
    return !operator==(lhs, rhs);
}

auto Roman_int::Print(std::ostream& os) const -> 
std::ostream& {
    os << ToRomanInteger(integer_);
    return os;
}

Roman_int operator+(const Roman_int lhs, const Roman_int rhs) {
	Roman_int temp(lhs);
	temp += rhs;
	return temp;
}

Roman_int operator-(const Roman_int lhs, const Roman_int rhs) {
	Roman_int temp(lhs);
	temp -= rhs;
	return temp;
}

Roman_int operator*(const Roman_int lhs, const Roman_int rhs) {
	Roman_int temp(lhs);
	temp *= rhs;
	return temp;
}

Roman_int operator/(const Roman_int lhs, const Roman_int rhs) {
	Roman_int temp(lhs);
	temp /= rhs;
	return temp;
}

#include "Roman_int.h"

#include <iostream>

Roman_int::Roman_int(const std::string& roman_value) {

}

Roman_int& Roman_int::operator+=(const Roman_int other) {

}

Roman_int& Roman_int::operator-=(const Roman_int other) {

}

Roman_int& Roman_int::operator*=(const Roman_int other) {

}

Roman_int& Roman_int::operator/=(const Roman_int other) {

}

std::ostream& operator<<(std::ostream& os, const Roman_int other) {

}

bool operator==(const Roman_int lhs, const Roman_int rhs) {

}

bool operator!=(const Roman_int lhs, const Roman_int rhs) {
    return !operator==(lhs, rhs);
}

auto Roman_int::Print(std::ostream& os) const -> 
std::ostream& {

}

auto Roman_int::ToInt(std::string roman_value) ->
std::int64_t {

}

auto Roman_int::ToRoman(std::int64_t value) ->
std::string {

}

Roman_int operator+(const Roman_int lhs, const Roman_int rhs) {

}

Roman_int operator-(const Roman_int lhs, const Roman_int rhs) {

}

Roman_int operator*(const Roman_int lhs, const Roman_int rhs) {

}

Roman_int operator/(const Roman_int lhs, const Roman_int rhs) {

}
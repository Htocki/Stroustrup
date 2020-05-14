#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

std::vector<std::string> Split(const std::string& string) {
  std::stringstream buffer;
  buffer << string;
  std::vector<std::string> substrings;
  std::copy(
    std::istream_iterator<std::string> { buffer },
    std::istream_iterator<std::string> { },
    std::back_inserter(substrings));
  return substrings;
}

void Print(const std::vector<std::string>& vector) {
  std::copy(
    std::begin(vector),
    std::end(vector),
    std::ostream_iterator<std::string> { std::cout, "\n" });
}

int main() {
  const std::string string {
    "The algorithms library defines functions for a variety "
    "of purposes (e.g. searching, sorting, counting, "
    "manipulating) that operate on ranges of elements. Note "
    "that a range is defined as [first, last) where last "
    "refers to the element past the last element to inspect "
    "or modify. "
  };
  Print(Split(string));
  return 0;
}

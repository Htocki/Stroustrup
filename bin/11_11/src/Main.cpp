#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

std::vector<std::string> Split(
  const std::string& string,
  const std::string& whitespaces
) {
  std::string corrected;
  std::transform(
    std::begin(string),
    std::end(string),
    std::back_inserter(corrected),
    [&whitespaces] (unsigned char character) -> unsigned char {
      if (whitespaces.find(character) != std::string::npos) {
        character = ' ';
      }
      return character;
    });
  std::stringstream buffer;
  buffer << corrected;
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
  Print(Split(string, ".,!;?()[]a"));
  return 0;
}

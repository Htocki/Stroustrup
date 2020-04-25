#include "HelpFunctions.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <sstream>

#include "PunctStream.h"

std::vector<std::string> Split(
  const std::string& string,
  const std::string& whitespaces
) {
  std::stringstream buffer;
  buffer << string;
  std::vector<std::string> substrings;
  std::copy(
    std::istream_iterator<std::string> { buffer },
    std::istream_iterator<std::string> { },
    std::back_inserter(substrings));
  return substrings;
}

void Print(const std::vector<std::string> vector) {
  std::copy(
    std::begin(vector),
    std::end(vector),
    std::ostream_iterator<std::string> { std::cout, "\n" });
}

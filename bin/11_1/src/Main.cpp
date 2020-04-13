#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <iterator>
#include <fstream>

int main() {
  try {
    std::ifstream in { "files/In.txt" };
    std::ofstream out { "files/Out.txt" };

    if (!in.is_open()) {
      throw std::invalid_argument {
        "The file \"files/In.txt\" was not found."
      };
    }

    in >> std::noskipws;
    out << std::noskipws;

    std::transform(
      std::istream_iterator<char> (in),
      std::istream_iterator<char> (),
      std::ostream_iterator<char> (out),
      [] (char c) { return std::tolower(c); } );
  }
  catch (const std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

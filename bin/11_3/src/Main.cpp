#include <algorithm>
#include <cctype>
#include <exception>
#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

bool IsVovel(const char c) {
  for (const auto vovel : std::string { "eyuioaEYUIOA" }) {
    if (c == vovel) {
      return true;
    }
  }
  return false;
}

int main() {
  try {
    std::ifstream in { "files/file.txt" };
    if (!in.is_open()) {
      throw std::invalid_argument {
        "The specified file was not found."
      };
    }

    std::string buffer;
    in >> std::noskipws;

    std::copy_if(
      std::istream_iterator<char> (in),
      std::istream_iterator<char> (),
      std::back_inserter(buffer),
      [] (unsigned char c) -> bool {
        return !IsVovel(c);
      });

    std::ofstream out { "files/file.txt" };
    if (!out.is_open()) {
      throw std::invalid_argument {
        "The specified file was not found."
      };
    }

    out << std::noskipws;
    out << buffer;
  }
  catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

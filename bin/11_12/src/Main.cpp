#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  try {
    std::string buffer;

    // The reading.
    {
      std::ifstream file { "files/File.txt" };
      if (!file.is_open()) {
        throw std::invalid_argument {
          "The file \"files/File.txt\" was not found."
        };
      }
      file >> std::noskipws;
      std::copy(
        std::istream_iterator<char> { file },
        std::istream_iterator<char> { },
        std::back_inserter(buffer));
    }

    // The writing in reverse order.
    {
      std::ofstream file { "files/File.txt" };
      file << std::noskipws;
      std::copy(
        std::rbegin(buffer),
        std::rend(buffer),
        std::ostream_iterator<char> { file });
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

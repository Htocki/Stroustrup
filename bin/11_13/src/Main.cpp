#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
  try {
    std::vector<std::string> buffer;

    // The reading.
    {
      std::ifstream file { "files/File.txt" };
      if (!file.is_open()) {
        throw std::invalid_argument {
          "The file \"files/File.txt\" was not found."
        };
      }
      std::copy(
        std::istream_iterator<std::string> { file },
        std::istream_iterator<std::string> { },
        std::back_inserter(buffer));
    }

    // The writing in reverse order.
    {
      std::ofstream file { "files/File.txt" };
      std::copy(
        std::rbegin(buffer),
        std::rend(buffer),
        std::ostream_iterator<std::string> { file, " " });
    }
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

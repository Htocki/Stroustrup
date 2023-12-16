#include <algorithm>
#include <cctype>
#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>

int main() {
  try {
    std::ifstream file("files/File.txt");
    if (!file.is_open()) {
      throw std::runtime_error {"Error opening file."};
    } else {
      std::stringstream buffer;
      for (char c; (c = file.get()) && file.good();) {
        if (std::isdigit(c) ||
            std::isspace(c) ||
            c == '-' && isdigit(file.peek())) {
          buffer << c;
        } else {
          throw std::logic_error {
            "Invalid file contents.\n"
            "The file must contain integers separated by spaces."
            };
        }
      }

      std::cout
        << "Summation Result: "
        << std::accumulate(
          std::istream_iterator<std::int64_t> (buffer),
          std::istream_iterator<std::int64_t> (),
          0);
    }
  } catch (std::exception& e) {
    std::cerr << e.what() << std::endl;
  }

  // Pause
  std::cin.get();

  return 0;
}

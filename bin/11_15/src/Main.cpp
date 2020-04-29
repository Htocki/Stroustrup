#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
  try {
    std::ifstream in { "files/In.txt" };
    if (!in.is_open()) {
      throw std::invalid_argument {
        "The file \"files/In.txt\" was not found."
      };
    }

    std::vector<double> values;
    std::copy(
      std::istream_iterator<double> { in },
      std::istream_iterator<double> { },
      std::back_inserter(values));

    std::ofstream out { "files/Out.txt" };
    out << std::scientific << std::setprecision(8);

    // Limit of values per line.
    constexpr  std::size_t limit_per_line { 4 };
    // Current count of values per line.
    std::size_t value_count { 0 };

    for (const auto value : values) {
      if (value_count == limit_per_line) {
        out << '\n';
        value_count = 0;
      }
      out << std::setw(20) << value  << ' ';
      ++value_count;
    }
    out << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}

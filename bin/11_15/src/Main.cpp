// Напишите программу, считывающую из файла числа, разделенные
// пробельными символами, и выводящую в другой файл числа,
// используя научный формат и точность, равную восьми, в
// четырех полях по двадцать символов в строке.

#include <algorithm>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <vector>

int main() {
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
  constexpr std::size_t limit_per_line { 20 };
  // Limit of lines per block.
  constexpr std::size_t limit_per_block { 4 };
  // Current count of values per line.
  std::size_t value_count { 0 };
  // Current count of lines per block.
  std::size_t line_count { 0 };

  for (const auto value : values) {
    if (value_count == limit_per_line) {
      out << '\n';
      value_count = 0;
      ++line_count;
    }
    if (line_count == limit_per_block) {
      out << '\n';
      line_count = 0;
    }
    out << std::setw(15) << value  << " ";
    ++value_count;
  }
  out << std::endl;

  return 0;
}

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

  std::vector<int> values;
  std::copy(
    std::istream_iterator<int> { in },
    std::istream_iterator<int> { },
    std::back_inserter(values));

  std::ofstream out { "files/Out.txt" };
  for (std::size_t i { 0 }; i < values.size(); ++i) {
  }

  return 0;
}

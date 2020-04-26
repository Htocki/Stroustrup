#include <algorithm>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <utility>
#include <vector>

void Print(const std::vector<std::pair<int, int>>& values) {
  for (const auto value : values) {
    std::cout << value.first;
    if (value.second > 1) {
      std::cout << " " << value.second;
    }
    std::cout << std::endl;
  }
}

std::vector<std::pair<int, int>> Repack(const std::vector<int>& values) {
  std::vector<std::pair<int, int>> resorted_values;
  for (const auto value : values) {
    resorted_values.push_back({
      value,
      std::count(values.begin(), values.end(), value)
    });
  }
  resorted_values.erase(
    std::unique(
      resorted_values.begin(),
      resorted_values.end()),
    resorted_values.end());
  return resorted_values;
}

int main() {
  try {
    std::fstream file { "files/File.txt" };
    if (!file.is_open()) {
      throw std::invalid_argument {
        "The file \"files/File.txt\" was not found."
      };
    }
    std::vector<int> values;
    std::copy(
      std::istream_iterator<int> { file },
      std::istream_iterator<int> { },
      std::back_inserter(values));
    std::sort(std::begin(values), std::end(values));
    Print(Repack(values));
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }

  return 0;
}

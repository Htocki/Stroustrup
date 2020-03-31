#include <cstdint>
#include <fstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

int main() {
  std::ifstream file("files/File.txt");
  if (file.is_open()) {
    std::vector<std::int64_t> values;
    for (std::string string; file >> string;) {
      std::stringstream ss;
      ss << string;
      std::int64_t value { 0 };
      if (ss >> value) { values.push_back(value); }
    }
    std::cout
      << "Summation Result: "
      << std::accumulate(values.begin(), values.end(), 0)
      << std::endl;
    } else {
      std::cerr << "Error opening file." << std::endl;
    }
  return 0;
}

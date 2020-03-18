#include <cstdint>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

std::int64_t Sum(std::vector<std::int64_t>& values) {
    std::int64_t sum = { 0 };
    for (const auto value : values) {
        sum += value;
    }
    return sum;
}

int main() {
    std::ifstream file("files/File.txt");
    if (file.is_open()) {
        std::vector<std::int64_t> values;
        for (std::string string; file >> string; ) {
            std::stringstream ss;
            ss << string;
            std::int64_t value;
            if (ss >> value) {
                values.push_back(value);
            }
        }
        std::cout << "Sum: " << Sum(values) << std::endl;
    }
    else {
        std::cerr << "Error opening file." << std::endl;
    }
    return 0;
}
#include "Sum.h"

#include <exception>

std::int64_t sum_numbers_from_file(const std::string& fileName) {
    std::ifstream ifs(fileName);
    if (!ifs.is_open()) {
        throw std::exception{ "Error opening file." };
    }
    else {
        std::int64_t sum = { 0 };
        std::int64_t value = { 0 };
        while (ifs >> value) {
            sum += value;
        }
        return sum;
    }
}
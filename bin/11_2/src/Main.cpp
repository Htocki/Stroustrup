#include <cstdint>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

int main() {
  try {
    std::cout << "Input a file name: ";
    std::string fileName;
    std::getline(std::cin, fileName);

    std::ifstream file { fileName };
    if (file.is_open()) {
      std::string word;
      std::cout << "Input word: ";
      std::getline(std::cin, word);

      std::string string;
      bool strings_found { false };
      for (std::int64_t index { 1 }; std::getline(file, string); ++index) {
        if (string.find(word) != std::string::npos) {
          std::cout << " [" << index << "] \t"
            << "\"" << string << "\"" << std::endl;
          strings_found = true;
        }
      }
      if (!strings_found) {
        std::cout << "No strings containing the specified"
          " word were found in the file." << std::endl;
      }
    } else {
      throw std::invalid_argument {
        "The specified file was not found."
      };
    }
  }
  catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
}

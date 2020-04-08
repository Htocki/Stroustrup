#include <cstdint>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

bool IsSeparator(const char symbol) {
  const std::string_view separators { " .,!?;:'\"[](){}<>/|\\" };
  return separators.find(symbol) != std::string_view::npos;
}

// A word is a set of characters separated from the
// rest by a set of separator characters.
bool IsWordFound(const std::string_view word, const std::string_view line) {
  auto begin = line.find(word);
  if (begin == std::string_view::npos) {
    return false;
  } else {
    auto end = begin + word.size() - 1;
    // The case when a word occupies the entire line.
    if (begin == 0 && end == line.size()) { return true; }

    return IsSeparator(line.at(begin - 1))
      && IsSeparator(line.at(end + 1));
  }
}

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

      std::string line;
      bool lines_with_word_is_found { false };
      for (std::int64_t index { 1 }; std::getline(file, line); ++index) {
        if (IsWordFound(word, line)) {
          std::cout << " [" << index << "] \t"
            << "\"" << line << "\"" << std::endl;
          lines_with_word_is_found = true;
        }
      }
      if (!lines_with_word_is_found) {
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

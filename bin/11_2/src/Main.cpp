#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <string>
#include <string_view>

bool IsSeparator(const char symbol) {
  const std::string_view separators { " .,!?;:'\"[](){}<>/|\\" };
  return separators.find(symbol) != std::string_view::npos;
}

// A word is a set of characters separated from the
// rest by a set of separator characters.
bool IsWordFound(const std::string& word, const std::string& line) {
  const std::string outlinedLine { ' ' + line + ' ' };
  auto begin = outlinedLine.find(word);
  if (begin == std::string_view::npos) { return false; }
  auto end = begin + word.size() - 1;
  std::cout << word << "[" << outlinedLine << "]" << std::endl;
  return IsSeparator(outlinedLine.at(begin - 1))
    && IsSeparator(outlinedLine.at(end + 1));
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

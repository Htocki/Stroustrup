#include <algorithm>
#include <cctype>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <utility>
#include <vector>

bool IsPunct(const unsigned char c) {
  return c == '.' || c == ';' || c == ',' ||
    c == '?' || c == '\'';
}

int main() {
  try {
    std::ifstream in { "files/In.txt" };
    if (!in.is_open()) {
      throw std::invalid_argument {
        "The file \"files/File.txt\" was not found."
      };
    }

    in >> std::noskipws;
    std::string buffer;
    std::copy(
      std::istream_iterator<char> (in),
      std::istream_iterator<char> (),
      std::back_inserter(buffer));

    // Convert all characters to lowercase.
    std::transform(
      std::begin(buffer),
      std::end(buffer),
      std::begin(buffer),
      [] (unsigned char c) -> unsigned char {
        return std::tolower(c);
      });

    // Replace abbreviations with the full form.
    const std::vector<std::pair<std::string, std::string>> forms {
      { "don't", "do not" },
      { "can't", "cannot" },
      { "couldn't", "could not" },
      { "mustn't", "must not" },
      { "needn't", "need not" },
      { "won't", "will not" },
      { "wouldn't", "would not" },
      { "shan't", "shall not" },
      { "shouldn't", "should not" },
      { "oughtn't", "ought not" },
      { "hadn't", "had not" },
    };
    for (const auto& [contracted_form, long_form] : forms) {
      auto position { buffer.find(contracted_form) };
      while (position != std::string::npos) {
        buffer.replace(position, contracted_form.size(), long_form);
        position = buffer.find(contracted_form, position);
      }
    }

    // Saving strings enclosed in double quotes and their
    // starting positions.
    std::vector<std::pair<std::size_t, std::string>> substrings;
    {
      bool is_reading { false };
      bool is_insertion { false };
      std::size_t position { 0 };
      std::string substring;

      for (std::size_t i { 0 }; i < buffer.size(); ++i) {
        if (buffer.at(i) == '\"') {
          if (is_reading) {
            is_reading = false;
            is_insertion = true;
          } else {
            is_reading = true;
            position = i;
          }
        }

        if (is_reading) {
          substring += buffer.at(i);
        }

        if (is_insertion) {
          substrings.push_back({ position, substring });
          is_insertion = false;
          substring.clear();
        }
      }
    }

    // Replace punctuation with spaces.
    std::transform(
      buffer.begin(),
      buffer.end(),
      buffer.begin(),
      [] (unsigned char c) -> unsigned char {
        if (IsPunct(c)) { c = ' '; }
        return c;
      });

    // Returns saved substrings to the modified string.
    for (const auto& [position, substring] : substrings) {
      buffer.replace(position, substring.size(), substring);
    }

    std::ofstream out { "files/Out.txt" };
    out << std::noskipws << buffer;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

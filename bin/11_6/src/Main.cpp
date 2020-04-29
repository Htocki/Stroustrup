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
  return c == '.' || c == ';' || c == ',' || c == '?' ||
    c == '-' || c == '\'';
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

    // Saving strings enclosed in double quotes and their
    // starting positions.
    std::vector<std::pair<std::size_t, std::string>> pairs;
    {
      bool isReading { false };
      bool isInsertion { false };
      std::size_t position { 0 };
      std::string substring;

      for (std::size_t i { 0 }; i < buffer.size(); ++i) {
        if (buffer.at(i) == '\"') {
          if (isReading) {
            isReading = false;
            isInsertion = true;
          } else {
            isReading = true;
            position = i;
          }
        }

        if (isReading) {
          substring += buffer.at(i);
        }

        if (isInsertion) {
          pairs.push_back({ position, substring });
          isInsertion = false;
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

    // Insert previously saved rows at their positions.
    for (const auto& pair : pairs) {
      for (std::size_t i { 0 }; i < pair.second.size(); ++i) {
         buffer.at(pair.first + i) = pair.second.at(i);
      }
    }

    std::ofstream out { "files/Out.txt" };
    out << std::noskipws << buffer;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

#include <cctype>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

bool IsVovel(const char c) {
  for (const auto vovel : std::string { "eyuioaEYUIOA" }) {
    if (c == vovel) {
      return true;
    }
  }
  return false;
}

int main() {
  try {
    std::stringstream buffer;

    std::ifstream in { "files/file.txt" };
    if (in.is_open()) {
      for (char c { ' ' }; in.get(c);) {
        if (!IsVovel(c)) {
            buffer.put(c);
        }
      }
    } else {
      throw std::invalid_argument {
        "The specified file was not found."
      };
    }

    std::ofstream out { "files/file.txt" };
    if (out.is_open()) {
      for (char c { ' ' }; buffer.get(c);) {
        out.put(c);
      }
    } else {
      throw std::invalid_argument {
        "The specified file was not found."
      };
    }
  }
  catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }

  return 0;
}

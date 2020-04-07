#include <cctype>
#include <exception>
#include <iostream>
#include <fstream>

int main() {
  try {
    std::ifstream inputFile { "files/Input.txt" };
    std::ofstream outputFile { "files/Out.txt" };
    if (inputFile.is_open() && outputFile.is_open()) {
      for (char c { ' ' }; inputFile.get(c);) {
        outputFile.put(std::tolower(c));
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

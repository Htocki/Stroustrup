#include <exception>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  try {
    std::cout << "Input a file name: ";
    std::string fileName;
    std::getline(std::cin, fileName);

    std::ifstream file { fileName };
    if (file.is_open()) {
      //
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

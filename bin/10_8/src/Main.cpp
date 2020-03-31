#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {  // The program by the condition accepts 2 files.
      throw std::invalid_argument {
        "The specified number of files is invalid."
      };
    }

    std::vector<std::string> file_names;
    for (std::size_t i{ 1 }; i < argc; ++i) {
      file_names.push_back(argv[i]);
    }

    std::ifstream file_one { file_names.at(0) };
    std::ifstream file_two { file_names.at(1) };
    std::ofstream new_file {"NewFile.txt", std::ios_base::ate};

    if (file_one.is_open() && file_two.is_open() && new_file.is_open()) {
      for (char c {' '}; file_one;) {
        file_one.get(c);
        new_file.put(c);
      }

      for (char c {' '}; file_two;) {
        file_two.get(c);
        new_file.put(c);
      }
    } else {
      std::cerr << "An error occurred while opening files." << std::endl;
    }
  } catch (std::exception& e) {
      std::cerr << e.what() << std::endl;
  }

  std::cin.get();  // Pause.
}



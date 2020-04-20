// Разделите программу ввода-вывода из раздела 11.3.2 на две:
// одна программа пусть конвертирует обычный текстовый файл
// в бинарный, а другая считывает бинарный файл и преобразует
// его в текстовый. Протестируйте эти программы, сравнивая
// текстовые файлы до и после преобразования в двоичный файл
// и обратно.

#include <algorithm>
#include <bitset>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

bool IsToBinary(const std::string_view& flag) {
  return flag == "-TB" || flag == "--to-binary";
}

bool IsToTextual(const std::string_view& flag) {
  return flag == "-TT" || flag == "--to-textual";
}

bool IsFlag(const std::string_view& flag) {
  return IsToBinary(flag) || IsToTextual(flag);
}

int main(int argc, char* argv[]) {
  try {
    if (argc != 3) {
      throw std::invalid_argument {
        "Invalid number of parameters specified."
      };
    }

    const std::string_view flag { argv[1] };
    if (!IsFlag(flag)) {
      throw std::invalid_argument {
        "The specified character set is not a flag."
      };
    }

    if (IsToBinary(flag)) {
      std::ifstream textual { argv[2] };
      if (!textual.is_open()) {
        throw std::invalid_argument {
          "The specified file was not found."
        };
      }
      std::ofstream binary { "file.bin", std::ios::binary };
      textual >> std::noskipws;
      binary << std::noskipws;
      std::copy(
        std::istream_iterator<char> { textual },
        std::istream_iterator<char> { },
        std::ostream_iterator<std::bitset<sizeof(char)>> { binary });
    }

    if (IsToTextual(flag)) {
      std::ifstream binary { argv[2], std::ios::binary };
      if (!binary.is_open()) {
        throw std::invalid_argument {
          "The specified file was not found."
        };
      }
      std::ofstream textual { "file.txt" };
      binary >> std::noskipws;
      textual << std::noskipws;
      std::copy(
        std::istream_iterator<std::bitset<sizeof(char)>> { binary },
        std::istream_iterator<std::bitset<sizeof(char)>> { },
        std::ostream_iterator<char> { textual });
    }
  }
  catch (const std::invalid_argument& excaption) {
    std::cerr << excaption.what() << std::endl;
  }
  catch (const std::exception& excaption) {
    std::cerr << excaption.what() << std::endl;
  }
  catch (...) {
    std::cout << "Unknown exception." << std::endl;
  }
  return 0;
}

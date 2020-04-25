#include <algorithm>
#include <bitset>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <string_view>
#include <vector>

template<class T>
char* AsBytes(T& i) {
  void* addr = &i;
  return static_cast<char*>(addr);
}

bool IsToBinary(const std::string_view& flag) {
  return flag == "-tB" || flag == "--to-binary";
}

bool IsToTextual(const std::string_view& flag) {
  return flag == "-tT" || flag == "--to-textual";
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
      std::vector<int> values;
      std::copy(
        std::istream_iterator<int> { textual },
        std::istream_iterator<int> { },
        std::back_inserter(values));

      std::ofstream binary { "file.bin", std::ios::binary };
      for (auto value : values) {
        binary.write(AsBytes(value), sizeof(int));
      }
    }

    if (IsToTextual(flag)) {
      std::ifstream binary { argv[2], std::ios::binary };
      if (!binary.is_open()) {
        throw std::invalid_argument {
          "The specified file was not found."
        };
      }
      std::vector<int> values;
      for (int value { 0 }; binary.read(AsBytes(value), sizeof(int));) {
        values.push_back(value);
      }
      std::ofstream textual { "file.txt" };
      std::copy(
        std::begin(values),
        std::end(values),
        std::ostream_iterator<int> { textual, " " });
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

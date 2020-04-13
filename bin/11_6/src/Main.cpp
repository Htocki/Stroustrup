// Напишите программу, заменяющую знаки пунктуации пробелами.
// Считайте таковыми точку (.), точку с запятой (;), запятую
// (,), вопросительный знак (?), дефис (-), одинарные кавычки
// ('). Не изменяйте символы, находящиеся между парами двойных
// кавычек ("). Например, строка "  - don't use the as-if rule."
// должна принять вид "  don t use the as if rule ".

#include <algorithm>
#include <cctype>
#include <exception>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>

bool IsPunct(const unsigned char c) {
  return c == '.' || c == ';' || c == ',' || c == '?' ||
    c == '-' || c == '\'';
}

int main() {
  try {
    std::ifstream file { "files/File.txt" };
    if (!file.is_open()) {
      throw std::invalid_argument {
        "The file \"files/File.txt\" was not found."
      };
    }

    file >> std::noskipws;
    std::string buffer;
    std::transform(
      std::istream_iterator<char> (file),
      std::istream_iterator<char> (),
      std::back_inserter(buffer),
      [] (unsigned char c) -> unsigned char {
        if (IsPunct(c)) { c = ' '; }
        return c;
      });

    std::cout << std::noskipws << buffer << std::endl;
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}

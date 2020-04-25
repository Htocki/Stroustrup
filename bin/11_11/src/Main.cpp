// Напишите функцию std::vector<std::string> Split(
// const std::string& s, const std::string& w),
// возвращающую вектор подстрок аргумента s, разделенных
// пробельными символами символами, при условии, что в качестве
// пробельного символа могут использоваться как "обычные"
// пробельные символы, так и символы из строки w.

#include <string>

#include "HelpFunctions.h"

int main() {
  const std::string string {
    "The algorithms library defines functions for a variety "
    "of purposes (e.g. searching, sorting, counting, "
    "manipulating) that operate on ranges of elements. Note "
    "that a range is defined as [first, last) where last "
    "refers to the element past the last element to inspect "
    "or modify. "
  };
  Print(Split(string, ".,!;?"));
  return 0;
}

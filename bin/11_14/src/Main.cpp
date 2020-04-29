#include <algorithm>
#include <cctype>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>

int main() {
  try {
    std::ifstream in { "files/In.txt" };
    if (!in.is_open()) {
      throw std::invalid_argument {
        "The file \"files/In.txt\" was not found."
      };
    }

    std::string buffer;
    std::copy(
      std::istream_iterator<char> { in },
      std::istream_iterator<char> { },
      std::back_inserter(buffer));

    int  alpha { 0 }, lower { 0 }, upper { 0 }, digit { 0 },
        xdigit { 0 }, cntrl { 0 }, graph { 0 }, space { 0 },
         blank { 0 }, print { 0 }, punct { 0 };

    for (const auto character : buffer) {
      if (std::isalpha(character)) { ++alpha; }
      if (std::islower(character)) { ++lower; }
      if (std::isupper(character)) { ++upper; }
      if (std::isdigit(character)) { ++digit; }
      if (std::isxdigit(character)) { ++xdigit; }
      if (std::iscntrl(character)) { ++cntrl; }
      if (std::isgraph(character)) { ++graph; }
      if (std::isspace(character)) { ++space; }
      if (std::isblank(character)) { ++blank; }
      if (std::isprint(character)) { ++print; }
      if (std::ispunct(character)) { ++punct; }
    }

    const int width { 10 };
    std::ofstream out { "files/Out.txt" };
    out
      << "Number of characters by category:\n"
      << std::setw(width) << "  Alpha: " << alpha << '\n'
      << std::setw(width) << "  Lower: " << lower << '\n'
      << std::setw(width) << "  Upper: " << upper << '\n'
      << std::setw(width) << "  Digit: " << digit << '\n'
      << std::setw(width) << "  Xdigit: " << xdigit << '\n'
      << std::setw(width) << "  Cntrl: " << cntrl << '\n'
      << std::setw(width) << "  Graph: " << graph << '\n'
      << std::setw(width) << "  Space: " << space << '\n'
      << std::setw(width) << "  Blank: " << blank << '\n'
      << std::setw(width) << "  Print: " << print << '\n'
      << std::setw(width) << "  Punct: " << punct << std::endl;
  } catch (const std::exception& e) {
    std::cerr << e.what() << std::endl;
  } catch (...) {
    std::cerr << "Unknown exception." << std::endl;
  }
  return 0;
}

#include <cctype>
#include <iostream>
#include <string>

bool IsInputContinue() {
  std::cout << "Want to continue input? "
    "(Print [y]es or [n]o): ";
  std::cin.exceptions(std::ios_base::failbit);
  char answer { ' ' };
  std::cin.get(answer);

  if (std::cin.get() != '\n') {
    std::cout << "I consider your answer as negative. "
        "Input stopped ..." << std::endl;
    return false;
  }

  switch (answer) {
    case 'y':
      std::cout << "Input continued..." << std::endl;
      return true;
    case 'n':
      std::cout << "Input stopped..." << std::endl;
      return false;
    default:
      std::cout << "I consider your answer as negative. "
        "Input stopped..." << std::endl;
      return false;
  }
}

int main() {
  try {
    do {
      std::cout << "Input string: ";
      std::string string;
      std::cin.exceptions(std::ios_base::failbit);
      std::getline(std::cin, string);
      std::cout << "Parsing a string into categories:" << std::endl;
      for (const auto character : string) {
        std::string buffer;
        std::cout << "Character \'" << character << "\' is";
        if (std::isalnum(character)) { buffer += " alphanumeric,"; }
        if (std::isalpha(character)) { buffer += " alphabetic,"; }
        if (std::islower(character)) { buffer += " lowercase,"; }
        if (std::isupper(character)) { buffer += " an uppercase character,"; }
        if (std::isdigit(character)) { buffer += " a digit,"; }
        if (std::isxdigit(character)) { buffer += " a hexadecimal character,"; }
        if (std::iscntrl(character)) { buffer += " a control character,"; }
        if (std::isgraph(character)) { buffer += " a graphical character,"; }
        if (std::isspace(character)) { buffer += " a space character,"; }
        if (std::isblank(character)) { buffer += " a blank character,"; }
        if (std::isprint(character)) { buffer += " a printing character,"; }
        if (std::ispunct(character)) { buffer += " a punctuation character,"; }
        // Replacing an extra comma with a dot.
        std::cout << buffer.substr(0, buffer.size() - 1) << '.' << std::endl;
      }
    } while (IsInputContinue());
  } catch (const std::ios_base::failure& e) {
    std::cout
      << "Caught an ios_base::failure.\n"
      << "Explanatory string: " << e.what() << '\n'
      << "Error code: " << e.code() << std::endl;
  }

  return 0;
}

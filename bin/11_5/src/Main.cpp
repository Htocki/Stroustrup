// Напишите программу. считывающую строки и выводящую
// категории каждого символа в соответствии с правилами,
// описанными в разделе 11.6. Помните, что один и тот же символ
// может относиться к разным категориям (например, х - это и
// буквенный, и буквенно-цифровой символ).

#include <cctype>
#include <iostream>
#include <string>

bool IsInputContinue() {
  std::cout << "Want to continue input? "
    "(Print [y]es or [n]o): ";
  std::cin.exceptions(std::ios_base::failbit);
  char answer { ' ' };
  std::cin.get(answer);
  std::cin.get();
  switch (answer) {
    case 'y':
      std::cout << "Input continued..." << std::endl;
      return true;
    case 'n':
      std::cout << "Input stopped..." << std::endl;
      return false;
    default:
      std::cout << "I consider your answer as negative. "
        "Input stopped ..." << std::endl;
      return false;
  }
}

int main() {
  try {
    do {
      std::cout << "Input string: ";
      std::string string;
      std::getline(std::cin, string);
      std::cout << string << std::endl;
    } while (IsInputContinue());
  } catch (const std::ios_base::failure& e) {
    std::cout
      << "Caught an ios_base::failure.\n"
      << "Explanatory string: " << e.what() << '\n'
      << "Error code: " << e.code() << std::endl;
  }

  return 0;
}

#include <cstdint>
#include <iostream>

int main() {
  std::cout.exceptions(std::ios_base::failbit);
  std::cin.exceptions(std::ios_base::failbit);

  try {
    std::int64_t
      oct1 { 0 }, oct2 { 0 }, oct3 { 0 },
      dec1 { 0 }, dec2 { 0 }, dec3 { 0 },
      hex1 { 0 }, hex2 { 0 }, hex3 { 0 };

    std::cout << "Enter the octal numbers:\n" << std::oct;
    std::cout << "  First: ";
    std::cin >> std::oct >> oct1;
    std::cout << "  Second: ";
    std::cin >> std::oct >> oct2;
    std::cout << "  Third: ";
    std::cin >> std::oct >> oct3;
    std::cout << std::endl;

    std::cout << "Enter the demical numbers:\n";
    std::cout << "  First: ";
    std::cin >> std::dec >> dec1;
    std::cout << "  Second: ";
    std::cin >> std::dec >> dec2;
    std::cout << "  Third: ";
    std::cin >> std::dec >> dec3;
    std::cout << std::endl;

    std::cout << "Enter the demical numbers:\n";
    std::cout << "  First: ";
    std::cin >> std::hex >> hex1;
    std::cout << "  Second: ";
    std::cin >> std::hex >> hex2;
    std::cout << "  Third: ";
    std::cin >> std::hex >> hex3;
    std::cout << std::endl;

    std::cout
      << std::oct << oct1
        << " (octal) turns into decimal "
        << std::dec << oct1 << '\n'
      << std::oct << oct2
        << " (octal) turns into decimal "
        << std::dec << oct2 << '\n'
      << std::oct << oct3
        << " (octal) turns into decimal "
        << std::dec << oct3 << '\n'
      << std::endl;

    std::cout << std::dec
      << dec1 << " (decimal) turns into decimal " << dec1 << '\n'
      << dec2 << " (decimal) turns into decimal " << dec2 << '\n'
      << dec3 << " (decimal) turns into decimal " << dec3 << '\n'
      << std::endl;

    std::cout
      << std::hex << hex1
        << " (hexadecimal) turns into decimal "
        << std::dec << hex1 << '\n'
      << std::hex << hex2
        << " (hexadecimal) turns into decimal "
        << std::dec << hex2 << '\n'
      << std::hex << hex3
        << " (hexadecimal) turns into decimal "
        << std::dec << hex3 << '\n'
      << std::endl;
  } catch (const std::ios_base::failure& e) {
    std::cout
      << "Caught an ios_base::failure.\n"
      << "Explanatory string: " << e.what() << '\n'
      << "Error code: " << e.code() << std::endl;
  }

  return 0;
}

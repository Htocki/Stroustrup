#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

struct Reading {
  int hour { 0 };  // [0, 23].
  double temperature { 0 };  // Fahrenheit.
};

std::ostream& operator<< (std::ostream& os, const Reading& r) {
  return os << r.hour << " " << r.temperature << "\n";
}

int GetHour() {
  std::cout << "Input hour [0, 23]: ";
  if (int hour { -1 }; std::cin >> hour) {
    if (hour < 0 || hour > 23) {
      throw std::invalid_argument {
        "The hour you entered is incorrect."
      };
    }
  }
}

constexpr double fahrenheit_temperature_minimun { -459.67 };

double GetTemperature() {
  std::cout << "Input temperature: ";
  if (double temperature { -1000 }; std::cin >> temperature) {
    if (temperature < fahrenheit_temperature_minimun) {
      std::invalid_argument {
        "Incorrect temperature entered."
      };
    }
  }
}

Reading InstanceReading() {
  std::cin.exceptions(std::ios::failbit);
  Reading r;
  try {
    r.hour = GetHour();
    r.temperature = GetTemperature();
  }
  catch (std::invalid_argument& e) {
    std::cerr << e.what() << "\n";
    std::cout <<
      "An error occurred while entering the entry.\n"
      "Want to repeat again? (All entries entered up\n"
      "to this point will not be entered into the file.)\n"
      "Enter [y]es or [n]ot: ";

    if (char decision { ' ' }; std::cin >> decision) {
      switch (decision) {
      case 'y':
        return InstanceReading();
      case 'n':
        throw std::invalid_argument { "Bye Bye." };
      default:
        throw std::invalid_argument { "I take it as not. Bye Bye." };
      }
    }
  }
  return r;
}

constexpr std::uint64_t number_of_readings = { 50 };

int main() {
  try {
    std::vector<Reading> readings;
    readings.resize(number_of_readings);
    std::ofstream file("Raw_temps.txt");

    if (file.is_open()) {
      for (auto& r : readings) { r = InstanceReading(); }
      for (const auto& r : readings) { file << r; }
    } else {
      throw std::invalid_argument{ "Invalid file specified." };
    }
  }
  catch (std::ios_base::failure& e) {
    std::cerr << e.what() << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cin.get();  // Pause.

  return 0;
}

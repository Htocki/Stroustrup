#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

struct Reading {
  int hour { 0 };
  char scale { 'c' };
  double temperature { 0 };
};

static double min_limit { 0 };

char GetScale() {
  std::cin.exceptions(std::ios::failbit);
  std::cout << "Input scale (Fahrenheit[f] or (Celsius[c]): ";
  if (char scale {' '}; std::cin >> scale) {
    switch (scale) {
    case 'f' :
      min_limit = -459.67;
      return scale;
    case 'c':
      min_limit = -273.15;
      return scale;
    default:
      throw std::invalid_argument {
        "The scale is entered incorrectly."
      };
    }
  }
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

double GetTemperature() {
  std::cout << "Input temperature: ";
  if (double temperature { -1000 }; std::cin >> temperature) {
    if (temperature < min_limit) {
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
    r.scale = GetScale();
    r.temperature = GetTemperature();
    r.hour = GetHour();
  }
  catch (std::invalid_argument& e) {
    std::cerr << e.what() << "\n\n";
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

constexpr std::uint64_t number_of_readings { 50 };

int main() {
  try {
    std::vector<Reading> readings;
    readings.resize(number_of_readings);
    std::ofstream file("Raw_temps.txt");

    if (file.is_open()) {
      for (auto& r : readings) {
        r = InstanceReading();
      }

      for (const auto& r : readings) {
        file
          << r.hour << " "
          << r.temperature << " "
          << r.scale << "\n";
      }
    } else {
      throw std::invalid_argument{ "Error opening file." };
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

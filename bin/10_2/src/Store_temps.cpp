#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

constexpr std::uint64_t number_of_readings = { 50 };

struct Reading {
  int hour;  // [0, 23].
  double temperature;  // Fahrenheit.
};

Reading InstanceReading() {
  std::cin.exceptions(std::ios::failbit);
  Reading r;

  std::cout << "Input hour [0, 23]: ";
  if (std::cin >> r.hour) {
    if (r.hour < 0 || r.hour > 23) {
      std::cerr <<
        "Input is incorrect.\n\n"
        "Try again:" << std::endl;
      return InstanceReading();
    }
  }

  std::cout << "Input temperature (Fahrenheit): ";
  if (std::cin >> r.temperature) {
    if (r.temperature < -1000 || r.temperature > 1000) {
      std::cerr <<
        "Input is incorrect.\n\n"
        "Try again:" << std::endl;
      return InstanceReading();
    }
  }

  return r;
}

int main() {
  try {
    std::vector<Reading> temps;
    std::ofstream ofs("Raw_temps.txt");

    if (ofs.is_open()) {
      while (temps.size() != number_of_readings) {
        temps.push_back(InstanceReading());
      }
      for (auto r : temps) {
        ofs << r.hour << " " << r.temperature << "\n";
      }
    } else {
      throw std::invalid_argument{ "Invalid file specified." };
    }
  }
  catch (std::ios_base::failure e) {
    std::cerr << "Critical input error." << std::endl;
  }
  catch (std::exception e) {
    std::cerr << e.what() << std::endl;
  }

  std::cin.get();  // Pause.

  return 0;
}

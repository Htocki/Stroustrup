#include <algorithm>
#include <exception>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>

struct Reading {
  int hour;  // [0, 23].
  double temperature;  // Fahrenheit.
};

double operator+(double temperature, Reading read) {
  return read.temperature + temperature;
}

std::vector<Reading> ReadFromFile(const std::string& fileName) {
  std::vector<Reading> readings;
  std::ifstream ifs(fileName);

  if (ifs.is_open()) {
    Reading r;
    while (!ifs.eof()) {
      ifs >> r.hour >> r.temperature;
        readings.push_back(r);
    }
  } else {
    throw std::invalid_argument{ "Invalid file specified." };
  }
  return readings;
}

void Print(const std::vector<Reading>& readings) {
  for (const auto& r : readings) {
    std::cout << r.hour << " " << r.temperature << "\n";
  }
  std::cout << std::endl;
}

double AverageTemperature(std::vector<Reading> readings) {
  return std::accumulate(readings.begin(), readings.end(), 0) /
    readings.size();
}

double TemperatureMedian(const std::vector<Reading>& readings) {
  std::vector<double> temperatures;
  temperatures.reserve(readings.size());

  for (const auto& r : readings) {
    temperatures.push_back(r.temperature);
  }

  std::sort(temperatures.begin(), temperatures.end());

  if (temperatures.size() % 2 == 0) {
    return (temperatures.at(temperatures.size() / 2) +
      temperatures.at(temperatures.size() / 2 - 1)) / 2;
  } else {
    return temperatures.at(temperatures.size() / 2);
  }
}

int main() {
  try {
    std::vector<Reading> readings = ReadFromFile("files/Raw_temps.txt");
    Print(readings);
    std::cout
      << "Average temperature: "
      << AverageTemperature(readings)
      << "\n"
      << "TemperatureMedian: "
      << TemperatureMedian(readings)
      << std::endl;
  }
  catch (std::invalid_argument& e) {
    std::cerr << e.what() << std::endl;
  }

  std::cin.get();  // Pause.

  return 0;
}

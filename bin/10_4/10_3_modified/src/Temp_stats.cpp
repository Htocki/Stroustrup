#include <algorithm>
#include <exception>
#include <iostream>
#include <fstream>
#include <numeric>
#include <string>
#include <vector>

struct Reading {
  int hour { 0 };
  char scale { 'c' };
  double temperature { 0 };
};

double operator+(double temperature, Reading read) {
  return read.temperature + temperature;
}

double ConvertCelsiusToFahrenheit(double temperature) {
  return (9. / 5) * temperature + 32;
}

std::vector<Reading> ReadFromFile(const std::string& fileName) {
  std::vector<Reading> readings;
  std::ifstream file(fileName);

  if (file.is_open()) {
    for (Reading r; !file.eof();) {
      file >> r.hour >> r.temperature >> r.scale;
      r.temperature = ConvertCelsiusToFahrenheit(r.temperature);
      r.scale = 'f';
      readings.push_back(r);
    }
  } else {
    throw std::invalid_argument{ "Invalid file specified." };
  }
  return readings;
}

void Print(const std::vector<Reading>& readings) {
  for (const auto& r : readings) {
    std::cout
      << r.hour << " "
      << r.temperature << " "
      << r.scale << "\n";
  }
  std::cout << std::endl;
}

double AverageTemperature(const std::vector<Reading> readings) {
  return std::accumulate(readings.begin(), readings.end(), 0) /
    readings.size();
}

double TemperatureMedian(const std::vector<Reading>& readings) {
  std::vector<double> temperatures;

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
    std::cout << "Average temperature: "
      << AverageTemperature(readings)
      << "\n"
      << "TemperatureMedian: "
      << TemperatureMedian(readings)
      << std::endl;
    }
    catch (std::invalid_argument& e) {
      std::cout << e.what() << std::endl;
    }

    std::cin.get();  // Pause.

    return 0;
}

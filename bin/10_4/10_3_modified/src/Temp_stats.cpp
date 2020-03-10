#include <algorithm>
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

struct Reading {
    int hour;
    double temperature;
    char scale;
};

auto ConvertCelsiusToFahrenheit(double temperature) ->
double {
    return (9. / 5) * temperature + 32;
}

auto ReadFromFile(const std::string& fileName) ->
std::vector<Reading> {
    std::vector<Reading> readings;
    std::ifstream ifs(fileName);

    if (ifs.is_open()) {
        Reading r;
        while (!ifs.eof()) {
            ifs >> r.hour >> r.temperature >> r.scale;
            r.temperature = ConvertCelsiusToFahrenheit(r.temperature);
            r.scale = 'f';
            readings.push_back(r);
        }
    }
    else {
        throw std::exception{ "Invalid file specified." };
    }

    return readings;
}

void Print(const std::vector<Reading>& readings) {
    for (const auto& r : readings) {
        std::cout 
            << r.hour << " " 
            << r.temperature << " " 
            << r.scale << std::endl;
    }
    std::cout << std::endl;
}

auto AverageTemperature(const std::vector<Reading>& readings) ->
double {
    double sum{ 0 };
    for (const auto& r : readings) {
        sum += r.temperature;
    }
    return sum / readings.size();
}

auto TemperatureMedian(const std::vector<Reading>& readings) ->
double {
    std::vector<double> temperatures;

    for (const auto& r : readings) {
        temperatures.push_back(r.temperature);
    }

    std::sort(temperatures.begin(), temperatures.end());

    if (temperatures.size() % 2 == 0) {
        return (temperatures.at(temperatures.size() / 2)
            + temperatures.at(temperatures.size() / 2 - 1)) / 2;
    }
    else {
        return temperatures.at(temperatures.size() / 2);
    }
}

int main() {
    try {
        std::vector<Reading>& readings = {
            ReadFromFile("files/Raw_temps.txt")
        };

        Print(readings);

        std::cout << "Average temperature: "
            << AverageTemperature(readings)
            << std::endl;

        std::cout << "TemperatureMedian: "
            << TemperatureMedian(readings)
            << std::endl;

    }
    catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }

    // Pause
    char c; std::cin.get(c);

    return 0;
}
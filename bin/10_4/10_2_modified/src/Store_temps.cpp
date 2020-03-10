#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

constexpr std::uint64_t number_of_readings = { 5 };

struct Reading {
    int hour;
    double temperature;
    char scale;
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

    struct Temperature_limit {
        double min = {0};
    } temperature_limit;

    std::cout << "Input scale (Fahrenheit[f] or (Celsius[c]): ";
    if (std::cin >> r.scale) {
        switch (r.scale) {
        case 'f' :
            temperature_limit.min = -459.67;
            break;
        case 'c':
            temperature_limit.min = -273.15;
            break;
        default: 
            std::cerr <<
                "Input is incorrect.\n\n"
                "Try again:" << std::endl;
            return InstanceReading();
        }
    }

    std::cout << "Input temperature: ";
    if (std::cin >> r.temperature) {
        if (r.temperature < temperature_limit.min) {
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
                ofs 
                    << r.hour 
                    << " " 
                    << r.temperature
                    << " "
                    << r.scale
                    << "\n";
            }
        }
        else {
            throw std::exception{ "Error opening file." };
        }
    }
    catch (std::ios_base::failure e) {
        std::cerr << "Critical input error." << std::endl;
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
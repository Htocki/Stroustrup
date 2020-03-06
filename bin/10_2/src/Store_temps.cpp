#include <cstdint>
#include <exception>
#include <fstream>
#include <iostream>
#include <vector>

constexpr std::uint64_t number_of_readings = { 50 };

struct Reading {
    int hour; // [0, 23].
    double temperature; // Fahrenheit.
};

Reading AddReading() {
    try {
        Reading r;
        std::cout << "Input hour [0, 23]: ";
        if (!(std::cin >> r.hour) || r.hour < 0 || r.hour > 23) {
            throw std::exception{ 
                "Input is incorrect.\n\n"
                "Try again:"
            };
        }

        std::cout << "Input temperature (Fahrenheit): ";
        if (!(std::cin >> r.temperature)) {
            throw std::exception{
                "Input is incorrect.\n\n"
                "Try again:"
            };
        }

        return r;
    }
    catch (std::exception e) {
        if (std::cin.eof()) {
            throw std::exception{ 
                "The program stopped working because "
                "you entered the end of file symbol." 
            };
        }
        else {
            std::cerr << e.what() << std::endl;
            return AddReading();
        }
    }

}

int main() {
    std::vector<Reading> temps;
    try {
        std::ofstream ofs("Raw_temps.txt");
        if (ofs.is_open()) {
            while (temps.size() != number_of_readings) {
                temps.push_back(AddReading());
            }

            for (auto r : temps) {
                ofs << r.hour << " " << r.temperature << "\n";
            }
        }
        else {
            throw std::exception{ "Error opening file." };
        }
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::string> file_names;

    for (std::size_t i{ 1 }; i < argc; ++i) {
        file_names.push_back(argv[i]);
    }

    std::ifstream 
        file_one{ file_names[0] }, 
        file_two{ file_names[1] };

    std::ofstream new_file ("NewFile.txt", std::ios_base::ate);

    if (file_one.is_open() && 
        file_two.is_open() &&
        new_file.is_open()) 
    {
        while (file_one) {
            char c;
            file_one.get(c);
            new_file.put(c);
        }

        while (file_two) {
            char c;
            file_two.get(c);
            new_file.put(c);
        }   
    }
    else {
        std::cerr << "An error occurred while opening files." << std::endl;
    }

    // Pause.
    // char c; std::cin.get(c);
}



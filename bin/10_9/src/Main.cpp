#include <algorithm>
#include <iostream>
#include <fstream>
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
        std::vector<std::string> words;
        std::string word;

        while (file_one >> word) {
            words.push_back(word);
        }

        while (file_two >> word) {
            words.push_back(word);
        }

        std::sort(words.begin(), words.end());

        for (const auto word : words) {
            new_file << word << " ";
        }
    }
    else {
        std::cerr << "An error occurred while opening files." << std::endl;
    }

    // Pause.
    // char c; std::cin.get(c);
}
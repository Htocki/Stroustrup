#include <conio.h>

#include <iostream>
#include <fstream>

#include "Sum.h"

int main() {
    try {
        std::cout
            << "Sum: "
            << sum_numbers_from_file("files/File.txt")
            << std::endl;
    }
    catch (std::exception e) {
        std::cerr << e.what() << std::endl;
    }
    getch();
    return 0;
}
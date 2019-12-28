#include "Name_pairs.h"



int main() {
	Name_pairs pairs;
	pairs.read_names();
	pairs.read_ages();
	pairs.print();
	pairs.sort();
	std::cout << pairs << std::endl;
}
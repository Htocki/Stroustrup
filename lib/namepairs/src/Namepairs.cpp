#include "Namepairs.h"

Namepairs::Namepairs(
	std::initializer_list<std::pair<std::string, int>> list
) {
	for (auto element : list) {
		names.push_back(element.first);
		ages.push_back(element.second);
	}
}

void Namepairs::ReadNames() {
	std::string name_sequence;
	std::cout <<
		"Enter a sequence of names separated by spaces:\n";
	std::getline(std::cin, name_sequence);
	char* c_name_sequence = new char[name_sequence.length() + 1];
	std::strcpy(c_name_sequence, name_sequence.c_str());
	char* name = std::strtok(c_name_sequence, " ");
	while (name != nullptr) {
		names.push_back(name);
		ages.push_back(-1);
		name = std::strtok(nullptr, " ");
	}
	std::cout << "\n\n";
}

void Namepairs::ReadAges() {
	if (!names.size()) {
		std::cerr << "It is not possible to match the names with "
			"age because the container with the names is empty."
			"\n\n";
	}
	else {
		for (auto i(0u); i < names.size(); ++i) {
			if (ages.at(i) == -1) {
				std::cout
					<< "Enter the age for the name \""
					<< names.at(i) << "\": ";
				int age;
				std::cin >> age;
				ages.at(i) = age;
			}
		}
		std::cin.get();
		std::cout << "\n\n";
	}
}

void Namepairs::Print() {
	std::cout << "Pairs (year: age): " << std::endl;
	for (auto i(0u); i < names.size(); ++i)
		std::cout << "   " << names[i] << ": " << 
			ages[i] << "\n";
	std::cout << std::endl;
}

void Namepairs::Sort() {
	std::string temp_name;
	int temp_age;

	for (int i = 0; i < names.size() - 1; ++i)
		for (int j = 0; j < names.size() - i - 1; ++j)
			if (names[j] > names[j + 1]) {
				temp_name = names[j];
				names[j] = names[j + 1];
				names[j + 1] = temp_name;

				temp_age = ages[j];
				ages[j] = ages[j + 1];
				ages[j + 1] = temp_age;
			}
}

std::ostream& operator<<(std::ostream& os, const Namepairs& pairs) {
	for (auto i(0u); i < pairs.names.size(); ++i)
		os	<< pairs.names.at(i) << ": " 
			<< pairs.ages.at(i) << "\n";
	std::cout << std::endl;
	return os;
}

bool operator==(const Namepairs& lhs, const Namepairs& rhs) {
	if (lhs.names.size() == rhs.names.size() &&
		lhs.ages.size() == rhs.ages.size()) {
		for (auto i(0u); i < lhs.names.size(); ++i)
			if (lhs.names[i] != rhs.names[i] ||
				lhs.ages[i] != rhs.ages[i])
				return false;		
		return true;
	}
	else
		return false;
}

bool operator!=(const Namepairs& lhs, const Namepairs& rhs) {
	return !operator==(lhs, rhs);
}
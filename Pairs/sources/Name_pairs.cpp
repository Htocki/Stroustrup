#include "Name_pairs.h"



void Name_pairs::read_names() {
	std::string name_sequence;
	std::getline(std::cin, name_sequence);

	char* c_name_sequence = new char[name_sequence.length() + 1];
	std::strcpy(c_name_sequence, name_sequence.c_str());
	
	char* name = std::strtok(c_name_sequence, " ");
	while (name != nullptr) {
		_names.push_back(name);
		name = std::strtok(nullptr, " ");
	}
	
	std::cout << std::endl;
}

void Name_pairs::read_ages() {
	for (const auto name : _names) {
		std::cout
			<< "Enter the age for the name "
			<< name << ":  ";
		int age;
		std::cin >> age;
		_ages.push_back(age);
	}
	
	std::cout << std::endl;
}

void Name_pairs::print() {
	for (decltype(_names.size()) i{0}; i < _names.size(); ++i)
		std::cout << _names[i] << " " << _ages[i] << std::endl;
	
	std::cout << std::endl;
}

void Name_pairs::sort() {
	std::string temp_name;
	int temp_age;

	for (int i = 0; i < _names.size() - 1; i++) {
		for (int j = 0; j < _names.size() - i - 1; j++) {
			if (_names[j] > _names[j + 1]) {
				temp_name = _names[j];
				_names[j] = _names[j + 1];
				_names[j + 1] = temp_name;

				temp_age = _ages[j];
				_ages[j] = _ages[j + 1];
				_ages[j + 1] = temp_age;
			}
		}
	}
}
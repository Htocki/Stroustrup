#include "Name_pairs.h"



Name_pairs::Name_pairs() {}

Name_pairs::Name_pairs(std::initializer_list<std::pair<std::string, int>> list) {
	for (auto e : list) {
		_names.push_back(e.first);
		_ages.push_back(e.second);
	}
}

void Name_pairs::read_names() {
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string name_sequence;
	std::cout << "Enter a sequence of names separated by spaces: " << std::endl;
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
	if (_names.size() == 0)
		std::cerr << "It is not possible to match the names with "
			"age because the container with the names is empty."
			<< std::endl << std::endl;
	else
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
	for (decltype(_names.size()) i{ 0 }; i < _names.size(); ++i)
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

std::ostream& operator<<(std::ostream& os, const Name_pairs& pairs) {
	for (decltype(pairs._names.size()) i(0); i < pairs._names.size(); ++i)
		os << pairs._names[i] << " " << pairs._ages[i] << std::endl;
	os << std::endl;
	return os;
}

bool operator==(const Name_pairs& left, const Name_pairs& right) {
	if (left._names.size() == right._names.size() &&
		left._ages.size() == right._ages.size()) {
		for (decltype(left._names.size()) i(0); i < left._names.size(); ++i)
			if (left._names[i] != right._names[i] ||
				left._ages[i] != right._ages[i])
				return false;		
		return true;
	}
	else
		return false;
}

bool operator!=(const Name_pairs& left, const Name_pairs& right) {
	return !operator==(left, right);
}
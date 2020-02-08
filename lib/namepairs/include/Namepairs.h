#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <limits>
#include <initializer_list>
#include <utility>



class Namepairs {
public:
	Namepairs();
	Namepairs(std::initializer_list<std::pair<std::string, int>>);
	void read_names();
	void read_ages();
	void print();
	void sort();

	friend std::ostream& operator<<(std::ostream&, const Namepairs&);
	friend bool operator==(const Namepairs&, const Namepairs&);
	friend bool operator!=(const Namepairs&, const Namepairs&);

private:
	std::vector<std::string> _names;
	std::vector<double> _ages;
};

#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <limits>
#include <initializer_list>
#include <utility>



class Name_pairs {
public:
	Name_pairs();
	Name_pairs(std::initializer_list<std::pair<std::string, int>>);
	void read_names();
	void read_ages();
	void print();
	void sort();

	friend std::ostream& operator<<(std::ostream&, const Name_pairs&);
	friend bool operator==(const Name_pairs&, const Name_pairs&);
	friend bool operator!=(const Name_pairs&, const Name_pairs&);

private:
	std::vector<std::string> _names;
	std::vector<double> _ages;
};

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>



class Name_pairs {
public:
	void read_names();
	void read_ages();
	void sort();
	void print();

	bool operator==(const Name_pairs&);
	bool operator!=(const Name_pairs&);

	friend std::ostream& operator<<(std::ostream&, const Name_pairs&);


private:
	std::vector<std::string> _names;
	std::vector<int> _ages;
};

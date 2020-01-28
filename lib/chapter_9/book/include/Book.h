#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include "Date.h"



class Book {
public:
	class Invalid_ISBN {};

	Book(std::string, std::string, std::string, Chrono::Date);

	std::string isbn() const { return _isbn; }
	std::string title() const { return _title; }
	std::string author() const { return _author; }
	Chrono::Date copyright_rd() const { return _copyright_rd; }
	
	bool is_giving_out() { return _giving_out; }

private:
	std::string _isbn;
	std::string _title;
	std::string _author;
	Chrono::Date _copyright_rd;	// Copyright registration date
	bool _giving_out;

	bool is_valid(std::string);
	bool is_number(std::string);
};



bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
std::ostream& operator<<(std::ostream&, const Book&);
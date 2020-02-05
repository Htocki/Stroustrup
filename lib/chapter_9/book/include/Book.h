#pragma once
#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include "Date.h"



class Book {
public:
	enum class Genre {
		NotSpecified,
		Fantastic,
		Prose,
		Periodical,
		Bibliography,
		Juvenile
	};

	class Invalid_ISBN {};

	Book();
	Book(std::string, std::string, std::string, Date, Genre);

	std::string isbn() const { return _isbn; }
	std::string title() const { return _title; }
	std::string author() const { return _author; }
	Date copyright_rd() const { return _crd; }
	Genre genre() const { return _genre; }
	
	bool is_giving_out() { return _giving_out; }

private:
	std::string _title = "Not specified";
	std::string _isbn = "Not specified";
	std::string _author = "Not specified";
	Date _crd; // Copyright registration date
	Genre _genre = Genre::NotSpecified;
	bool _giving_out = false;

	bool is_valid(std::string);
	bool is_number(std::string);

	friend std::istream& operator>>(std::istream&, Book&);
};



std::ostream& operator<<(std::ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
std::istream& operator>>(std::istream&, Book::Genre&);
std::ostream& operator<<(std::ostream&, const Book::Genre&);
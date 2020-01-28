#include "Book.h"



Book::Book(
	std::string title,
	std::string author,
	std::string isbn,
	Chrono::Date copyright_rd
)
	: _title(title)
	, _author(author)
	, _copyright_rd(copyright_rd)
{
	if (!is_valid(isbn)) throw Invalid_ISBN{};
	else _isbn = isbn;
}

bool Book::is_valid(std::string isbn) {
	char* c_isbn = new char[isbn.length() + 1];
	std::strcpy(c_isbn, isbn.c_str());

	std::vector<std::string> parts;
	char* part = std::strtok(c_isbn, "-");
	while (part != nullptr) {
		parts.push_back(part);
		part = std::strtok(nullptr, "-");
	}

	if (parts.size() != 4 || parts[3].size() != 1) return false;
	else 
		if (is_number(parts[0]) &&
			is_number(parts[1]) &&
			is_number(parts[2]) &&
			std::isalnum(parts[3][0])) return true;
		else return false;
}

bool Book::is_number(std::string string) {
	for (auto e : string)
		if (!std::isdigit(e)) return false;
	return true;
}

bool operator==(const Book& left, const Book& right) {
	return operator==(left.isbn(), right.isbn());
}

bool operator!=(const Book& left, const Book& right) {
	return operator!=(left.isbn(), right.isbn());
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
	os  << "Title: " << book.title() << std::endl
		<< "Author: " << book.author() << std::endl
		<< "ISBN: " << book.isbn() << std::endl
		<< std::endl;
	return os;
}
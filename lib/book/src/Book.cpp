#include "Book.h"

#include <limits>

Book::Book() {}

Book::Book(
	std::string title,
	std::string isbn,
	std::string author,
	Date crd,
	Genre genre
)
	: _title(title)
	, _author(author)
	, _crd(crd)
	, _genre(genre)
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

std::istream& operator>>(std::istream& is, Book& book) {
	is.clear();

	std::string title;
	std::cout << "Input book title: ";
	std::getline(is, title);

	std::string isbn;
	std::cout << "Input book ISBN: ";
	std::getline(is, isbn);

	std::string author;
	std::cout << "Input book author: ";
	std::getline(is, author);

	Date date;
	std::cout << "Input book copyright registration date: " << std::endl;
	is >> date;

	Book::Genre genre;
	std::cout << "Input book genre: ";
	is >> genre;

	book = Book(title, isbn, author, date, genre);

	std::cout << std::endl << std::endl;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Book& book) {
	os << "Title: " << book.title() << std::endl
		<< "Author: " << book.author() << std::endl
		<< "Genre: " << book.genre() << std::endl
		<< "ISBN: " << book.isbn() << std::endl
		<< std::endl;
	return os;
}

bool operator==(const Book& left, const Book& right) {
	return operator==(left.isbn(), right.isbn());
}

bool operator!=(const Book& left, const Book& right) {
	return !operator==(left.isbn(), right.isbn());
}

std::istream& operator>>(std::istream& is, Book::Genre& genre) {
	is.clear();
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::string s_genre;
	std::getline(is, s_genre);

	if (s_genre == "Bibliography")
		genre = Book::Genre::Bibliography;
	else if (s_genre == "Fantastic")
		genre = Book::Genre::Fantastic;
	else if (s_genre == "Juvenile")
		genre = Book::Genre::Juvenile;
	else if (s_genre == "Periodical")
		genre = Book::Genre::Periodical;
	else if (s_genre == "Prose")
		genre = Book::Genre::Prose;
	else
		genre = Book::Genre::NotSpecified;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Book::Genre& genre) {
	switch (genre) {
	case Book::Genre::Bibliography:
		os << "Bibliography";
		break;
	case Book::Genre::Fantastic:
		os << "Fantastic";
		break;
	case Book::Genre::Juvenile:
		os << "Juvenile";
		break;
	case Book::Genre::Periodical:
		os << "Periodical";
		break;
	case Book::Genre::Prose:
		os << "Prose";
		break;
	case Book::Genre::NotSpecified:
		os << "Not Specified";
		break;
	}
	return os;
}
#include "Library.h"



void Library::add_book() {
	Book book;
	std::cin >> book;
	_books.push_back(book);
}

void Library::add_patron() {
	Patron patron;
	std::cin >> patron;
	_patrons.push_back(patron);
}

void Library::add_transaction() {
	std::cin.clear();
	std::cin.ignore(
		std::numeric_limits<std::streamsize>::max(), '\n');

	std::string patronName;
	std::cout << "Input patron name: ";
	std::getline(std::cin, patronName);

	if (!is_patron_library_client(patronName))
		throw SearchError{};

	std::string bookTitle;
	std::cout << "Input book title: ";
	std::getline(std::cin, bookTitle);

	if (!is_book_part_of_library(bookTitle))
		throw SearchError{};

	Patron patron = search_patron(patronName);
	if (!patron.is_membership_fee_paid())
		throw Debt{};

	Book book = search_book(bookTitle);
	std::cout << "Input current date: " << std::endl;
	Date date; std::cin >> date;
	
	Transaction transaction{ book, patron, date };
	_transactions.push_back(transaction);
}

auto Library::debtors_names() -> std::vector<std::string> {
	std::vector<std::string> debtorsNames;
	for (const auto& patron : _patrons)
		if (!patron.is_membership_fee_paid())
			debtorsNames.push_back(patron.name());
	return debtorsNames;
}

bool Library::is_patron_library_client(std::string patronName) {
	for (const auto& patron : _patrons)
		if (patron.name() == patronName)
			return true;
	return false;
}

bool Library::is_book_part_of_library(std::string bookTitle) {
	for (const auto& book : _books)
		if (book.title() == bookTitle)
			return true;
	return false;
}

auto Library::search_patron(std::string patronName) -> Patron {
	for (const auto& patron : _patrons)
		if (patron.name() == patronName)
			return patron;
	return Patron{};
}

auto Library::search_book(std::string bookTitle) -> Book {
	for (const auto& book : _books)
		if (book.title() == bookTitle)
			return book;
	return Book{};
}
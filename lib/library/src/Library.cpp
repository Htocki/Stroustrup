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

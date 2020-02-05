#pragma once
#include <vector>
#include <cstring>
#include <limits>
#include "Book.h"
#include "Date.h"
#include "Patron.h"



class Library {
public:
	struct Transaction {
		Book book;
		Patron patron;
		Date date;
	};

	void add_book();


private:
	std::vector<Book> _books;
	std::vector<Patron> _patrons;
	std::vector<Transaction> _transactions;
};
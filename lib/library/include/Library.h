#pragma once
#include <vector>
#include <cstring>
#include <limits>
#include <vector>
#include <string>
#include "Book.h"
#include "Date.h"
#include "Patron.h"



class Library {
public:
	class SearchError {};
	class Debt {};

	struct Transaction {
		Book book;
		Patron patron;
		Date date;
	};

	void add_book();
	void add_patron();
	void add_transaction();
	auto debtors_names() -> std::vector<std::string>;


private:
	bool is_patron_library_client(std::string patronName);
	bool is_book_part_of_library(std::string bookTitle);

	/*	Use the two underlying functions only if functions 
		is_patron_library_client() and is_book_part_of_library()
		return true.
	*/
	auto search_patron(std::string) -> Patron;
	auto search_book(std::string) -> Book;

	std::vector<Book> _books;
	std::vector<Patron> _patrons;
	std::vector<Transaction> _transactions;
};
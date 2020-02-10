#include "Patron.h"



Patron::Patron() 
	: _name("Unnamed")
	, _library_card_number(0)
	, _membership_fee(0)
	, _membership_fee_paid(false)
{
	// Добавить проверку корректности
}

Patron::Patron(
	std::string user_name, 
	int library_card_number,
	int membership_fee
)
	: _name(user_name)
	, _library_card_number(library_card_number)
	, _membership_fee(membership_fee)
	, _membership_fee_paid(true)
{}

void Patron::name(std::string name) {
	_name = name;
}

void Patron::library_card_number(int library_card_number) {
	if (library_card_number < 0) throw Invalid{};
	else _library_card_number = library_card_number;
}

void Patron::membership_fee(int membership_fee) {
	if (membership_fee < 0) throw Invalid{};
	else _membership_fee = membership_fee;
}

std::istream& operator>>(std::istream& is, Patron& patron) {
	std::cout << "Input patron name: ";
	std::string name; is >> name;
	patron.name(name);

	std::cout << "Input library card number: ";
	int number;  is >> number;
	patron.library_card_number(number);

	std::cout << "Input size of membership fee: ";
	int size; is >> size;
	patron.membership_fee(size);

	std::cout << std::endl << std::endl;

	return is;
}
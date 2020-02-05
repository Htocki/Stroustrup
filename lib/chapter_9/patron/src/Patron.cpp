#include "Patron.h"



Patron::Patron() 
	: _user_name("Unnamed")
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
	: _user_name(user_name)
	, _library_card_number(library_card_number)
	, _membership_fee(membership_fee)
	, _membership_fee_paid(false)
{}

void Patron::user_name(std::string user_name) {
	_user_name = user_name;
}

void Patron::library_card_number(int library_card_number) {
	if (library_card_number < 0) throw Invalid{};
	else _library_card_number = library_card_number;
}

void Patron::membership_fee(int membership_fee) {
	if (membership_fee < 0) throw Invalid{};
	else _membership_fee = membership_fee;
}
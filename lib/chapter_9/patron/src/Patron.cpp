#include "Patron.h"



Patron::Patron(
	std::string user_name, 
	int library_card_number
)
	: _user_name(user_name)
	, _library_card_number(library_card_number)
	, _membership_fee(0)
	, _membership_fee_paid(false)
{}

void Patron::membership_fee(int membership_fee) {
	if (membership_fee < 0) throw Invalid{};
	else _membership_fee = membership_fee;
}
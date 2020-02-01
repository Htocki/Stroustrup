#pragma once
#include <string>



class Patron {
public:
	class Invalid {};

	Patron(std::string, int);

	std::string user_name() const { return _user_name; }
	int library_card_number() const { return _library_card_number; }
	int membership_fee() const { return _membership_fee; }
	bool is_membership_fee_paid() { return _membership_fee; }

	void membership_fee(int membership_fee);

private:
	std::string _user_name;
	int _library_card_number;
	int _membership_fee;

	bool _membership_fee_paid;
};
#pragma once
#include <string>
#include <iostream>



class Patron {
public:
	class Invalid {};

	Patron();
	Patron(std::string, int, int);

	std::string user_name() const { return _user_name; }
	int library_card_number() const { return _library_card_number; }
	int membership_fee() const { return _membership_fee; }
	bool is_membership_fee_paid() { return _membership_fee; }

	void user_name(std::string);
	void library_card_number(int);
	void membership_fee(int);

private:
	std::string _user_name;
	int			_library_card_number;
	int			_membership_fee;

	bool		_membership_fee_paid;
};



std::istream& operator>>(std::istream&, Patron&);
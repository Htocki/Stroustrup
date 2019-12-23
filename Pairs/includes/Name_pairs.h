#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cstring>



class Name_pairs {
public:
	// Reads a series of names.
	void read_names();
	// Prompts the user to enter an age for the name.
	void read_ages();
	/* Displays the pairs (name [i], age [i])
	   (one per line) in the order specified by 
	   the name vector. */
	void print();
	/* Sorts the name vector in alphabetical order and
	   reorganizes the age vector accordingly. */
	void sort();


private:
	std::vector<std::string> _names;
	std::vector<int> _ages;
};
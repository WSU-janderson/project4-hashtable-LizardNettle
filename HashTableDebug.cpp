/**
* HashTableDebug.cpp
 *
 * Write your tests in this file
 * ABANDONING THIS FILE BECAUSE FOR SOME REASON I GET LINKER ERRORS WITH THIS SPECIFIC FILE, AND NOTHING I DO RESOLVES IT. DEBUG STUFF GOING IN MainTest.cpp NOW.
 * SPENT LIKE 2 HOURS REPEATEDLY TRYING TO DELETE AND CHANGE BUILD FILES, AND NOTHING WORKED SO I GIVE UP.
 */
#include <iostream>
#include "HashTable.h"
#include <cstddef>

using namespace std;

int main() {
	bool isTrue;
	// test constructors
	std::cout << "Testing both constructors...";
	HashTable table{};
	HashTable table2{8};
	std::cout << "HashTable objects created successfully" << std::endl;


	// test accessors
	std::cout << "TESTING ACCESSORS BEFORE VALS ARE ADDED..." << std::endl;
	std::cout << "contains() test 1...";
	isTrue = table.contains("key");
	std::cout << "Result: " << isTrue << std::endl;

	std::cout << "alpha() test 1...";
	std::cout << "Result: " << table.alpha() << std::endl;

	std::cout << "capacity() test 1...";
	std::cout << "Result: " << table.capacity() << std::endl;

	std::cout << "size() test 1...";
	std::cout << "Result: " << table.size() << std::endl;

	std::cout << "TESTING INSERT()..." << std::endl;


	return 0;
}
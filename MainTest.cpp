
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
	std::cout << std::endl << "TESTING ACCESSORS BEFORE VALS ARE ADDED..." << std::endl;
		std::cout << "contains() test 1...";
		isTrue = table.contains("key");
		std::cout << "Result: " << isTrue << std::endl;

		std::cout << "alpha() test 1...";
		std::cout << "Result: " << table.alpha() << std::endl;

		std::cout << "capacity() test 1...";
		std::cout << "Result: " << table.capacity() << std::endl;

		std::cout << "size() test 1...";
		std::cout << "Result: " << table.size() << std::endl;

	std::cout << std::endl << "TESTING INSERT()..." << std::endl;
		table.insert("James", 26); std::cout << "table.insert('James', 26)" << std::endl;
		table.insert("Randal", 1); std::cout << "table.insert('Randal', 1)" << std::endl;
		table.insert("Randal", 2); std::cout << "table.insert('Randal', 2)" << std::endl;
		table.insert("Kevin", 5); std::cout << "table.insert('Kevin', 5)" << std::endl;

	std::cout << std::endl << "TESTING ACCESSORS..." << std::endl;
		std::cout << "contains() test 2..." << std::endl;
		std::cout << "contains('James'): " << table.contains("James") << std::endl;
		std::cout << "contains('Randal'): " << table.contains("Randal") << std::endl;

		std::cout << "alpha() test 2...";
		std::cout << "Result: " << table.alpha() <<std::endl;

		std::cout << "capacity() test 2...";
		std::cout << "Result: " << table.capacity() << " (8 expected)" << std::endl;

		std::cout << "size() test 2...";
		std::cout << "Result: " << table.size() << " (3 expected)" << std::endl;




	return 0;
}

#include <iostream>
#include "HashTable.h"

// used this file for all testing on my end due to issues with HashTableDebug.cpp (see comments in HashTableDebug.cpp for details).

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

	std::cout << "checking all keys...";
	vector<string> allKeys = table.keys();
	vector<int> allValues;
	for (string key : allKeys) {
		std::cout << key << ". ";
		allValues.push_back(table.get(key).value());
	} std::cout << std::endl;

	std::cout << "checking all values...";
	for (int value : allValues) {
		std::cout << value << ". ";
	}
	cout << std::endl;

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

	std::cout << std::endl << "TESTING REMOVE..." << std::endl;
		table.remove("James"); std::cout << "table.remove('James'): status (" << table.contains("James") << ") (0 expected)" << std::endl;
		table.remove("Randal"); std::cout << "table.remove('randal'): status (" << table.contains("Randal") << ") (0 expected)" << std::endl;

	std::cout << "ADDING 4 KEY-PAIR VALUES TO TRIGGER RESIZE..." << std::endl;
		table.insert("key1", 11); std::cout << "table.insert('key1', 11)" << std::endl;
		table.insert("key2", 12); std::cout << "table.insert('key2', 12)" << std::endl;
		table.insert("key3", 13); std::cout << "table.insert('key3', 13)" << std::endl;
		table.insert("key4", 14); std::cout << "table.insert('key4', 14)" << std::endl;

	std::cout << "CHECKING TO ENSURE RESIZE WAS DONE CORRECTLY..." << std::endl;
		std::cout << "size: " << table.size() << std::endl;
		std::cout << "capacity: " << table.capacity() << std::endl;
		std::cout << "contains('key1'): " << table.contains("key1") << std::endl;
		std::cout << "contains('key2'): " << table.contains("key2") << std::endl;
		std::cout << "contains('key3'): " << table.contains("key3") << std::endl;
		std::cout << "contains('key4'): " << table.contains("key4") << std::endl;


	std::cout << "checking all keys...";
	allKeys.clear(); allValues.clear();
	allKeys = table.keys();
	for (string key : allKeys) {
		std::cout << key << ". ";
		allValues.push_back(table.get(key).value());
	} std::cout << std::endl;

	std::cout << "checking all values...";
	for (int value : allValues) {
		std::cout << value << ". ";
	}

	return 0;
}
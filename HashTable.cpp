/**
 * HashTable.cpp
 */

#include <string>
#include <vector>
#include "HashTable.h"
#include "HashTableBucket.h"

using namespace std;

/**
 * Constructor that takes an initial capacity for the table.
 * If no capacity is given, it defaults to 8 initially.
*/
HashTable::HashTable(size_t initCapacity) {
	buckets.resize(initCapacity);

	// insert (initCapacity) number of HashTableBucket's
	for (int i = 0; i < initCapacity; i++) {
 		HashTableBucket bucket = HashTableBucket();
 		buckets.insert(buckets.begin() + i, bucket);
 }

}
/**
 * Insert a new key-value pair into the table. Duplicate keys are NOT allowed. The
 * method should return true if the insertion was successful. If the insertion was
 * unsuccessful, such as whened behavior. Simply put, you do not need to address attempts
 * to access keys not in the table inside the bracket operator method.
*/
int& HashTable::operator[](const string& key) {

}
/**
 * Insert a new key-value pair into the table. Duplicate keys are NOT allowed. The
 * method should return true if the insertion was successful. If the insertion was
 * unsuccessful, such as when a duplicate is attempted to be inserted, the method
 * should return false
*/
bool HashTable::insert(std::string key, size_t value) {
	// check for duplicates

	// generate hash, then try to place key-value pair at the home position
	// else, start probing.
	hash<string> hash;
	int home = hash(key) % size();

	if (buckets[home].isEmpty()) {
		buckets[home].load(key, value);
		return true;
	}
	// for all values in offsets, try to see if buckets[home + offset[i]] is free.
	for (int offset : offsets) {
		int probe = home + offset;
		if (buckets[probe].isEmpty()) {
			buckets[probe].load(key, value);
			return true;
		}
	}
	return false;
}
/**
 * If the key is in the table, remove will “erase” the key-value pair from the
 * table. This might just be marking a bucket as empty-after-remove
*/
bool HashTable::remove(std::string key) {}
/**
 * contains returns true if the key is in the table and false if the key is not in
 * the table.
*/
bool HashTable::contains(const string& key) const {
	for (int i = 1; i < buckets.capacity(); i++) {
		if (buckets[i].getKey() == key) {
			return true;
		}
	}
	return false;
}

/**
 * If the key is found in the table, find will return the value associated with
 * that key. If the key is not in the table, find will return something called
 * nullopt, which is a special value in C++. The find method returns an
 * optional<int>, which is a way to denote a method might not have a valid value
 * to return. This approach is nicer than designating a special value, like -1, to
 * signify the return value is invalid. It's also much better than throwing an
 * exception if the key is not found.
*/
std::optional<int> HashTable::get(const string& key) const {}

/**
 * keys returns a std::vector (C++ version of ArrayList, or simply list/array)
 * with all of the keys currently in the table. The length of the vector should be
 * the same as the size of the hash table.
*/
std::vector<string> HashTable::keys() const {}
/**
 * alpha returns the current load factor of the table, or size/capacity. Since
 * alpha returns a double,make sure to properly cast the size and capacity, which
 * are size_t, to avoid integer division. You can cast a size_t num to a double in
 * C++ like:
 static_cast<double>(num)
 *
 * The time complexity for this method must be O(1).
*/
double HashTable::alpha() const {}
/**
* capacity returns how many buckets in total are in the hash table. The time
* complexity for this algorithm must be O(1).
*/
size_t HashTable::capacity() const {}
/**
* The size method returns how many key-value pairs are in the hash table. The
* time complexity for this method must be O(1)
*/
size_t HashTable::size() const {}

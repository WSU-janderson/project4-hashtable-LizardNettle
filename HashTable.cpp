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
	// insert (initCapacity) number of HashTableBucket's
	buckets.resize(initCapacity);

	for (int i = 0; i < initCapacity; i++) {
 		HashTableBucket bucket = HashTableBucket();
		buckets.push_back(bucket);
 }

}
/**
 * Insert a new key-value pair into the table. Duplicate keys are NOT allowed. The
 * method should return true if the insertion was successful, otherwise returns false.
 * unsuccessful, such as whened behavior.
 *
 * Does not address attempts to access keys not
 * in the table.
*/
int& HashTable::operator[](const string& key) {
	// TODO: need to check notes on how operator[] works.
	// may be able to make it just call insert(key, value) ? Unsure.
}
/**
 * Insert a new key-value pair into the table. Duplicate keys are NOT allowed.
 * @return returns true if the insertion was successful, and false otherwise.
*/
bool HashTable::insert(std::string key, size_t value) {
	if (contains(key)) {
		return false;
	}
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
 * table. This is done by marking the bucket as EAR.
*/
bool HashTable::remove(std::string key) {
	// if key is in buckets, makeEAR()
	for (int i = 1; i < buckets.capacity(); i++) {
		if (buckets[i].getKey() == key) {
			buckets[i].makeEAR();
		}
	}
	return false;
}

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
std::optional<int> HashTable::get(const string& key) const {
	// if key is in buckets, getValue().
	for (int i = 1; i < buckets.capacity(); i++) {
		if (buckets[i].getKey() == key) {
			return buckets[i].getValue();
		}
	}
}

/**
 * keys returns a std::vector with all of the keys currently
 * in the table. The length of the vector should be
 * the same as the size of the hash table.
*/
std::vector<string> HashTable::keys() const {
	vector<string> allKeys;

	// add the keys of all normal buckets to allKeys.
	for (int i = 0; i < buckets.capacity(); i++) {
		if (buckets[i].isNormal()) {
			allKeys.push_back(buckets[i].getKey());
		}
	}
	return allKeys;
}
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
size_t HashTable::capacity() const {
	return buckets.capacity();
}
/**
* The size method returns how many key-value pairs are in the hash table. The
* time complexity for this method must be O(1)
*/
size_t HashTable::size() const {
	// check every bucket in buckets, if bucket.isNormal, tick counter.
	int counter = 0;
	for (int i = 0; i < buckets.capacity(); i++) {
		if (buckets[i].isNormal()) {
			counter++;
		}
	}
	return counter;
}

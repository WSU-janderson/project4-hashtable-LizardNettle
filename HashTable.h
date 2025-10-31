/**
 * HashTable.h
 */
#include <optional>
#include <string>
#include "HashTableBucket.h"
#include <vector>

class HashTable {
public:
	static const size_t DEFAULT_INITIAL_CAPACITY = 8;
    enum class BucketType {NORMAL, ESS, EAR};
    // constructors & destructors
	HashTable();
    HashTable(size_t initCapacity);

    // operators
    int& operator[](const std::string& key);
	// std::ostream& operator<<(std::ostream&);

    // setters
    bool insert(std::string key, size_t value);
	void resize();
    bool remove(std::string key);

    // getters
    bool contains(const std::string& key) const;
    [[nodiscard]] std::optional<int> get(const std::string& key) const;
    [[nodiscard]] std::vector<std::string> keys() const;
    double alpha() const;
    size_t capacity() const;
    size_t size() const;
	friend std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);

private:
    // BucketType bucketState;
    std::vector<HashTableBucket> buckets;
	std::vector<int> offsets = {4, 5, 2, 9, 1, 8, 7, 3, 6};

};

std::ostream& operator<<(std::ostream& os, const HashTable& hashTable);
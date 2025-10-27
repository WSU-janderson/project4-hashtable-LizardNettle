/**
 * HashTable.h
 */
#include <optional>
#include <string>
#include "HashTableBucket.h"

class HashTable {
public:
    enum class BucketType {NORMAL, ESS, EAR};
    // constructors & destructors
    HashTable(size_t initCapacity = 8);

    // operators
    int& operator[](const std::string& key);

    // setters
    bool insert(std::string key, size_t value);
    bool remove(std::string key);

    // getters
    bool contains(const std::string& key) const;
    [[nodiscard]] std::optional<int> get(const std::string& key) const;
    [[nodiscard]] std::vector<std::string> keys() const;
    double alpha() const;
    size_t capacity() const;
    size_t size() const;

private:
    BucketType bucketState;
    std::vector<HashTableBucket> buckets;
	std::vector<int> offsets = {4, 5, 2, 9, 1, 8, 7, 3, 6};




};

//
// Created by zande on 10/23/2025.
//

#include "HashTableBucket.h"

#include <ostream>

using namespace std;

/**
 * default constructor, only sets bucketState to ESS
 */
HashTableBucket::HashTableBucket() {
    this->bucketState = BucketType::ESS;
    this->value = 0;
}

HashTableBucket::HashTableBucket(const std::string &key, const int value) {
    bucketState = BucketType::NORMAL;
    this->key = key;
    this->value = value;
}

void HashTableBucket::makeNormal() {
    this->bucketState = BucketType::NORMAL;
}
void HashTableBucket::makeESS() {
    this->bucketState = BucketType::ESS;
}
void HashTableBucket::makeEAR() {
    this->bucketState = BucketType::EAR;
}

/**
 * @return returns the key of this bucket
 */
std::string HashTableBucket::getKey() const {
    return this->key;
}

/**
 * @return returns the value of this bucket
 */
int HashTableBucket::getValue() const {
    return this->value;
}

bool HashTableBucket::isEmptySinceStart() const {
    return (bucketState == BucketType::ESS);
}

bool HashTableBucket::isEmptyAfterRemove() const {
    return (bucketState == BucketType::EAR);
}

bool HashTableBucket::isNormal() const {
	if (bucketState == BucketType::ESS) {
		return false;
	}
	if (bucketState == BucketType::NORMAL) return true;
	return false;
}

bool HashTableBucket::isEmpty() const {
	if (isNormal()) {
		return false;
	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket) {
    std::string thisKey = bucket.key;
    int thisValue = bucket.value;

    os << "key: " << thisKey << ", value: " << thisValue << std::endl;
    return os;
}
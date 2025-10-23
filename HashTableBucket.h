//
// Created by zande on 10/23/2025.
//


#ifndef HASHTABLE_HASHTABLEBUCKET_H
#define HASHTABLE_HASHTABLEBUCKET_H

#include <string>

class HashTableBucket {
public:
    enum class BucketType {NORMAL, ESS, EAR};

    // constructors
    HashTableBucket();
    HashTableBucket(const std::string &key, int value);
    /**
     * sets the 'key' and 'value' to the given values
     * @param key new string key of the bucket
     * @param value new value of the bucket.
     */
    void load(std::string key, int value)
    {this->key = key; this->value = value; this->bucketState = BucketType::NORMAL;};

    /**
     * resets the bucket and marks it EAR
     */
    void unload()
    {this->key.clear(); this->value = 0; this->bucketState = BucketType::EAR;};
    void makeNormal();
    void makeESS();
    void makeEAR();

    //getters
    std::string getKey();
    int getValue() const;
    bool isEmptySinceStart() const;
    bool isEmptyAfterRemove() const;
    bool isEmpty() const;

    friend std::ostream& operator<<(std::ostream& os, const HashTableBucket& bucket);

private:
    BucketType bucketState;
    std::string key;
    int value;
};


#endif //HASHTABLE_HASHTABLEBUCKET_H
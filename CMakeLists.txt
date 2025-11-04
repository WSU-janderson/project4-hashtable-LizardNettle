cmake_minimum_required(VERSION 4.0)
project(hashtable)

set(CMAKE_CXX_STANDARD 20)

add_executable(HashTableTests
        HashTableTests.cpp
        HashTable.cpp
        HashTable.h
        HashTableBucket.cpp
        HashTableBucket.h
)

#add_executable(HashTableDebug
#        HashTableDebug.cpp
#        HashTable.h
#        HashTableBucket.h
#        HashTable.cpp
#        HashTableBucket.cpp
#)

#add_executable(MainTest.cpp
#        HashTable.h
#        HashTableBucket.h
#        HashTable.cpp
#        HashTableBucket.cpp
#        MainTest.cpp
#)

# Make SequenceDebug the default startup target
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT HashTableDebug)
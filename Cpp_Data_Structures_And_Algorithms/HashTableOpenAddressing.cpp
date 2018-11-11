#include <string>
#include <iostream>
#include "HashTableOpenAddressing.h"

HashTableOpenAddressing::HashTableOpenAddressing() {
	// Initialize current size as 0
	currentSize = 0;

	// Initialize table
	arr = new HashElement *[TABLE_SIZE];
	for (int i = 0; i < TABLE_SIZE; ++i)
		arr[i] = nullptr;

	// Specify deleted node content
	deletedElement = new HashElement(-1, "");
}

int HashTableOpenAddressing::HashFunction(int key) {
	return key % TABLE_SIZE;
}

void HashTableOpenAddressing::Insert(int key, std::string value) {
	// It's impossible to store a new element
	// if hash table doesn't have free space
	if (currentSize >= TABLE_SIZE)
		return;

	// Create a temporary element
	// to be inserted to hash table
	HashElement * temp = new HashElement(key, value);

	// Get hash key from hash function
	int hashIndex = HashFunction(key);

	// Find next free space
	// using linear probing
	while (arr[hashIndex] != nullptr && arr[hashIndex]->Key != key && arr[hashIndex]->Key != -1) {
		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}

	// If there's new element to be inserted
	// then increase the current size
	if (arr[hashIndex] == nullptr || arr[hashIndex]->Key == -1) {
		++currentSize;
		arr[hashIndex] = temp;
	}
}

std::string HashTableOpenAddressing::Search(int key) {
	// Get hash key from hash function
	int hashIndex = HashFunction(key);

	// Find the element with given key
	while (arr[hashIndex] != nullptr && arr[hashIndex]->Key != deletedElement->Key) {
		// If element is found
		// then return its value
		if (arr[hashIndex]->Key == key)
			return arr[hashIndex]->Value;

		// Keep looking for the key
		// using linear probing
		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}

	// If not found return null
	return "";
}

void HashTableOpenAddressing::Remove(int key) {
	// Get hash key from hash function
	int hashIndex = HashFunction(key);

	// Find the element with given key
	while (arr[hashIndex] != nullptr) {
		// If element is found then mark the cell as deletedElement
		if (arr[hashIndex]->Key == key) {
			arr[hashIndex] = deletedElement;

			// Reduce size
			--currentSize;

			// No need to search anymore
			return;
		}

		// Keep looking for the key
		// using linear probing
		++hashIndex;
		hashIndex %= TABLE_SIZE;
	}

	// Note: if key is not found just do nothing
}

bool HashTableOpenAddressing::IsEmpty() {
	return currentSize == 0;
}

void HashTableOpenAddressing::PrintHashTableOpenAddressing() {
	// Iterate through array
	for (int i = 0; i < currentSize; ++i) {
		// Just print the element if it exist
		if (arr[i] != nullptr && arr[i]->Key != -1) {
			std::cout << "Cell: " << i << " Key: " << arr[i]->Key;
			std::cout << " Value: " << arr[i]->Value << std::endl;
		}
	}
}

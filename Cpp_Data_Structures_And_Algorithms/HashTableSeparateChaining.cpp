#include <list>
#include <string>
#include "HashTableSeparateChaining.h"

HashTableSeparateChaining::HashTableSeparateChaining() {
	for (int i = 0; i < TABLE_SIZE; ++i)
		tableList[i].clear();
}

int HashTableSeparateChaining::HashFunction(int key) {
	return key % TABLE_SIZE;
}

void HashTableSeparateChaining::Insert(int key, std::string value) {
	bool isKeyFound = false;

	// Get hash key from hash function
	int hashKey = HashFunction(key);

	// Iterate through chaining node (linked list) in selected cell
	for (auto &hashElement : tableList[hashKey]) {
		// if the key is found update the data
		if (hashElement.Key == key) {
			isKeyFound = true;
			hashElement.Value = value;
		}
	}

	// If key is not found, append at the back
	if (!isKeyFound)
		tableList[hashKey].emplace_back(key, value);
}

std::string HashTableSeparateChaining::Search(int key) {
	// Get hash key from hash function
	int hashKey = HashFunction(key);

	// Iterate through chaining node (linked list)
	// in selected cell
	for (auto &hashElement : tableList[hashKey]) {
		// if the key is found
		// return the value of name
		if (hashElement.Key == key) {
			return hashElement.Value;
		}
	}

	// If this statement is reached
	// it means that the key is not found
	// so just return empty string
	return "";
}

void HashTableSeparateChaining::Remove(int key) {
	// Get hash key from hash function
	int hashKey = HashFunction(key);

	// Get the table cell, a std::list<HashElement>
	auto &hashElements = tableList[hashKey];

	// Tranverse the chaining node (linked list)
	for (auto it = hashElements.begin(); it != hashElements.end(); ++it) {
		// if the key is found
		// then delete the list's element
		if (it->Key == key) {
			hashElements.erase(it);
			break;
		}
	}

	// Note: if key is not found just do nothing
}

bool HashTableSeparateChaining::IsEmpty() {
	// Initialize total element
	int totalElement = 0;

	// Count all elements in table hash
	for (int i = 0; i < TABLE_SIZE; ++i) {
		totalElement += (int)tableList[i].size();

		// If the total element is not zero
		// the hash table must not be empty
		if (totalElement > 0)
			return false;
	}

	// If this statement is reached
	// it means that total element is zero
	return true;
}

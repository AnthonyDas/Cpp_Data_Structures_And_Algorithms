#ifndef HashTableOpenAddressing_OPENADDRESSING_H
#define HashTableOpenAddressing_OPENADDRESSING_H

#include <string>
#include "HashElement.h"

#define TABLE_SIZE 7

class HashTableOpenAddressing {

	int currentSize;
	HashElement * *arr;
	HashElement * deletedElement;

public:

	HashTableOpenAddressing();
	~HashTableOpenAddressing();

	void Insert(int key, std::string value);
	std::string Search(int key);
	void Remove(int key);
	bool IsEmpty();
	void PrintHashTableOpenAddressing();

private:

	int HashFunction(int key);
};

#endif // HashTableOpenAddressing_OPENADDRESSING_H

#ifndef HASHTABLE_SEPARATECHAINING_H
#define HASHTABLE_SEPARATECHAINING_H

#include <list>
#include <string>
#include "HashElement.h"

#define TABLE_SIZE 7

class HashTableSeparateChaining {

	std::list<HashElement> tableList[TABLE_SIZE];

public:

	HashTableSeparateChaining();

	void Insert(int key, std::string value);
	std::string Search(int key);
	void Remove(int key);
	bool IsEmpty();

private:

	int HashFunction(int key);

};

#endif // HASHTABLE_SEPARATECHAINING_H

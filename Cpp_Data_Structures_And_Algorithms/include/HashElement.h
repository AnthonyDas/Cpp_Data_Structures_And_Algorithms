#ifndef HASH_ELEMENT_H
#define HASH_ELEMENT_H

#include <string>

class HashElement {
public:

	int Key;
	std::string Value;

	HashElement(int key, std::string value) : Key(key), Value(value) {};

};

#endif // HASH_ELEMENT_H

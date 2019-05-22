#include <iostream>
#include "Node.h"

template <typename T>
void PrintNode(Node<T> * node) {
	while (node) {
		std::cout << node->Value << " -> ";
		node = node->Next;
	}
	std::cout << "NULL" << std::endl;
}

template <typename T>
bool CompareAllMatchedElements(Node<T> * ptr1, Node<T> * ptr2) {
	// If firstList isn't at the end but secondList is, return false
	if (ptr1 != nullptr && ptr2 == nullptr)
		return false;

	// Reached the end of the firstList
	if (ptr1 == nullptr)
		return true;

	// Compare values, and if match, check next value
	if (ptr1->Value == ptr2->Value) {
		return CompareAllMatchedElements(ptr1->Next, ptr2->Next);
	}
	
	return false;
}

// Checks whether firstList is a sublist within secondList
template <typename T>
bool Sublist_Search(Node<T> * firstList, Node<T> * secondList) {
	// If firstList is NULL, return true
	if (firstList == nullptr) {
		return true;
	}

	// If firstList is not NULL but secondList is, return false
	if ((firstList != nullptr && secondList == nullptr)) {
		return false;
	}

	// Compare values, and if match, check deeper
	if (firstList->Value == secondList->Value) {
		if (CompareAllMatchedElements(firstList, secondList)) {
			return true;
		}
	}

	// Otherwise, check starting at next element within second list
	return Sublist_Search(firstList, secondList->Next);
}

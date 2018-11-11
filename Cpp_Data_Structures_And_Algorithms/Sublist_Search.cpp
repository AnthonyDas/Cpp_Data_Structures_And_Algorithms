#include <iostream>
#include "Node.h"

template <typename T>
void PrintNode(Node<T> * node) {
	// It will print the initial node
	// until it finds NULL for the Next pointer
	// that indicate the end of the Node Chain
	while (node != nullptr) {
		std::cout << node->Value << " -> ";
		node = node->Next;
	}

	std::cout << "NULL" << std::endl;
}

template <typename T>
bool CompareAllMatchedElements(Node<T> * ptr1, Node<T> * ptr2) {
	// ptr2 cannot be NULL since it will be compared to ptr1
	if (ptr1 != nullptr && ptr2 == nullptr)
		return false;

	// It's the end of the first list element
	if (ptr1 == nullptr)
		return true;

	// Compare value of each list
	if (ptr1->Value == ptr2->Value) {
		// Compare next element
		return CompareAllMatchedElements(ptr1->Next, ptr2->Next);
	}
	
	return false;
}

template <typename T>
bool Sublist_Search(Node<T> * firstList, Node<T> * secondList) {
	// If both are NULL, just return true
	if (firstList == nullptr && secondList == nullptr) {
		return true;
	}

	// If one is NULL but the other is not,
	// just return false
	if ((firstList != nullptr && secondList == nullptr) ||
		(firstList == nullptr && secondList != nullptr)) {
		return false;
	}

	// Compare the value, if not match,
	// check next element of second list
	if (firstList->Value == secondList->Value) {
		// If matched, check deeper
		if (CompareAllMatchedElements(firstList, secondList)) {
			return true;
		}
	}

	// Check next element of the second list
	return Sublist_Search(firstList, secondList->Next);
}

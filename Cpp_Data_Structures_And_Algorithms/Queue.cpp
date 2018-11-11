#include "Queue.h"
#include "Node.h"

template <typename T>
bool Queue<T>::IsEmpty() {
	// return TRUE if there's at least one item
	// otherwise, return FALSE
	return m_count <= 0;
}

template <typename T>
T Queue<T>::Front() {
	// Just return the value
	// of m_front node
	return m_front->Value;
}

template <typename T>
void Queue<T>::Enqueue(T val) {
	// Create a new Node
	Node<T> * node = new Node<T>(val);

	if (m_count == 0) {
		// If the queue is empty
		// the new node will be
		// m_front and m_back
		node->Next = nullptr;
		m_front = node;
		m_back = m_front;
	}
	else {
		// If there's at least one element
		// in the queue, the current m_back element
		// won't be the Back element anymore
		// so the Next pointer of the current m_back
		// point to the new node
		m_back->Next = node;

		// The new Node now become the Back position
		m_back = node;
	}

	// One element is added
	++m_count;
}

template <typename T>
void Queue<T>::Dequeue() {
	// Do nothing if list is empty
	if (m_count == 0)
		return;

	// Save the current Front
	// to a new node
	Node<T> * node = m_front;

	// Point the Front pointer
	// to the element next to the current Front
	m_front = m_front->Next;

	// Now it's safe to remove
	// the first element
	delete node;

	// One element is removed
	--m_count;
}
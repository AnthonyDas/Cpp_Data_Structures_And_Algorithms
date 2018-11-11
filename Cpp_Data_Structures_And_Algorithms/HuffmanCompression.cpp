#include <iostream>
#include <vector>
#include <queue>
#include <string>

class MinHeapNode {
public:

	// Input character
	char Data;

	// Frequency of the character
	unsigned Frequency;

	// Left and right child
	MinHeapNode * LeftChild, *RightChild;

	// Constructor
	MinHeapNode(char data, unsigned freq) {
		LeftChild = nullptr;
		RightChild = nullptr;

		this->Data = data;
		this->Frequency = freq;
	}
};

class compare {
public:

	bool operator() (MinHeapNode * left, MinHeapNode * right) {
		return (left->Frequency > right->Frequency);
	}
};

void PrintCodes(MinHeapNode * root, std::string str) {
	if (!root) return;

	if (root->Data != '$') {
		std::cout << root->Data << ": " << str << std::endl;
	}

	PrintCodes(root->LeftChild, str + "0");
	PrintCodes(root->RightChild, str + "1");
}

void HuffmanCodes(char data[], int freq[], int dataSize) {
	MinHeapNode * left, *right, *top;

	// Create a min heap & inserts all characters of data[]
	std::priority_queue<MinHeapNode*, std::vector<MinHeapNode*>, compare> minHeap;

	for (int i = 0; i < dataSize; ++i)
		minHeap.push(new MinHeapNode(data[i], freq[i]));

	// Iterate while size of heap doesn't become 1
	while (minHeap.size() != 1) {
		// Extract the two minimum
		// freq items from min heap
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

		// Create a new internal node with frequency equal to the sum of the
		// two nodes frequencies. Make the two extracted node as left and right children
		// of this new node. Add this node to the min heap '$' is a special value
		// for internal nodes, not used
		top = new MinHeapNode('$', left->Frequency + right->Frequency);

		top->LeftChild = left;
		top->RightChild = right;

		minHeap.push(top);
	}

	// Print Huffman codes using the Huffman tree built above
	PrintCodes(minHeap.top(), "");
}

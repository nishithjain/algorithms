#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<typename T>
class MinHeap {
	T* maxHeap;		// Create Binary Tree, then use it to construct heap.
	int heapSize = 0; 	// Size of the array.
	int realSize = 0;	// Number of elements in the heap.

public:
	~MinHeap() {
		delete[] maxHeap;
	}
	MinHeap(int heapSize) {
		this->heapSize = heapSize;
		maxHeap = new T[heapSize + 1];
		// To better track the indices of the binary tree, 
		// we will not use the 0-th element in the array.
		maxHeap[0] = 0;
	}

	void add(T element) {
		realSize++;
		if (realSize > heapSize) {
			realSize--;
			cout << "Too many elements\n";
			return;
		}

		maxHeap[realSize] = element;
		int index = realSize;
		// Index of the parent node of any node is [index of the node / 2].
		// Index of the left child node is [index of the node * 2].
		// Index of the right child node is [index of the node * 2 + 1].
		int parent = index / 2;

		while (maxHeap[index] < maxHeap[parent] && index > 1) {
			swap(maxHeap[index], maxHeap[parent]);
			index = parent;
			parent = index / 2;
		}
	}

	T peek() {
		return maxHeap[1];
	}

	int size() {
		return realSize;
	}

	T pop() {
		if (realSize < 1) {
			cout << "Heap is Empty!\n";
			return '\0';
		}
		else {
			T removedElement = maxHeap[1];
			maxHeap[1] = maxHeap[realSize];
			realSize--;

			int index = 1;
			while (index <= realSize / 2) {
				int left = index * 2;
				int right = (index * 2) + 1;
				if (maxHeap[index] > maxHeap[left] || maxHeap[index] > maxHeap[right]) {
					if (maxHeap[left] < maxHeap[right]) {
						swap(maxHeap[left], maxHeap[index]);
						index = left;
					}
					else {
						swap(maxHeap[right], maxHeap[index]);
						index = right;
					}
				}
				else break;
			}
			return removedElement;
		}
	}
};


int main()
{
	MinHeap<char> minHeapChar(10);

	minHeapChar.add('a');
	minHeapChar.add('b');
	minHeapChar.add('c');
	minHeapChar.add('d');

	cout << "Peek: " << minHeapChar.peek() << endl;
	cout << "pop: " << minHeapChar.pop() << endl;
	cout << "Peek: " << minHeapChar.peek() << endl;

	minHeapChar.add('z');

	cout << "Peek: " << minHeapChar.peek() << endl;
	cout << "pop: " << minHeapChar.pop() << endl;
	cout << "Peek: " << minHeapChar.peek() << endl;

	MinHeap<int> minHeapInt(10);

	minHeapInt.add(1);
	minHeapInt.add(11);
	minHeapInt.add(111);
	minHeapInt.add(1111);

	cout << "Peek: " << minHeapInt.peek() << endl;
	cout << "pop: " << minHeapInt.pop() << endl;
	cout << "Peek: " << minHeapInt.peek() << endl;

	minHeapInt.add(9999);

	cout << "Peek: " << minHeapInt.peek() << endl;
	cout << "pop: " << minHeapInt.pop() << endl;
	cout << "Peek: " << minHeapInt.peek() << endl;

	return 0;
}

#pragma once
#include <vector>

using namespace std;

// This class defines a heap where each node has a
// less or equal value than all child nodes (min-heap)
// Implemented using a vector of integers representing the
// values at each node of a complete binary tree
// Do not modify anything in the class definition

class minHeap {
    private:
        vector<int> heap;
        void siftUp(int pos);
        void siftDown(int pos);
    public:
        minHeap() {} // Default constructor, heap is initiallay an empty vector
        minHeap(vector<int> data) {
            heap = data; // Set private vector to parameter vector
            for (int i = heap.size()-1; i >= 0; i--) {
                siftDown(i); // Sift down each node to maintain min-heap property
            }
        } // Arg constructor, heap is a parameterized vector

        void insert(int value); // Insert value into heap
        int removeMin(); // Removes minimum value
        vector<int> getHeap() {return heap;} //Returns heap data for test cases
};

void minHeap::siftUp(int pos) { // Sift up a node to maintain min-heap property
    int parent = (pos-1) / 2; // Parent of current node
    if (parent >= 0 && heap[pos] < heap[parent]) { // If parent exists and current node is less than parent
        swap(heap[pos], heap[parent]); // Swap current node with parent
        siftUp(parent); // Recursively sift up parent
    }
}

void minHeap::siftDown(int pos) { // Sift down a node to maintain min-heap property
    int left = 2 * pos + 1; // Left child of current node
    int right = 2 * pos + 2; // Right child of current node
    int smallest = pos; // Assume current node is smallest
    if (left < heap.size() && heap[left] < heap[smallest]) { // If left child exists and is less than current node, set smallest to left child
        smallest = left;
    }
    if (right < heap.size() && heap[right] < heap[smallest]) { // If right child exists and is less than current node, set smallest to right child
        smallest = right;
    }
    if (smallest != pos) { // If current node is not smallest
        swap(heap[pos], heap[smallest]); // Swap current node with smallest
        siftDown(smallest); // Recursively sift down smallest
    }
}


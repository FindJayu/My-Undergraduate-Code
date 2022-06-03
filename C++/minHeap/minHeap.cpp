#include <bits/stdc++.h>
#include "minHeap.h"
using namespace std;

void minHeap::insert(int value) {
    heap.push_back(value); // Insert value into heap
    siftUp(heap.size() - 1); // Sift up new node to maintain min-heap property
}

int minHeap::removeMin() {
    int min = heap[0]; // Determine minimum value
    heap[0] = heap[heap.size()-1]; // Swap last node with root
    heap.pop_back(); // Remove last node
    siftDown(0); // Sift down root to maintain min-heap property
    return min; // Return minimum value (popped from back of heap)
}

int main() {

    vector<int> data = {1,4,8,7,11,12,9,16,10,13};
    minHeap heap(data);

    cout << "Heap: ";
    for (int i = 0; i < heap.getHeap().size(); i++) {
        cout << heap.getHeap()[i] << " ";
    }

    cout << "index of parent is: " << floor((5-1)/2) << endl;
    cout << "index of left child is: " << 2*5+1 << endl;
    cout << "index of right child is: " << 2*5+2 << endl;

} // Main function to test heap


// Jack Carson
// CPSC 1070
// Project 3
// 25 October 2021

#include <bits/stdc++.h>
#include "Queue.h"
using namespace std;

/* Returns true if the queue is full (size 100), false otherwise. */
bool Queue::isFull() { 
    return nodeCount == maxSize;
}

/* Returns true if the head of the list is nullptr, which is only true
when the enqueue function has not been used to enter any QueueNode into
the queue, or the queue has been cleared using clearQueue() */
bool Queue::isEmpty() {
    return head == nullptr;
}

/* Uses a temporary queue pointer in a !isEmpty() Queue 
that sets itself to the head Node, and unlinks it from the 
list. Using this method the node data still technically exists
but is unreachable since it has been unlinked from the list. This
property is useful for relinking elements of the queue after they
have been used by the cipher, such that they move to the back of the queue */
int Queue::dequeue(int n) {
    QueueNode *temp = nullptr; 
    if (isEmpty()) {
        cout << "The queue is empty\n";
        return 0;  
    } else {
        n = head->data; 
        temp = head;
        head = head->next; 
        delete temp; 
    }
    nodeCount--; 
    if (nodeCount <= 0) {
        nodeCount == 0; 
    }
    return n; 
}

/* Adds a QueueNode based on the state of the linked list. 
No operation is performed if the nodeCount == 100.
In an empty list, the head is allocated new memory and 
points towards the tail, while the tail is still equal to nullptr. 
In a full list, the head pointer will point to a new 
QueueNode, and set it as the tail */
int Queue::enqueue(int n) {
    if (isFull()) {
        cout << "Queue is full\n";
        return 0;
    }
    if (isEmpty()) {
        head = new QueueNode(n);
        tail = head;
    } else {
        tail->next = new QueueNode(n);
        tail = tail->next;
    }
    nodeCount++; 
    if (nodeCount >= maxSize) {
        nodeCount == 100;
    }
    return n;
}

/* Helper function that iterates through the linked list 
using the list pointers and prints the data between the two
input parameters using a temporary pointer. */
void Queue::printQueue(int start, int end) {
    if (isEmpty()) {
        cout << "The queue is empty\n";
        return;
    }
    if (start > end) {
        cout << "Invalid range\n";
        return;
    }
    if (start < 0 || start > nodeCount) {
        start = 0;
    }
    if (end > nodeCount || end < 0) {
        end = nodeCount;
    }
    QueueNode *temp = head;
    for (int i = 0; i < start; i++) {
        temp = temp->next;
    }
    for (int i = start; i < end; i++) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

/* Performs the same operation as the Queue destructor
by using a temporary pointer to iterate through the list and 
unlink each Node, and then delete the pointers between nodes. */
void Queue::clearQueue() {
    QueueNode *temp = nullptr;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    nodeCount = 0;
} 

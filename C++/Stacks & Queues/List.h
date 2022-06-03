/*
 * Name: Jack Carson
 * Date Submitted: 1/31/22
 * Lab Section: 002
 * Assignment Name: 2121 Lab 1 
*/

#pragma once

#include <iostream>
#include <string>
#include "Node.h"
using namespace std;

// This class represents a linked list of node objects
// Do not modify anything in the class interface
template <class T>
class List {

private:
  Node<T> * start; // Pointer to the first node in this list
  int mySize;  // Size (or length) of this list

public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  // Print the name and this list's size and values to stdout
  // This function is already implemented (no need to change it)
  void print(string name) {
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr) {
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }
}; 

// Construct an empty list by initializig this list's instance variables
template <class T>
List<T>::List() {
  start = nullptr;
  mySize = 0;
}

// Destroy all nodes in this list to prevent memory leaks
template <class T>
List<T>::~List() {}

// Return the size of this list
template <class T>
int List<T>::size() {
  return mySize;
}

// Return true if this list is empty
// Otherwise, return false
template <class T>
bool List<T>::empty() {
  return mySize == 0;
}

// Create a new node with value, and insert that new node
// Into this list at start
template <class T>
void List<T>::insertStart(T value) {
  Node<T> * newNode = new Node<T>(value);
  newNode->next = start;
  start = newNode;
  mySize++;
}

// Create a new node with value, and insert that new node
// Into this list at end
template <class T>
void List<T>::insertEnd(T value) {
  Node<T> * newNode = new Node<T>(value);
  if (empty()) {
    start = newNode;
  }
  else {
    Node<T> * iterator = start;
    while(iterator->next != nullptr) {
      iterator = iterator->next;
    }
    iterator->next = newNode;
  }
  mySize++;
}

// Create a new node with value <value>, and insert that new node at position j
template <class T>
void List<T>::insertAt(T value, int j) {
  if (j < 0 || j > mySize) {
    cout << "Error: index out of bounds" << endl;
  }
  else if (j == 0) {
    insertStart(value);
  }
  else if (j == mySize) {
    insertEnd(value);
  }
  else {
    Node<T> * newNode = new Node<T>(value);
    Node<T> * iterator = start;
    for(int i = 0; i < j - 1; i++) {
      iterator = iterator->next;
    }
    newNode->next = iterator->next;
    iterator->next = newNode;
    mySize++;
  }
}

// Remove node at start
// Make no other changes to list
template <class T>
void List<T>::removeStart() {
  if (empty()) {
    cout << "Error: list is empty" << endl;
  }
  else {
    Node<T> * temp = start;
    start = start->next;
    delete temp;
    mySize--;
  }
}

// Remove node at end
// Make no other changes to list
template <class T>
void List<T>::removeEnd() {
  if(empty()) {
    cout << "Error: list is empty" << endl;
  }
  else if(mySize == 1) {
    delete start;
    start = nullptr;
    mySize--;
  }
  else {
    Node<T> * iterator = start;
    while (iterator->next->next != nullptr){
      iterator = iterator->next;
    }
    delete iterator->next;
    iterator->next = nullptr;
    mySize--;
  }
}

// Remove node at position j
// Make no other changes to list
template <class T>
void List<T>::removeAt(int j) { 
  if (j < 0 || j >= mySize) {
    cout << "Error: index out of bounds" << endl;
  }
  else if (j == 0) {
    removeStart();
  }
  else if (j == mySize - 1) {
    removeEnd();
  }
  else {
    Node<T> * iterator = start;
    for(int i = 0; i < j - 1; i++) {
      iterator = iterator->next;
    }
    Node<T> * temp = iterator->next;
    iterator->next = iterator->next->next;
    delete temp;
    mySize--;
  }
}

// Return the value of the first node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getFirst() {
  if (empty()) {
    return T();
  }
  else {
    return start->value;
  }
}

// Return the value of the last node in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getLast() {
  if (empty()) {
    return T();
  }
  else {
    Node<T> * iterator = start;
    while (iterator->next != nullptr) {
      iterator = iterator->next;
    }
    return iterator->value;
  }
}

// Return the value of the node at position j in the Linked List,
// If no first node, return the default constructed value: T()
template <class T>
T List<T>::getAt(int j) {
  if (j < 0 || j >= mySize) {
    cout << "Error: index out of bounds" << endl;
  }
  else if (j == 0) {
    return getFirst();
  }
  else if (j == mySize - 1) {
    return getLast();
  }
  else {
    Node<T> * iterator = start;
    for(int i = 0; i < j; i++){
      iterator = iterator->next;
    }
    return iterator->value;
  }
}

// Return the position of the (first) node whose value is equal to the key
// Otherwise, return -1
template <class T>
int List<T>::find(T key) {
  if (empty()) {
    return -1;
  }
  else {
    Node<T> * iterator = start;
    int j = 0;
    while (iterator != nullptr) {
      if (iterator->value == key) {
        return j;
      }
      iterator = iterator->next;
      j++;
    }
    return -1;
  }
}

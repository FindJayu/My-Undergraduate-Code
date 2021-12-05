// Jack Carson
// CPSC 1071 - 002
// The Decepticons
// 17 November 2021

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function definitions containing printList()
and makeList() along with helper functions */
int getLength(struct Node*);
void printList(struct Node*);
struct Node* makeList(); 
struct Node* makeNode(char word[100]); 
struct Node* getNode(struct Node*, int);

#endif
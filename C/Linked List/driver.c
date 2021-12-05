// Jack Carson
// CPSC 1071 - 002
// The Decepticons
// 17 November 2021

#include "LinkedList.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
// Create a struct node by calling makeList() returning a struct Node*
struct Node* head = makeList();
// Display the list using helper functions
printList(head);
}
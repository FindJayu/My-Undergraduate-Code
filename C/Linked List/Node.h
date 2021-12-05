// Jack Carson
// CPSC 1071 - 002
// The Decepticons
// 17 November 2021

#ifndef NODE_H
#define NODE_H
#include <stdlib.h>
#include <string.h>

// Node Structure Definition holding a char array of size 100
struct Node {
    char word[100]; 
    struct Node *next;
} Node;

#endif
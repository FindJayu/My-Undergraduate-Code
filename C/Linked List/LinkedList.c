// Jack Carson
// CPSC 1071 - 002
// The Decepticons
// 17 November 2021

#include "LinkedList.h"
#include "Node.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function that iterates the linked list
with a counter variable and returns the size of the linked list */
int getLength(struct Node* head) {
    int count = 0; 
    struct Node* temp = head; 
    while(temp != NULL) {
        count++; 
        temp = temp->next; 
    }
    return count; 
}

/* Prints the list by getting nodes contained in the linked list 
and formatting print statements with the word[] contained in those nodes */
void printList(struct Node* head) {
    int i = getLength(head);
    struct Node* temp = head;
    
    if (i == 1) {
        printf("You've entered the following node: "); 
        printf("%s\n", temp->word);
    }

    if (i == 2) {
        printf("You've entered the following nodes: "); 
        printf("%s and %s\n", getNode(head, 1)->word, getNode(head, 0)->word);
    }

    if (i > 2) {
        printf("You've entered the following nodes: ");  
        while (i > 1) {
            printf("%s, ", getNode(head, i - 1)->word); 
            i--; 
        }
        printf("and %s\n", getNode(head, 0)->word);
    }  
}

/* Prompts the user for input and creates linked list nodes using
the inputted string. makeNode() function used to create each node */
struct Node* makeList() {
    int i = 0; 
    struct Node *head, *temp; 

    while(1) {
        printf("Enter a word or phrase, or -99 to end: "); 
        char word[100];
        fgets(word, 100, stdin);
        if(strcmp(word, "-99\n") == 0) {
            break;
        }

        word[strlen(word) - 1] = '\0';
        temp = makeNode(word); 

        if (i == 0) {
            head = temp; 
        } else {
            temp->next = head; 
            head = temp;
        }
        i++; 
    }
    return head;
}

/* Allocates memory for the size of a node and copies the 
argument into the node word[] */
struct Node* makeNode(char word[100]) {
    struct Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->word, word);
    newNode->next = NULL;
    return newNode;
}

/* Returns the nth node in the list from the head */
struct Node* getNode(struct Node* head, int n) {
    struct Node* temp = head; 
    int i = 0; 
    while(i < n) {
        temp = temp->next; 
        i++; 
    }
    return temp; 
}






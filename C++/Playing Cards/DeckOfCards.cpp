// Jack Carson
// CPSC 1071 - 002
// The Carsonators
// 20 November 2021

#include <bits/stdc++.h>
#include "Card.h"
#include "DeckOfCards.h"
using namespace std;


/* Shuffle function which switches index positions in the vector
deck as it iterates through the vector. Temporary card object is used
to hold the data of the [i]th card in the vector, and swaps with a randomly
chosen card in the vector. Using this approach, Card objects may also be 
swapped more than once, or not at all during an iteration. */
void DeckOfCards::shuffle() {
    srand(time(NULL));

    for (int i = 0; i <= 51; i++) {
        Card temp = deck[i]; 
        int x = (rand() % 52);
        deck[i] = deck[x]; 
        deck[x] = temp; 
    }
}

/* Using the private int currentCard as a pseudo-counter, returns
the current card in the deck after the arg constructor initializes 
currentCard to zero (In the case a deck is constructed). Uses postincrement
to add to the current card count after returning the card, and returns 
"No more cards" if the 52nd index of deck is accessed (Has no card object). */
Card DeckOfCards::dealCard() {
    if (currentCard >= 52) {
        cout << "No more cards in the deck";
    }
    else {
        return deck[currentCard++]; 
    }
    return deck[0];
} 

/* Returns true if the counter variable currentCard has reached
the "Bottom" of the deck of cards, and false otherwise. */
bool DeckOfCards::moreCards() {
    return (currentCard < 52); 
} 

/* Extra function using a for loop and toString() in order to 
print out all the cards contained in the deck */
void DeckOfCards::printDeck() {
    for (int i = 0; i < 52; i++) {
        cout << deck[i].toString(); 
    }
}

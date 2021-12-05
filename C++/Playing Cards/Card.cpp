// Jack Carson
// CPSC 1071 - 002
// The Carsonators
// 20 November 2021

#include <bits/stdc++.h>
#include "Card.h"
using namespace std;

/* const arrays with values after being declared private in Card.h
contain strings that will be used for concatenation into display values
such as "Seven of Spades" using the toString function. */
const string Card::Suits[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
const string Card::Faces[13] = {"Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

/* toString that uses auxiliary returnFace() and returnSuit()
functions to concatenate a printed string */
string Card::toString() {
    string s = returnFace() + " of " + returnSuit();
    return s;
}

/* Switches private int Suit from the calling object
and returns the index of the Suits[] array */
string Card::returnSuit() {
    switch (Suit) {
        case 0 : return Suits[0];
            break;
        case 1 : return Suits[1];
            break;
        case 2 : return Suits[2];
            break;
        case 3 : return Suits[3];
            break;
        default : cout << "Invalid Suit";
            break;
    }
    return "";
}

/* Switches private int Face from the calling object
and returns the index of the Faces[] array */
string Card::returnFace() {
    switch (Face) {
        case 0 : return Faces[0];
            break;
        case 1 : return Faces[1];
            break;
        case 2 : return Faces[2];
            break;
        case 3 : return Faces[3];
            break;
        case 4 : return Faces[4];
            break;
        case 5 : return Faces[5];
            break;
        case 6 : return Faces[6];
            break;
        case 7 : return Faces[7];
            break;
        case 8 : return Faces[8];
            break;
        case 9 : return Faces[9];
            break;
        case 10 : return Faces[10];
            break;
        case 11 : return Faces[11];
            break;
        case 12 : return Faces[12];
            break;
        default : cout << "Invalid Face";
            break;
    }
    return "";
}

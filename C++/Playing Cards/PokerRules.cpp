// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

#include <bits/stdc++.h>
#include "PokerRules.h"
#include "AnalyzeHand.h"
using namespace std;

/* Iterates the vector 10 times, and swaps items if the preceding element is greater than the postceding element*/
std::vector<Card> PokerRules::sortHand() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0, k = 1; k < Hand.size(); j++, k++) {
            if (Hand[j].getFace() > Hand[k].getFace()) {
                Card temp = Hand[j];
                Hand[j] = Hand[k];
                Hand[k] = temp;
            }
        }
    }
    return Hand;
}

/* Returns true if any hand condition is true */
bool PokerRules::isWon() {
    if (pair()||twoPairs()||threeOfAKind()||fourOfAKind()||straight()||flush()) {
        return true;
    } 
    return false;
}

/* Returns true if two adjacent sorted items are equal to one another*/
bool PokerRules::pair() {
    sortHand();
    for (int i = 0, j = 1; j < Hand.size(); i++, j++) {
        if (Hand[i].getFace() == Hand[j].getFace()) {
            return true;
        }
    }
    return false;
}

/* Returns true if two adjacent sorted items are equal to one another and the next two are equal to one another*/
bool PokerRules::twoPairs() {
    sortHand();
    int pairCount = 0;
    for (int i = 0, j = 1, k = 2; j < Hand.size(); i++, j++, k++) {
        if (Hand[i].getFace() == Hand[j].getFace()) {
            if (Hand[i].getFace() == Hand[k].getFace()) {
                i = j;
                j = k;
            }
            pairCount++;
        }
    }
    if (pairCount == 2) {
        return true;
    }
    return false;
}

/* Returns true if three adjacent sorted items are equal to one another*/
bool PokerRules::threeOfAKind() {
    sortHand(); 
    for (int i = 0, j = 1, k = 2; k < Hand.size(); i++, j++, k++) {
        if (Hand[i].getFace() == Hand[j].getFace() && Hand[i].getFace() == Hand[k].getFace()) {
            return true;
        }
    }
    return false; 
}

/* Returns true if four adjacent sorted items are equal to one another*/
bool PokerRules::fourOfAKind() {
    sortHand(); 
    for (int i = 0, j = 1, k = 2, l = 3; l < Hand.size(); i++, j++, k++, l++) {
        if (Hand[i].getFace() == Hand[j].getFace() && Hand[i].getFace() == Hand[k].getFace() && Hand[i].getFace() == Hand[l].getFace()) {
            return true;
        }
    }
    return false; 
}

/* Returns true if all items are consecutive in regards to face integers*/
bool PokerRules::straight() {
    sortHand();
    for (int i = 0, j = 1; j < Hand.size(); i++, j++) {
        if (Hand[i].getFace() + 1 != Hand[j].getFace()) {
            return false;
        }
    }
    return true;
}

/* Returns true if all items are the same suit*/
bool PokerRules::flush() {
    sortHand();
    for (int i = 0, j = 1; j < Hand.size(); i++, j++) {
        if (Hand[i].getSuit() != Hand[j].getSuit()) {
            return false;
        }
    }
    return true;
}


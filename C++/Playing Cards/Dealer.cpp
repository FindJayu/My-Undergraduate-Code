// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

#include <bits/stdc++.h>
#include "PokerRules.h"
#include "BlackjackRules.h"
#include "AnalyzeHand.h"
using namespace std;

/* main with parameters allowing 0 or 1 to be passed as arguments*/
int main(int argc, char* argv[]) {
    cout << "\n";
    if (argc == 1) {
        exit(1); 
    }
    else if (argv[1][0] == '0') { 
        vector<Card> bHand; 
        bHand.push_back(Card(0, 0));
        bHand.push_back(Card(11, 0));
        bHand.push_back(Card(10, 0));
        BlackjackRules game(bHand); 

        /*String Formatting and checking the vector bHand to determine if the hand is winning*/
        cout << "******* Welcome to Blackjack Rules *******\n" << endl;
        cout << "We are checking the Hand:\n"; 
        cout << game.toString() << endl; 
        cout << "...Checking\n";
        if(game.isWon()) {
            cout << "\nThis is a Winning hand!\n"; 
        } 
    }
    else if (argv[1][0] == '1') { 
        vector<Card> pHand;
        pHand.push_back(Card(1, 0));
        pHand.push_back(Card(10, 0));
        pHand.push_back(Card(11, 0));
        pHand.push_back(Card(8, 0));
        pHand.push_back(Card(1, 1));
        PokerRules game(pHand);

        /*String Formatting and checking the vector pHand to determine if the hand is winning*/
        cout << "******* Welcome to Poker Rules *******\n" << endl;
        cout << "We are checking the Hand:\n"; 
        cout << game.toString() << endl;
        cout << "...Checking\n";
        if(game.isWon()) {
            cout << "\nThis is a Winning hand!\n"; 
        } 
    }
}


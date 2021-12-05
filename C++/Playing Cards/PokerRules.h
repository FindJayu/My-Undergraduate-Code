// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

# ifndef POKER_RULES
# define POKER_RULES
# include "AnalyzeHand.h"
#include <bits/stdc++.h>

/* PokerRules inherits the arg constructor of AnalyzeHand*/
class PokerRules : public AnalyzeHand { 
    public:
        PokerRules(std::vector<Card> v) : AnalyzeHand(v) {};

        /* Declares functions, and provides getter functions*/
        bool isWon();
        bool pair(); 
        bool twoPairs(); 
        bool threeOfAKind(); 
        bool fourOfAKind(); 
        bool straight(); 
        bool flush(); 

        std::vector<Card> sortHand();
        int getNumOfCards() {return numOfCards;}
        std::vector<Card> getHand() {return Hand;}
};

# endif
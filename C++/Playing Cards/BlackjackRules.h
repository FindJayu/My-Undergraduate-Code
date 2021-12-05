// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

# ifndef BLACKJACK_RULES
# define BLACKJACK_RULES
# include "AnalyzeHand.h"
#include <bits/stdc++.h>

/* BlackjackRules inherits the arg constructor from AnalyzeHand*/
class BlackjackRules : public AnalyzeHand { 
    public:
        BlackjackRules(std::vector<Card> v) : AnalyzeHand(v) {};
        
        /* Provided getter functions, and declaration of pure virtual isWon()*/
        bool isWon(); 
        int getNumOfCards() {return numOfCards;}
        std::vector<Card> getHand() {return Hand;}
};

# endif

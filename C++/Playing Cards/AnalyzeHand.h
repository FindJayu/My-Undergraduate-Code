// Jack Carson
// CPSC 1070
// CoLab 5C
// 3 November 2021

# ifndef ANALYZE_HAND
# define ANALYZE_HAND
# include "Card.h"
#include <bits/stdc++.h>

/* Abstract AnalyzeHand that assigns the number of cards and vector*/
class AnalyzeHand : public Card {
    protected:       
        int numOfCards; 
        std::vector<Card> Hand;
    public: 
        AnalyzeHand(std::vector<Card> v) {
            this->numOfCards = v.size();
            this->Hand = v;
        };

        std::string toString(); 
        virtual bool isWon() = 0; 
}; 

# endif

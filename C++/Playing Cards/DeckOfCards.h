// Jack Carson
// CPSC 1071 - 002
// The Carsonators
// 20 November 2021

# ifndef DECKOFCARDS_H
# define DECKOFCARDS_H
#include "Card.h"
#include <vector>

// DeckOfCards inherits data and functions from class Card (Parent Class)
class DeckOfCards : public Card {
    private:
        /* Creates private vector deck containing Card objects, and
        the int currentCard used as a pseudo-counter variable for cards
        in the deck, and checking if Card objects still remain in the vector
        without removing them from the vector. */
        std::vector<Card>deck; 
        int currentCard;
    public:
        /* DeckOfCards constructor using enumerated types and nested for loops
        in order to fill the deck vector with 52 cards by face first, then suit
        (All Cards with the Hearts suit will be pushed into the array first). Also
        assigns the currentCard to zero to represent that no cards have been "dealt". */
        DeckOfCards() {  
        currentCard = 0; 
   	    for (int suit = Card::Hearts; suit <= Card::Spades; suit++) {
            for (int face = Card::Ace; face <= Card::King; face++) {
                deck.push_back(Card(face, suit));
            }        
        }
    }

        // Functions in class DeckOfCards are declared
        void shuffle(); 
        bool moreCards(); 
        void printDeck(); 
        Card dealCard();
};

# endif
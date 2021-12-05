// Jack Carson
// CPSC 1071 - 002
// The Carsonators
// 20 November 2021

# ifndef CARD_H
# define CARD_H
#include <string>

class Card {
    private:
        /* Initializes int(s) Suit and Face along with
        const string arrays Suits[] and Faces[] */
        int Suit; 
        int Face;
        const static std::string Suits[4];
        const static std::string Faces[13];
    public:
        /* enumerated SUIT and FACE data types used to
        initialize Deck of Card objects in DeckOfCards.h */
        enum SUIT {Hearts, Diamonds, Clubs, Spades};
        enum FACE {Ace, Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King};

        // Card No-Arg and Arg Constructors
        Card() {};
        Card(int Face, int Suit) {
            this->Face = Face;
            this->Suit = Suit; 
        };

        // Declaration of functions used together to print card object details in string format
        std::string toString(); 
        std::string returnSuit(); 
        std::string returnFace();
        int getFace() {return Face;}
        int getSuit() {return Suit;}

}; 

# endif
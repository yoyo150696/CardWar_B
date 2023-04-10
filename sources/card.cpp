#include "card.hpp"
namespace ariel{
    Card::Card(Suit suit,Rank rank){
        this->suit = suit;
        this->rank = rank;
    }
    int Card::val(){
        int v = rank;
        return v;
    }
    std::string Card::to_string() {
    std::string result;

    switch (rank) {
        case TWO:
            result = "2";
            break;
        case THREE:
            result = "3";
            break;
        case FOUR:
            result = "4";
            break;
        case FIVE:
            result = "5";
            break;
        case SIX:
            result = "6";
            break;
        case SEVEN:
            result = "7";
            break;
        case EIGHT:
            result = "8";
            break;
        case NINE:
            result = "9";
            break;
        case TEN:
            result = "10";
            break;
        case JACK:
            result = "Jack";
            break;
        case QUEEN:
            result = "Queen";
            break;
        case KING:
            result = "King";
            break;
        case ACE:
            result = "Ace";
            break;    
    }

    switch (suit) {
        case HEARTS:
            result += " of Hearts";
            break;
        case DIAMONDS:
            result += " of Diamonds";
            break;
        case CLUBS:
            result += " of Clubs";
            break;
        case SPADES:
            result += " of Spades";
            break;
    }

    return result;
}
    
}
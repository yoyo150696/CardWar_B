#pragma once
#include <string>
namespace ariel{
enum Rank { TWO = 2, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING,ACE };
enum Suit { HEARTS, DIAMONDS, CLUBS, SPADES };
class Card{
    Suit suit;
    Rank rank;
    public:
        Card(Suit s,Rank r);
        int val();
        std::string to_string();
    };
}
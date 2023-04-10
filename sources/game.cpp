#include "game.hpp"
#include <iostream>

namespace ariel{
    
    Game::Game(Player &first,Player &second):p1(first),p2(second){
        p1 = first;
        p2 = second;
        init_deck();
        deal();
        for (Card i : p1.pdeck) {
            std::cout << i.val() << " ";
        }
        std::cout<< std::endl <<"sec"<< std::endl;
        for (Card i : p2.pdeck) {
            std::cout << i.val() << " ";
        }
        p1.size = 26;
        p2.size = 26;
        if (&first == &second){
            this->p1.size = -1;
            this->p2.size = -1;
            throw ( "both are the smae player" );
        }
        
    }
    void Game::init_deck(){
        for (int rank = TWO; rank <= ACE; rank++) {
            for (int suit = HEARTS; suit <= SPADES; suit++) {
                deck.push_back({ static_cast<Suit>(suit), static_cast<Rank>(rank) });
            }
        }
        random_shuffle(deck.begin(), deck.end());
    }

    void Game::deal(){
        
        for (int i = 0; i < 26; i++) {
            p1.pdeck.push_back(deck.back());
            deck.pop_back();
            p2.pdeck.push_back(deck.back());
            deck.pop_back();
        }
    }

    void Game::playAll(){
        while (p1.size>0)
        {
            playTurn();
        }
        
    }
    void Game::turn(int cards_sum){
        lt += (" " + p1.name + " played " + p1.pdeck.back().to_string() + " " + p2.name +
         " played " + p2.pdeck.back().to_string() + ".");
        if(p1.pdeck.back().val()> p2.pdeck.back().val()){
            if(p1.pdeck.back().val()== ACE && p2.pdeck.back().val())
                p2.card_taken += (cards_sum + 2);
            else    
                p1.card_taken += (cards_sum + 2);
            p1.pdeck.pop_back();
            p2.pdeck.pop_back();
        }
        else if (p1.pdeck.back().val() < p2.pdeck.back().val())
        {
            if(p2.pdeck.back().val()== ACE && p1.pdeck.back().val())
                p1.card_taken += (cards_sum + 2);
            else    
                p2.card_taken += (cards_sum + 2);
            p2.card_taken += (cards_sum + 2);
            p1.pdeck.pop_back();
            p2.pdeck.pop_back();
        }
        else
        {
            lt += " Draw.";
            if(p1.pdeck.size() > 2)
            {
                p1.size--;
                p2.size--;
                p1.pdeck.pop_back();
                p2.pdeck.pop_back();
                turn(cards_sum + 2);
            }
            else{
                p1.card_taken += (cards_sum/2);
                p2.card_taken += (cards_sum/2);
            }
        }

    }
    void Game::playTurn(){
        lt = "";
        p1.size--;
        p2.size--;
        turn(0);
        
    }
    void Game::printLastTurn(){
        std::cout << lt;
    }
    void Game::printLog(){}
    void Game::printStats(){}
    void Game::printWiner(){}
    
}
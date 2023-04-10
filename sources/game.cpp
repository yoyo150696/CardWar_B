#include "game.hpp"
#include <iostream>
#include <random>
namespace ariel{
    
    Game::Game(Player &first,Player &second):p1(first),p2(second){
        
        init_deck();
        deal();
        p1 = first;
        p2 = second;
        draws = 0;
        p1.size = 26;
        p2.size = 26;
        if (first.name == second.name){
            this->p1.size = -1;
            this->p2.size = -1;
        }
        
    }
    void Game::init_deck(){
        for (int rank = TWO; rank <= ACE; rank++) {
            for (int suit = HEARTS; suit <= SPADES; suit++) {
                deck.push_back({ static_cast<Suit>(suit), static_cast<Rank>(rank) });
            }
        }
        std::random_device rd;
        std::mt19937 g(rd());
        std::shuffle(deck.begin(), deck.end(), g);
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
        std::string st = (" " + p1.name + " played " + p1.pdeck.back().to_string() + " " + p2.name +
         " played " + p2.pdeck.back().to_string() + ".");
        lt += st;
        log += (st + '\n');
        if(p1.pdeck.back().val()> p2.pdeck.back().val()){
            if(p1.pdeck.back().val()== ACE && p2.pdeck.back().val()){
                p2.card_taken += (cards_sum + 2);
                p2.wins++;}
            else{
                p1.card_taken += (cards_sum + 2);
                p1.wins++;} 
            p1.pdeck.pop_back();
            p2.pdeck.pop_back();}
        else if (p1.pdeck.back().val() < p2.pdeck.back().val()){
            if(p2.pdeck.back().val()== ACE && p1.pdeck.back().val()){
                p1.card_taken += (cards_sum + 2);
                p1.wins++;}
            else{
                p2.card_taken += (cards_sum + 2);
                p2.wins++;}
            p1.pdeck.pop_back();
            p2.pdeck.pop_back();
        }
        else
        {
            lt += " Draw.";
            draws++;
            if(p1.pdeck.size() > 1)
            {
                p1.size--;
                p2.size--;
                p1.pdeck.pop_back();
                p2.pdeck.pop_back();
                turn(cards_sum + 2);
            }
            else{
                p1.card_taken += ((cards_sum + 2)/2);
                p2.card_taken += ((cards_sum + 2)/2);
            }
        }

    }
    void Game::playTurn(){
        if(p1.size == -1)
            throw ( "both are the smae player" );
        else if(p1.size == 0)
            throw("Game is over!");
        else{    
            lt = "";
            p1.size--;
            p2.size--;
            turn(0);}
        
    }
    void Game::printLastTurn(){
        std::cout << lt;
    }
    void Game::printLog(){
        std::cout << log;
    }
    void Game::printStats(){
        double fwr = (p1.wins/26*100);
        double swr = (p2.wins/26*100);
        double dr = (draws/26*100);
        std::cout << p1.name << " stats: win rate - " << fwr << "% cards won - "<< p1.card_taken<< std::endl;
        std::cout << p2.name << " stats: win rate - " << swr << "% cards won - "<< p2.card_taken<< std::endl;
        std::cout << "draws rate - " << dr << " draws num - " << draws << std::endl;
    }

    void Game::printWiner(){
        if(p1.card_taken > p2.card_taken)
            std::cout << p1.name << std::endl;
        if(p1.card_taken < p2.card_taken)
            std::cout << p2.name << std::endl;
        if(p1.card_taken == p2.card_taken)
            throw("Draw");

    }
    
}
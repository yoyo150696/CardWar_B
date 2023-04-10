#include "player.hpp"
namespace ariel{
    Player::Player(std::string st){
        name = st;
        size = 0;
        card_taken = 0;
    }
    int Player::cardesTaken(){
        return card_taken;
        
    }
    int Player::stacksize(){
        return size;
    }

}
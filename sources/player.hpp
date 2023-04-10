#pragma once
#include <vector>
#include <string>
#include "card.hpp"
namespace ariel{
    class Player{
        public:
            std::string name;
            int size;
            double wins;
            int card_taken;
            std::vector<Card> pdeck;
            Player(std::string player_name);
            Player();
            int stacksize();

            int cardesTaken();

    };
}
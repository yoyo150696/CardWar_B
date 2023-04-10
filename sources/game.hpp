#include "player.hpp"
#include <vector>
#include <string>
namespace ariel{

    class Game{
        private:
            std::vector<Card> deck;
            void init_deck();
            void deal();
            std::string lt;
            std::string log;
            double draws;
            Player &p1;
            Player &p2;
        public:
            
            Game(Player &first,Player &second);
            void turn(int cards_sum);
            void playTurn();
            void printLastTurn();
            void playAll();
            void printWiner();
            void printLog();
            void printStats();
    };
}
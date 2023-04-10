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
        public:
            Player &p1;
            Player &p2;
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
#include <string>
#include <vector>

#pragma once
using namespace std;

namespace coup{
    class Player;
    class Game{
        public:
            Game();
            void addPlayer(Player &player);
            vector<string> players();
            string turn();
            string winner();
            int numberOfPlayers() const;
            void finishTurn();
            bool started;

        protected:
            vector<string> playersNames;
            vector<Player*> playersList;
            uint currentPlayer;
            int numOfPlayers;
        
    };
}
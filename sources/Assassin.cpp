#include <string>
#include "Player.hpp"
#include "Assassin.hpp"
#include <map>

const int coupAmount = 7;
const int assasination = 3;

namespace coup
{

    Assassin::Assassin(Game &game,const string &name) : Player(game, name)
    {
        playerRole = "Assassin";
    }

    string Assassin::role()
    {
        return playerRole;
    }

    void Assassin::coup(Player &player)
    {
        if (this->game->turn() != this->name)
        {
            throw "It's not your turn";
        }
        if (this->coinsAmount < 3)
        {
            throw "You don't have enough coins";
        }
        if (player.isCouped())
        {
            throw "Player is already couped";
        }
        player.setCouped();
        if (this->coinsAmount < coupAmount)
        {
            this->coinsAmount -= 3;
            this->map = {{"assasination", &player}};
        }
        else
        {
            this->coinsAmount -= coupAmount;
            this->map = {{"coup", &player}};
        }

        this->game->finishTurn();
    }
}
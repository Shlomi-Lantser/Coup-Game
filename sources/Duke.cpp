#include <string>
#include "Player.hpp"
#include "Duke.hpp"

const int HaveToCoup = 10;

namespace coup
{
    Duke::Duke(Game &game,const string &name) : Player(game, name)
    {
        playerRole = "Duke";
    }

    string Duke::role()
    {
        return playerRole;
    }

    void Duke::tax()
    {
        if (this->game->turn() != this->name)
        {
            throw "It's not your turn";
        }
        if (this->Couped)
        {
            throw "You are couped";
        }
        if (this->coinsAmount > HaveToCoup)
        {
            throw "You must coup !";
        }
        this->game->started = true;
        this->coinsAmount += 3;
        this->game->finishTurn();
    }

    void Duke::block(Player &player)
    {
        if (player.isCouped())
        {
            throw "Player is couped";
        }
        if (player.map.empty())
        {
            throw "Player didnt forgtn aid";
        }
        player.decreaseCoins(2);
        player.map.erase("foreign_aid");
    }
}
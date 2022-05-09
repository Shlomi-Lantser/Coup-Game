#include <string>
#include "Player.hpp"
#include "Ambassador.hpp"

namespace coup
{

    Ambassador::Ambassador(Game &game,const string &name) : Player(game, name)
    {
        playerRole = "Ambassador";
    }

    string Ambassador::role()
    {
        return playerRole;
    }

    void Ambassador::coup(Player &player)
    {
        Player::coup(player);
    }

    void Ambassador::transfer(Player &src, Player &dest)
    {
        if (this->game->turn() != this->name)
        {
            throw "It's not your turn";
        }
        if (src.coins() < 1)
        {
            throw "Player doesn't have enough coins";
        }
        src.decreaseCoins(1);
        dest.increaseCoins(1);
        this->game->finishTurn();
    }

    void Ambassador::block(Player &player)
    { // TODO: block coup
        if (player.role() != "Captain")
        {
            throw "Player is not a Captain";
        }
        if (player.map.empty())
        {
            throw "Player hasn't blockable actions";
        }
        // bool something = (player.map.count("steal1") > 0);
        if (player.map.count("steal1") > 0){
            player.decreaseCoins(1);
            player.map.find("steal1")->second->increaseCoins(1);
        }else if (player.map.count("steal2") > 0){
            player.decreaseCoins(2);
            player.map.find("steal2")->second->increaseCoins(2);
        }
       
    }
}
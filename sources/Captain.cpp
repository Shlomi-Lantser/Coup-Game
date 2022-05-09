#include <string>
#include "Player.hpp"
#include "Captain.hpp"
#include <iostream>

namespace coup{

    Captain::Captain(Game &game,const string &name) : Player(game, name){
        playerRole = "Captain";
    }

    string Captain::role(){
        return playerRole;
    }

    void Captain::block(Player &player){
        if (player.role() != "Captain"){
            throw "Player is not a Captain";
        }if (player.map.empty()){
            throw "Player hasn't blockable actions";
        }if (player.map.count("steal1") > 0){
            player.decreaseCoins(1);
            player.map.find("steal1")->second->increaseCoins(1);
        }else if (player.map.count("steal2") > 0){
            player.decreaseCoins(2);
            player.map.find("steal2")->second->increaseCoins(2);
        }
    }

    void Captain::steal(Player &player){
        if (this->game->turn() != this->name){
            throw "It's not your turn";
        }
        if (player.coins() == 0){
            throw "Player doesn't have enough coins";
        }if (player.coins() == 1){
            player.decreaseCoins(1);
            this->increaseCoins(1);
            this->map = {{"steal1", &player}};
        }else if (this->coinsAmount >= 2){
            player.decreaseCoins(2);
            this->increaseCoins(2);
            this->map = {{"steal2", &player}};
        }
        this->game->finishTurn();
    }
}
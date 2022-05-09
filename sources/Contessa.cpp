#include <string>
#include "Player.hpp"
#include "Contessa.hpp"
#include <map>
#include <iostream>

namespace coup{

    Contessa::Contessa(Game &game,const string &name) : Player(game, name){
        playerRole = "Contessa";
    }

    string Contessa::role(){
        return playerRole;
    }

    void Contessa::block(Player &player){ //TODO: block assassination
        if (player.map.count("coup") == 1){
            throw "Didnt assassinate";
        }
        if (player.role() == "Assassin" && player.map.count("assasination") > 0 ){
        player.map.find("assasination")->second->removeCouped();
        }
        else if (player.map.empty()){
            throw "Assasin didnt coup a player.";
        }else{
            throw "Player is not an Assassin";
        }
    }

}

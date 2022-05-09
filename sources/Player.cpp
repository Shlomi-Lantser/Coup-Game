#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"

using namespace std;

const int maxPlayers = 6;
const int minPlayers = 2;
const int HaveToCoup = 10;
const int coupAmount =7;

namespace coup
{

    Player::Player(Game &game,const string &name)
    {   
        if (game.numberOfPlayers() >= maxPlayers){
            cout << "TEST"<<endl;
            throw std::runtime_error("Maximum number of players reached");
        }
        this->game = &game;
        this->name = name;
        this->coinsAmount = 0;
        this->Couped = false;
        game.addPlayer(*this);
    }

    
    string Player::getName()
    {
        return this->name;
    }

    void Player::income()
    {
        if (this->game->numberOfPlayers() < minPlayers){
            throw "Not enough players";
        }
        if (this->coinsAmount > HaveToCoup){
            throw "You must coup !";
        }
        if (this->game->turn() != this->name){
            throw "It's not your turn";
        }
        this->game->started = true;
        this->coinsAmount++;
        this->game->finishTurn();
    }

    void Player::foreign_aid()
    {
        this->game->started = true;
        if (this->game->numberOfPlayers() <2){
            throw "Not enough players";
        }
        if (this->game->turn() != this->name){
            throw "It's not your turn";
        }
        if (this->coinsAmount > HaveToCoup){
            throw "You must coup !";
        }
        this->coinsAmount += 2;
        this->game->finishTurn();
        this->map = {{"foreign_aid", this}};
    }

    void Player::coup(Player &player)
    {
        if (this->game->numberOfPlayers() <2){
            throw "Not enough players";
        }
        if (this->game->turn() != this->name){
            throw "It's not your turn";
        }if (player.isCouped()){
            throw "Player is couped";
        }
        if (this->coins() < coupAmount){
            throw "Player doesn't have enough coins";
        }
        player.setCouped();
        this->game->finishTurn();
        this->coinsAmount -= coupAmount;
    }

    bool Player::isCouped() const
    {
        return this->Couped;
    }

    void Player::setRole() //TODO: set role
    {
        
    }

    int Player::coins() const
    {
        return this->coinsAmount;
    }

    void Player::setCouped()
    {
        this->Couped = true;
    }

    void Player::removeCouped()
    {
        this->Couped = false;

    }

    void Player::increaseCoins(int amount)
    {
        this->coinsAmount += amount;
    }

    void Player::decreaseCoins(int amount)
    {
        this->coinsAmount -= amount;
    }
}
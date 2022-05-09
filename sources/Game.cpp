#include <iostream>
#include <string>
#include <vector>
#include "Player.hpp"
#include "Game.hpp"

using namespace std;

const int MAX_PLAYERS = 6;

namespace coup
{
    Game::Game()
    {
        currentPlayer = 0;
        numOfPlayers = 0;
        this->playersList = vector<Player *>();
        this->started = false;
    }

    void Game::addPlayer(Player &player)
    {
        if (this->started)
        {
            throw "Game already started";
        }
        if (this->playersList.size() >= MAX_PLAYERS)
        {
            throw "Maximum number of players reached";
        }
        this->playersNames.push_back(player.getName());
        this->playersList.push_back(&player);
        this->numOfPlayers++;
    }

    int Game::numberOfPlayers() const
    {
        return this->numOfPlayers;
    }

    vector<string> Game::players()
    {
        playersNames = vector<string>();
        for (uint i = 0; i < this->playersList.size(); i++)
        {
            if (!this->playersList[i]->isCouped()){
                this->playersNames.push_back(this->playersList[i]->getName());
            }
        }
        return playersNames;
    }

    string Game::turn()
    {
        this->playersList[currentPlayer]->map.clear();
        return this->playersList[this->currentPlayer]->getName();
    }

    string Game::winner()
    {
        if (this->players().size() > 1)
        {
            throw "Game still in progress";
        }if (!this->started){
            throw "Game not started";
        }
        return this->players()[0];
    }

    void Game::finishTurn()
    {
        this->currentPlayer = (this->currentPlayer + 1) % this->playersList.size();
        while (this->playersList[this->currentPlayer]->isCouped())
        {
            this->currentPlayer = (this->currentPlayer + 1) % this->playersList.size();
        }
    }
}
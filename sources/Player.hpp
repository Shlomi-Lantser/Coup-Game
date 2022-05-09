#include <vector>
#include "Game.hpp"
#include <map>

#pragma once
using namespace std;

namespace coup
{
    class Player
    {
    public:
        Player(Game &game,const string &name);
        virtual ~Player() = default;
        virtual string role() = 0;
        virtual void coup(Player &player);
        virtual void income();
        virtual void foreign_aid();
        string getName();
        int coins() const;
        void setRole();
        bool isCouped() const;
        void setCouped();
        void removeCouped();
        void increaseCoins(int amount);
        void decreaseCoins(int amount);
        map<string, Player *> map;

    protected:
        Game *game;
        string name;
        string playeRole;
        int coinsAmount;
        bool Couped;
    };
}
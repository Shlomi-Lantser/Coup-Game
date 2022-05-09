#include <string>
#include "Player.hpp"

namespace coup{
    class Assassin : public Player{
        public:
            Assassin(Game &game,const string &name);
            string role() override;
            void coup(Player &player) override; //Can coup with 3 coins.

        protected:
            string playerRole;

    };
}
#include <string>
#include "Player.hpp"

namespace coup{
    class Captain : public Player{
        public:
            Captain(Game &game,const string &name);
            string role();
            void steal(Player &player);
            void static block(Player &player);

        protected:
            string playerRole;
    };
}
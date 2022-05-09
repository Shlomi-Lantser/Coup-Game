#include <string>
#include "Player.hpp"

namespace coup{
    class Contessa : public Player{

        public:
            Contessa(Game &game,const string &name);
            string role();
            void static block(Player &player);

        protected:
            string playerRole;

    };
}


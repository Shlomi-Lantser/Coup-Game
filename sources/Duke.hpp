#include <string>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Duke : public Player{
        public:
            Duke(Game &game,const string &name);
            string role();
            void tax();
            void static block(Player &player);

        protected:
            string playerRole;
    };
}
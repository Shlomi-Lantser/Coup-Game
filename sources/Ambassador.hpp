#include <string>
#include "Player.hpp"

using namespace std;

namespace coup{
    class Ambassador : public Player{
        public:
            Ambassador(Game &game,const string &name);
            string role();
            void coup(Player &player);
            void transfer(Player &src , Player &dest);
            void static block(Player &player);

        private:
            string playerRole;
    };

}
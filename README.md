# Coup Game C++

![image](https://user-images.githubusercontent.com/92504985/167398468-c3ae3f0d-3403-4d31-997e-d7663622d0bc.png)


# Description
Implementation of the game coup , coup game including 2-6 players that plays against each other , the last who survive wins.
This project including few classes:
* Game
* Player
* Duke
* Assassin
* Ambassador
* Captain
* Contessa

# Game description:
Attributes :
* vector<string> playersNames - Vector of the name of the non couped players.
* vector<Player*> playersList - Vector of the players that joined the game (Couped and uncouped).
* currentPlayer - integer that helps us to know who playing right now (who's turn).
* numOfPlayers - unsigned integer that indecate how many players in the game.
* started - boolean that determinate if the game has been started.

Methods:
* `addPlayer(Player &player)` - Adding the given player to the game (Cannot be added if the game has been started.)
* `players()` - returns the active players data structor.
* `turn()` - returns the name of the player who playing right now.
* `winner()` - returns the winner name only if the game is over.
* `int numberOfPlayers()` - return the number of players.
* `finishTurn()` - promoting the turn index.

# Player description:
Attributes :
* string name - the name of the player.
* Game game - the game that the player joined.
* coinsAmount - amount of the player coins.
* couped - boolean to check if the player is alive.
* map<string , Player*> - The last blockable action that this player did. 

Methods:
* `income` - recieving 1 coin from the treasury
* `foreign_aid` - receiving 2 coins from the treasury (that action can be blocked by duke)
* `coup(Player &player)` - to "kill" given player.

# Roles and abillities:
* **Duke** - Can take tax of 3 coins from the treasury , this action cannot be blocked by no one in addition the duke could block foreign_aid from every player.
* **Assasin** - Can assisinate (coup) every player for 3 coins intead of 7 , this action can be blocked by Contessa role.
* **Ambassador** - Can transfer one coin from player to player , in addition Ambassador can block steal action (Captain action).
* **Captain** - Can steal 2 coins from other player , this action can be blocked by other Captain or Ambassador.
* **Contessa** - Can block the assasinate (Assasin action).


# Rules:

In the beggining of the game every player that joined the game will get a random role every role has it owns abillities 
the goal of the game its to coup all the players around with coins and strategy actions with them.
* If player has 10 coins in the beggining of his turn he must coup someone.
* Blocking doesnt need to be in the player's turn (could do it everytime) and doesnt spending turn.
* Turns will be determinate following the join order.
        
                 

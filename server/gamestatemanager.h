#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "gamestate.h"
#include "QJsonDocument"

class GameStateManager
{
public:
    GameStateManager();
    size_t serialize(QJsonDocument &json);
    void deSerialize(QJsonDocument &json);

   GameState* getGamestate();
   void setGameState(GameState* gameState);


private:
   GameState* gameState;

};

#endif // GAMESTATEMANAGER_H

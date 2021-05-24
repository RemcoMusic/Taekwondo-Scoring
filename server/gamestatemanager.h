#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "gamestate.h"
#include "QJsonObject"

class GameStateManager
{
public:
    GameStateManager();
    size_t serialize(QJsonObject &json);
    void deSerialize(QJsonObject &json);

   GameState* getGamestate();
   void setGameState(GameState* gameState);


private:
   GameState* gameState;

};

#endif // GAMESTATEMANAGER_H

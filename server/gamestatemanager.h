#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "gamestate.h"
#include "QJsonDocument"

class GameStateManager
{
public:
    GameStateManager();
    size_t serialize(QJsonDocument &json, GameStatePartition partition);
    void deSerialize(QJsonDocument &json);

   GameState* getGamestate();



   void quickTesting();

private:
   GameState gameState;

};

#endif // GAMESTATEMANAGER_H

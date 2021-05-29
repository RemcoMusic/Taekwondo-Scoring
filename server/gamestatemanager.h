#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "gamestate.h"
#include "QJsonObject"
#include "QJsonArray"

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
   QJsonArray serializeNestedData();
   void deSerializeNestedData(QJsonArray jsonArray);
};

#endif // GAMESTATEMANAGER_H

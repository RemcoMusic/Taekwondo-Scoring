#ifndef GAMESTATEMANAGER_H
#define GAMESTATEMANAGER_H

#include "gamestate.h"
#include "QByteArray"

class GameStateManager
{
public:
    GameStateManager();
    size_t serialize(QByteArray &buf);
    void deSerialize(QByteArray &buf);

   GameState* getGamestate();



   void quickTesting();

private:
   GameState gameState;

};

#endif // GAMESTATEMANAGER_H

#ifndef CLIENT_H
#define CLIENT_H

#include "gamestate.h"
#include "gamestatemanager.h"

class Client
{

public:
    Client();
    GameState *getGameState();
    void updateGameState(QByteArray data);

private:
    GameState gameState;
    GameStateManager gameStateManager;
};

#endif // CLIENT_H

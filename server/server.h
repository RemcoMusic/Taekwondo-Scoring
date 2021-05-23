#ifndef SERVER_H
#define SERVER_H

#include "gamestate.h"
#include "gamestatemanager.h"
#include "QTcpSocket"
class Server
{
public:
    Server();
    void inputEvent(QString client, QString event); // String for now. must be changed to events.
    void newClientEvent(QTcpSocket* soc);
private:
    GameState gameState;  //the official match gamestate. All other clients will sync with this gamestate.
    GameStateManager gameStateManager; //parser for the gamestate

};

#endif // SERVER_H

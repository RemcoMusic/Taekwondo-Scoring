#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "gamestate.h"
#include "gamestatemanager.h"
#include <QTcpServer>
#include <QTcpSocket>
#include "serverthread.h"



class Server :public QObject
{
    Q_OBJECT
public:
    Server();
    void startServer();
private:
    GameState gameState;  //the official match gamestate. All other clients will sync with this gamestate.
    GameStateManager gameStateManager; //parser for the gamestate

    QTcpServer* serverSocket; //only used for server


public slots:
    void incomingConnection();
    void inputEvent(uint32_t id, QByteArray data); // String for now. must be changed to events.

};

#endif // SERVER_H

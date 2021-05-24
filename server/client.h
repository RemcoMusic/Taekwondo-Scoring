#ifndef CLIENT_H
#define CLIENT_H

#include "gamestate.h"
#include "gamestatemanager.h"
#include <QTcpSocket>
#include <QObject>

class Client: public QObject
{
    Q_OBJECT
public:
    Client();
    GameState *getGameState();
    void updateGameState(QByteArray data);

    bool connectToServer(QString ip);
    bool isConnectedToServer();
    void disconnectFromServer();
    void sendEventToServer(QString e); // a string for now.. will become events

private:
    GameState gameState;
    GameStateManager gameStateManager;

    QTcpSocket* clientSocket; //only used for client

public slots:
    //for client
    void handleClientEvent();
    void clientDisconnected();
};

#endif // CLIENT_H

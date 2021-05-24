#include "client.h"
#include <QJsonDocument>
#include <QJsonObject>
#include <QHostAddress>
Client::Client()
{
    gameState.creationDate = "5/13/2021 - 19:32:10";
    gameState.version = "1";
    gameState.matchName = "No-city";
    gameStateManager.setGameState(&gameState);
    clientSocket = new QTcpSocket(this);
}
bool Client::connectToServer(QString ip)
{
    clientSocket->connectToHost(QHostAddress(ip),HOST_PORT);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(handleClientEvent()));
    connect(clientSocket, SIGNAL(disconnected()), this,SLOT(clientDisconnected()));

    if(clientSocket->isOpen()){
        return true;
    }
    return false;
}
bool Client::isConnectedToServer()
{
    return clientSocket->isOpen();
}

void Client::sendEventToServer(QString e)
{
    if(clientSocket->isOpen()){
        clientSocket->write(e.toUtf8());
    }
}
void Client::handleClientEvent()
{
    QByteArray data = clientSocket->readAll();
//    QJsonDocument doc = QJsonDocument::fromBinaryData(data);
//    qDebug() << "client: "<< clientSocket->socketDescriptor() << " received data: " <<doc;
    updateGameState(data);
}
void Client::clientDisconnected()
{
    qDebug() << "client disconnected";
    clientSocket->close();
}


GameState *Client::getGameState()
{
    return &gameState;
}

void Client::updateGameState(QByteArray data)
{
    //QByteArray data = clientSocket->readAll();
    QJsonDocument doc = QJsonDocument::fromBinaryData(data);
    gameStateManager.deSerialize(doc);

    qDebug() << "client gamestate got updated: " << gameState.matchName;
}

#include "client.h"
#include <QJsonDocument>
#include <QJsonObject>
Client::Client()
{
    gameState.creationDate = "5/13/2021 - 19:32:10";
    gameState.version = "1";
    gameState.matchName = "Pape-city";
    gameStateManager.setGameState(&gameState);
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

#include "server.h"

#include "serverthread.h"
Server::Server()
{
    gameState.creationDate = "5/13/2021 - 19:32:10";
    gameState.version = "1";
    gameState.matchName = "Pape-city";
    gameStateManager.setGameState(&gameState);
}

void Server::inputEvent(QString client, QString event)
{
    qDebug() << client << " requested input event: " <<event;


    gameState.matchName = "Albla-city";





    //if(importantEvent){
        QJsonDocument doc;
        gameStateManager.serialize(doc);
        ServerThread::updateAllClients(doc.toBinaryData());
    //}
    //else {
        //set timer to update client in a small amount of time (eg 1 second), to reduce network traffic.
    //}


}

#include "server.h"

#include "serverthread.h"

Server::Server()
{
    gameState.creationDate = "5/13/2021 - 19:32:10";
    gameState.version = "1";
    gameState.matchName = "Pape-city";
    gameStateManager.setGameState(&gameState);


    serverSocket = new QTcpServer(this);
}
void Server::startServer()
{
    if(!serverSocket->listen(QHostAddress::Any,HOST_PORT))
    {
        qDebug() << "Could not start Hosting Server";
    } else{
        qDebug() << "Server started";
    }
    connect(serverSocket,SIGNAL(newConnection()),this,SLOT(incomingConnection()));
}
void Server::incomingConnection()
{
    // We have a new connection
    QTcpSocket* newClient = serverSocket->nextPendingConnection();
    qDebug() << "Server has new connection for client: " << newClient->socketDescriptor()<< ". Connecting...";

    //if(myRole == DeviceRole::HOST){
        ServerThread *thread = new ServerThread(newClient, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        connect(thread, SIGNAL(inComingData(uint32_t,QByteArray)),this,SLOT(inputEvent(uint32_t,QByteArray)));
        //return calls from client to host. and call the server_handler();
        thread->start();
    //}


    QJsonDocument doc;
    gameStateManager.serialize(doc);
    ServerThread::updateClient(newClient,doc.toBinaryData());

}
void Server::inputEvent(uint32_t id, QByteArray data)
{
    qDebug() << id << " requested input event: " <<data;


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

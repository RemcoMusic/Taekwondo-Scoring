#include "network.h"
#include "serverthread.h"
#include "QJsonObject"

Network::Network(QObject *parent, DeviceRole role) :
    QObject(parent)
{
    myRole = role;

    if(myRole == DeviceRole::HOST){
        serverSocket = new QTcpServer(this);
    } else {
        clientSocket = new QTcpSocket(this);
    }
}

void Network::startServer(Server *s)
{
    server = s;
    if(!serverSocket->listen(QHostAddress::Any,HOST_PORT))
    {
        qDebug() << "Could not start Hosting Server";
    } else{
        qDebug() << "Server started";
    }
    connect(serverSocket,SIGNAL(newConnection()),this,SLOT(incomingConnection()));
}


void Network::attatchClient(Client *c)
{
    client = c;
}

//used when this class must establish a connection to the server
bool Network::connectToServer(QString ip)
{
    clientSocket->connectToHost(QHostAddress(ip),HOST_PORT);
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(handleClientEvent()));
    connect(clientSocket, SIGNAL(disconnected()), this,SLOT(clientDisconnected()));

    if(clientSocket->isOpen()){
        return true;
    }
    return false;
}

bool Network::isConnectedToServer()
{
    return clientSocket->isOpen();
}

void Network::disconnectFromServer()
{
    if(clientSocket->isOpen()){
        clientSocket->close();
    }
    disconnect(clientSocket, SIGNAL(readyRead()));
    disconnect(clientSocket, SIGNAL(disconnected()));
}

void Network::sendEventToServer(QString e)
{
    if(clientSocket->isOpen()){
        clientSocket->write(e.toUtf8());
    }else {
        qDebug() << "client socket not open. cant write data to server";
    }
}

void Network::handleClientEvent()
{
    QByteArray data = clientSocket->readAll();
//    QJsonDocument doc = QJsonDocument::fromBinaryData(data);
//    qDebug() << "client: "<< clientSocket->socketDescriptor() << " received data: " <<doc;
    client->updateGameState(data);
}

void Network::clientDisconnected()
{
    qDebug() << "client disconnected";
    clientSocket->close();
}

void Network::incomingConnection()
{
    // We have a new connection
    QTcpSocket* newClient = serverSocket->nextPendingConnection();
    qDebug() << "Server has new connection for client: " << newClient->socketDescriptor()<< ". Connecting...";

    //if(myRole == DeviceRole::HOST){
        ServerThread *thread = new ServerThread(newClient, server, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        //return calls from client to host. and call the server_handler();
        thread->start();
    //}

    //else it is a client.. wich only has 1 connection. call handler from here
    //client_handler();
}

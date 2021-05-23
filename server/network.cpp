#include "network.h"
#include "serverthread.h"

Network::Network(QObject *parent, DeviceRole role) :
    QObject(parent)
{
    myRole = role;

    if(myRole == DeviceRole::HOST){
        server = new QTcpServer(this);
    } else {
        clientSocket = new QTcpSocket(this);
    }
}

void Network::startServer()
{
    if(!server->listen(QHostAddress::Any,HOST_PORT))
    {
        qDebug() << "Could not start Hosting Server";
    } else{
        qDebug() << "Server started";
    }
    connect(server,SIGNAL(newConnection()),this,SLOT(incomingConnection()));
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
    qDebug() << "client received data: " <<data;
}

void Network::clientDisconnected()
{
    qDebug() << "client disconnected";
    clientSocket->close();
}

void Network::incomingConnection()
{
    // We have a new connection
    QTcpSocket* newClient = server->nextPendingConnection();
    qDebug() << "Server has new connection for client: " << newClient->socketDescriptor()<< ". Connecting...";

    //if(myRole == DeviceRole::HOST){
        ServerThread *thread = new ServerThread(newClient, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        //return calls from client to host. and call the server_handler();
        thread->start();
    //}

    //else it is a client.. wich only has 1 connection. call handler from here
    //client_handler();
}

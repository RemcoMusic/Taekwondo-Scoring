#include "network.h"
#include "serverthread.h"

Network::Network(QObject *parent, serverRole role) :
    QTcpServer(parent)
{
    myRole = role;
}

void Network::startServer()
{


    int port;
    if(myRole == serverRole::HOST){
        port = HOST_PORT;
    } else {
        port = CLIENT_PORT;
    }

    if(!this->listen(QHostAddress::Any,port))
    {
        qDebug() << "Could not start "<< (myRole == serverRole::HOST?"Hosting Server":"Client Listener");
    }
    else
    {
        qDebug() << "Listening as " << (myRole == serverRole::HOST?"Host":"Client") << " to port " << port << "... ";
    }
}

void Network::incomingConnection(qintptr socketDescriptor)
{
    // We have a new connection
    qDebug() << socketDescriptor << " Connecting...";

    if(myRole == serverRole::HOST){
        ServerThread *thread = new ServerThread(socketDescriptor, this);
        connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        //return calls from client to host. and call the server_handler();
        thread->start();
    }

    //else it is a client.. wich only has 1 connection. call handler from here
    //client_handler();
}

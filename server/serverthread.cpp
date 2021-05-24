#include "serverthread.h"

QList<ServerThread*> ServerThread::activeConnections; //declaration of static variable
ServerThread::ServerThread(QTcpSocket *_socket, QObject *parent) :
    QThread(parent)
{
    socket = _socket;
    ServerThread::activeConnections.append(this);
}

ServerThread::~ServerThread()
{
    //cleanup
}

void ServerThread::run()
{
    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    qDebug() << socket->socketDescriptor() << " Client connected and running in ServerThread";

    exec();
}

int ServerThread::updateAllClients(QByteArray data)
{
    for(int i = 0; i < activeConnections.size(); i++){
        activeConnections.at(i)->socket->write(data);
    }
}

int ServerThread::updateClient(QTcpSocket* s, QByteArray data)
{
    s->write(data);
}

void ServerThread::readyRead()
{
    // get the information
    QByteArray data = socket->readAll();


    //qDebug() << socket->socketDescriptor() << " Data in: " << Data;
    emit inComingData(socket->socketDescriptor(),data);
    //socket->write(Data); //echo data back as test
}

void ServerThread::disconnected()
{
    ServerThread::activeConnections.removeOne(this);
    qDebug() << socket->socketDescriptor() << " Disconnected, remaining clients: "<< ServerThread::activeConnections.size();
    socket->close();
    socket->deleteLater();
    disconnect(socket, SIGNAL(readyRead()));
    disconnect(socket, SIGNAL(disconnected()));
    exit(0);
}

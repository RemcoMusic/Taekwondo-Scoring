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
    // thread starts here

    // connect socket and signal
    // note - Qt::DirectConnection is used because it's multithreaded
    //        This makes the slot to be invoked immediately, when the signal is emitted.

    connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()), Qt::DirectConnection);
    connect(socket, SIGNAL(disconnected()), this, SLOT(disconnected()));

    // We'll have multiple clients, we want to know which is which
    qDebug() << socket->socketDescriptor() << " Client connected and running in ServerThread";

    // make this thread a loop,
    // thread will stay alive so that signal/slot to function properly
    // not dropped out in the middle when thread dies

    exec();
}

void ServerThread::readyRead()
{
    // get the information
    QByteArray Data = socket->readAll();

    // will write on server side window
    qDebug() << socket->socketDescriptor() << " Data in: " << Data;

    socket->write(Data);
}

void ServerThread::disconnected()
{
    ServerThread::activeConnections.removeOne(this);
    qDebug() << socket->socketDescriptor() << " Disconnected, remaining clients: "<< ServerThread::activeConnections.size();
    socket->deleteLater();
    exit(0);
}

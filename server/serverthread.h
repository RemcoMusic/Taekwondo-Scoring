#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H


#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "server.h"

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(QTcpSocket *_socket,Server* s, QObject *parent = 0);
    ~ServerThread();
    void run();
    static QList<ServerThread*> activeConnections;
    static int updateAllClients(QByteArray data);

signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
    Server* server;
};


#endif // SERVERTHREAD_H

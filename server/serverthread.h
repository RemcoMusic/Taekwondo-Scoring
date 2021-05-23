#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H


#include <QThread>
#include <QTcpSocket>
#include <QDebug>

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(QTcpSocket *_socket, QObject *parent = 0);
    ~ServerThread();
    void run();
    static QList<ServerThread*> activeConnections;


signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
};


#endif // SERVERTHREAD_H

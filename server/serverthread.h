#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H


#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include <QByteArray>

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(QTcpSocket *_socket, QObject *parent = 0);
    ~ServerThread();
    void run();
    static QList<ServerThread*> activeConnections;
    static int updateAllClients(QByteArray data);
    static int updateClient(QTcpSocket *s, QByteArray data);

signals:
    void error(QTcpSocket::SocketError socketerror);
    void inComingData(uint32_t id, QByteArray data);

public slots:
    void readyRead();
    void disconnected();

private:
    QTcpSocket *socket;
};


#endif // SERVERTHREAD_H

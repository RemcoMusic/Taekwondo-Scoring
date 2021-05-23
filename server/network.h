#ifndef NETWORK_H
#define NETWORK_H


#include <QTcpServer>
#include <QTcpSocket>
#include "serverthread.h"

#define HOST_PORT   80  //port the server will run on

enum class DeviceRole{
    CLIENT,  //join a match
    HOST    //host a match
};

class Network : public QObject
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0, DeviceRole role = DeviceRole::CLIENT);

    //for server
    void startServer();

    //for client
    bool connectToServer(QString ip);
    void sendEventToServer(QString e); // a string for now.. will become events

private:
    DeviceRole myRole;        //local variable to tell if this is a client or server

    QTcpSocket* clientSocket; //only used for client
    QTcpServer* server;       //only used for server

signals:

public slots:
    //for client
    void handleClientEvent();
    void clientDisconnected();

    //for server
    void incomingConnection();

};

#endif // NETWORK_H

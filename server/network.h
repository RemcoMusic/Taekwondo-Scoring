#ifndef NETWORK_H
#define NETWORK_H


#include <QTcpServer>
#include <QTcpSocket>
#include "serverthread.h"

#include "client.h"
#include "server.h"



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
    void startServer(Server* s);

    //for client
    void attatchClient(Client* c);
    bool connectToServer(QString ip);
    bool isConnectedToServer();
    void disconnectFromServer();
    void sendEventToServer(QString e); // a string for now.. will become events

private:
    DeviceRole myRole;        //local variable to tell if this is a client or server

    QTcpSocket* clientSocket; //only used for client
    QTcpServer* serverSocket; //only used for server

    Server* server;          //server wich handles the logic. only used when role is server
    Client* client;          //client to pass the events to.. only used when role is client
signals:

public slots:
    //for client
    void handleClientEvent();
    void clientDisconnected();

    //for server
    void incomingConnection();

};

#endif // NETWORK_H

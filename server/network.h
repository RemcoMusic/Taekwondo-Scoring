#ifndef NETWORK_H
#define NETWORK_H


#include <QTcpServer>
#include "serverthread.h"
#define HOST_PORT   80
#define CLIENT_PORT 81
enum class serverRole{
    CLIENT,
    HOST
};

class Network : public QTcpServer
{
    Q_OBJECT
public:
    explicit Network(QObject *parent = 0, serverRole role = serverRole::CLIENT);
    void startServer();
    //void handleIncomingEvent;
private:
    serverRole myRole;
signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor);

};

#endif // NETWORK_H

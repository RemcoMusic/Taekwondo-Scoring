#include "initializeserver.h"

InitializeServer::InitializeServer(QObject *parent) : QObject(parent)
{

}

void InitializeServer::receiveSetupData(QString foo) {
    qDebug() << foo;
}

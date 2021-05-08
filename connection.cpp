#include "connection.h"

Connection::Connection(QObject *parent) : QObject(parent) ,
    m_uniqueID("0000")
{

}

void Connection::onReceivedStartSignal(QString matchName)
{
    qDebug() << matchName;
}

QString Connection::uniqueID()
{
    return m_uniqueID;
}

void Connection::setUniqueID(QString id)
{
    if(m_uniqueID != id) {
        m_uniqueID = id;
        emit uniqueIDChanged();
    }

}

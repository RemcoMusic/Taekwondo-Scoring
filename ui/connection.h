#ifndef CONNECTION_H
#define CONNECTION_H

#include <QObject>
#include <QDebug>

class Connection : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uniqueID READ uniqueID WRITE setUniqueID NOTIFY uniqueIDChanged)
public:
    explicit Connection(QObject *parent = nullptr);
    QString uniqueID();

signals:
    void uniqueIDChanged();

public slots:
    void onReceivedStartSignal(QString);
    void setUniqueID(QString);

private:
    QString m_uniqueID;

};

#endif // CONNECTION_H

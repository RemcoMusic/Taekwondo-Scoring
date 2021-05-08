#ifndef INITIALIZESERVER_H
#define INITIALIZESERVER_H

#include <QObject>
#include <QString>
#include <QDebug>

class InitializeServer : public QObject
{
    Q_OBJECT
public:
    explicit InitializeServer(QObject *parent = nullptr);

signals:

public slots:
    void receiveSetupData(QString);

};

#endif // INITIALIZESERVER_H

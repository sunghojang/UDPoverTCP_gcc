// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QTimer>
#include <QObject>
#include <QTcpServer>
#include <QTcpSocket>

#include <QMap>
#include <QByteArray>
#include <QDataStream>

#include "tcpclient.h"

class TCPServer : public QObject
{
    Q_OBJECT

public:
    TCPServer(QObject* parent = 0);

    bool start(const quint16 &port);
    void stop();

signals:
    void dataReceived(QByteArray data);
    void connectionCount(int count);

    void info(QString sender, QString info);
    void warning(QString sender, QString warning);
    void error(QString sender, QString error);

public slots:
    void sendData(const QByteArray &data);
    void clientDataReceived(const QByteArray &data);

private slots:
    void connectClient();
    void disconnectClient();

    void clientInfo(const QString &sender, const QString &message);
    void clientWarning(const QString &sender, const QString &message);
    void clientError(const QString &sender, const QString &message);

private:
    QTcpServer *server;
    QMap<QTcpSocket *, QTcpSocket *> socketMap;
    QMap<QTcpSocket *, TCPClient *> clientMap;

    QString classname;
};

#endif

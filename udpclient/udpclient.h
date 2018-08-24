// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#ifndef UDPCLIENT_H
#define UDPCLIENT_H

#include <QList>
#include <QObject>
#include <QString>
#include <QByteArray>
#include <QUdpSocket>

class UDPClient : public QObject
{
    Q_OBJECT
public:
    explicit UDPClient(QObject *parent = 0);

    bool connect(const qint64 &port = 49999);
    void disconnect();

signals:
    void dataReceived(QByteArray data);

    void info(QString sender, QString info);
    void warning(QString sender, QString warning);
    void error(QString sender, QString error);

public slots:
    void sendData(const QByteArray &data);

private slots:
    void readData();
    void displayError(QAbstractSocket::SocketError socketError);

private:
    qint64 port;
    QUdpSocket *udpSocket;

    QString classname;
    QList<QByteArray> sendDataFilter;
};

#endif // CLIENT_H

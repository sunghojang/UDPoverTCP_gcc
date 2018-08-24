// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include <QObject>
#include <QString>
#include <QByteArray>
#include <QTcpSocket>

class TCPClient : public QObject
{
    Q_OBJECT

public:
    TCPClient(QObject *parent = 0);

    bool connect(QTcpSocket *socket);
    bool connect(const QString &host, const qint64 &port);
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
    QString host;
    bool clientConnection;
    QTcpSocket *tcpSocket;

    QString classname;

    quint16 blockSize;
    QByteArray *buffer;
};

#endif

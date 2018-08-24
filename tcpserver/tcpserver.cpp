// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#include <QBuffer>
#include <QDataStream>

#include "tcpserver.h"

static inline QByteArray IntToArray(qint16 source);

TCPServer::TCPServer(QObject *parent)
    : QObject(parent), server(0)
{
    classname = "TCPServer";
}

bool TCPServer::start(const quint16 &port)
{
    if(server)
        return false;

    emit info(classname, "started at port " + QString::number(port));

    server = new QTcpServer(this);
    bool result1 = QObject::connect(server, SIGNAL(newConnection()), this, SLOT(connectClient()));
    bool result2 = server->listen(QHostAddress::Any, port);

    if (!result1)
        emit error(classname, "TCP server could not connect newConnection");
    if (!result2)
        emit error(classname, "TCP server failed to start listening");

    return (result1 && result2);
}

void TCPServer::stop()
{
    if(!server)
        return;

    // Cleanup the server
    server->close();
    server->deleteLater();
    server = 0;

    emit connectionCount(socketMap.size());
    emit warning(classname, "stopped");
}

void TCPServer::sendData(const QByteArray &data)
{
    if (!server)
        return;

    // Do nothing if there are no active connections
    if (socketMap.size() <= 0)
        return;

    // Build the message
    QByteArray message;
    message.append("TNO");  // Header
    message.append(IntToArray((quint16) data.size()));
    message.append(data);

    // Send the message
    QMap<QTcpSocket *, QTcpSocket *>::iterator ism;
    for (ism = socketMap.begin(); ism != socketMap.end(); ++ism)
    {
        QTcpSocket *socket = ism.value();

        socketMap[socket]->write(message);
        if (!socketMap[socket]->flush())
            emit warning(classname, "TCP server socket flush failed");
    }

    emit info(classname, "send data: " + QString(data));
}

void TCPServer::clientDataReceived(const QByteArray &data)
{
    emit dataReceived(data);
}

void TCPServer::connectClient()
{
    emit info(classname, "adding new connection");

    // Create socket and client
    while(server->hasPendingConnections())
    {
        QTcpSocket *socket = server->nextPendingConnection();
        QObject::connect(socket, SIGNAL(disconnected()), this, SLOT(disconnectClient()));

        socketMap[socket] = socket;

        TCPClient *client = new TCPClient(this);
        client->connect(socket);
        QObject::connect(client, SIGNAL(dataReceived(QByteArray)), this, SLOT(clientDataReceived(QByteArray)));
        QObject::connect(client, SIGNAL(info(QString,QString)), this, SLOT(clientInfo(QString,QString)));
        QObject::connect(client, SIGNAL(warning(QString,QString)), this, SLOT(clientWarning(QString,QString)));
        QObject::connect(client, SIGNAL(error(QString,QString)), this, SLOT(clientError(QString,QString)));

        clientMap[socket] = client;
    }

    emit connectionCount(socketMap.size());
}

void TCPServer::disconnectClient()
{
    QTcpSocket* socket = (QTcpSocket*)sender();

    // Cleanup specific socket
    clientMap[socket]->disconnect();
    clientMap[socket]->deleteLater();
    clientMap.remove(socket);
    socketMap[socket]->close();
    socketMap[socket]->deleteLater();
    socketMap.remove(socket);

    emit connectionCount(socketMap.size());
}

void TCPServer::clientInfo(const QString &sender, const QString &message)
{
    emit info(classname + "->" + sender, message);
}

void TCPServer::clientWarning(const QString &sender, const QString &message)
{
    emit warning(classname + "->" + sender, message);
}

void TCPServer::clientError(const QString &sender, const QString &message)
{
    emit error(classname + "->" + sender, message);
}

QByteArray IntToArray(qint16 source) // Use qint16 to ensure that the number have 2 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

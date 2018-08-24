// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#include <QtNetwork>

#include "tcpclient.h"

static inline qint16 ArrayToInt(QByteArray source);
static inline QByteArray IntToArray(qint16 source);


TCPClient::TCPClient(QObject *parent)
    :   QObject(parent), tcpSocket(0)
{
    classname = "TCPClient";
}


bool TCPClient::connect(QTcpSocket *socket)
{
    // Check if the socket is already initialised
    if(tcpSocket)
        return false;

    tcpSocket = socket;

    QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    QObject::connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

    // Init datastore
    blockSize = 0;
    buffer = new QByteArray();
    buffer->clear();

    clientConnection = false;

    return true;
}

bool TCPClient::connect(const QString &host, const qint64 &port)
{
    // Check if the socket is already initialised
    if(tcpSocket)
        return false;

    // Init and connect new tcpSocket
    emit info(classname, "connection to " + host + ":" + QString::number(port));
    this->host = host;
    this->port = port;

    tcpSocket = new QTcpSocket(this);


    QObject::connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(readData()));
    QObject::connect(tcpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

    // Init datastore
    blockSize = 0;
    buffer = new QByteArray();
    buffer->clear();

    tcpSocket->connectToHost(host, port);

    clientConnection = true;

    return true;
}

void TCPClient::disconnect()
{
    emit warning(classname, "disconnected");

    // Disconnect (if clientConnection)
    if (clientConnection)
        tcpSocket->disconnectFromHost();

    // Reset
    tcpSocket = 0;
    blockSize = 0;
    buffer->clear();
}

void TCPClient::sendData(const QByteArray &data)
{
    if (!tcpSocket)
        return;

    // Build the message
    QByteArray message;
    message.append("TNO");  // Header
    message.append(IntToArray((quint16) data.size()));
    message.append(data);

    // Send the message
    tcpSocket->write(message);
    if (!tcpSocket->flush())
        emit warning(classname, "TCP client socket flush failed");

    emit info(classname, "send data: " + QString(data));
}

void TCPClient::readData()
{
    QByteArray header = "TNO";

    int qint16Size = (int)sizeof(quint16);
    int minSize = header.size() + qint16Size;

    while (tcpSocket->bytesAvailable() > 0)
    {
        buffer->append(tcpSocket->readAll());
        while ((blockSize == 0 && buffer->size() >= minSize) || (blockSize > 0 && buffer->size() >= blockSize)) // While we can process data, process it
        {
            // If size of data has received completely, then store it on our global variable
            if (blockSize == 0 && buffer->size() >= minSize)
            {
                if (!buffer->startsWith(header))
                {
                    // Check header
                    emit error(classname, "header corrupted");
                    blockSize = 0;
                    buffer->clear();
                    return;
                }

                blockSize = ArrayToInt(buffer->mid(header.size(), minSize-1));

                buffer->remove(0, minSize);
            }

            // If data has received completely, then emit our SIGNAL with the data
            if (blockSize > 0 && buffer->size() >= blockSize)
            {
                QByteArray data = buffer->mid(0, blockSize);
                buffer->remove(0, blockSize);
                blockSize = 0;
                emit info(classname, "received data: " + QString(data));
                emit dataReceived(data);
            }
        }
    }
}


void TCPClient::displayError(QAbstractSocket::SocketError socketError)
{
    QString message;
    switch (socketError) {
    case QAbstractSocket::RemoteHostClosedError:
        message = "QAbstractSocket::RemoteHostClosedError";
        break;
    case QAbstractSocket::HostNotFoundError:
        message = "(QAbstractSocket::HostNotFoundError) Fortune Client. The host was not found. Please check the host name and port settings.";
        break;
    case QAbstractSocket::ConnectionRefusedError:
        message = "(QAbstractSocket::HostNotFoundError) The connection was refused by the peer. Make sure the fortune server is running, and check that the host name and port settings are correct.";
        break;
    default:
        message = "(QAbstractSocket::default) The following error occured: tbd";// << QString(tcpSocket->errorString());
    }

    emit error(classname, message);
    disconnect();
}

qint16 ArrayToInt(QByteArray source) // Use qint16 to ensure that the number have 2 bytes
{
    qint16 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

QByteArray IntToArray(qint16 source) // Use qint16 to ensure that the number have 2 bytes
{
    //Avoid use of cast, this is the Qt way to serialize objects
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

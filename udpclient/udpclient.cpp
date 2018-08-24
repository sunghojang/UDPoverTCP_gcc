// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#include "udpclient.h"

UDPClient::UDPClient(QObject *parent) :
    QObject(parent), udpSocket(0)
{
    classname = "UDPClient";
}

bool UDPClient::connect(const qint64 &port)
{
    // Check if the socket is already initialised
    if(udpSocket)
        return false;

    // Init and connect new udpSocket
    emit info(classname, "listening to port " + QString::number(port));
    this->port = port;

    udpSocket = new QUdpSocket(this);
    sendDataFilter.clear();


    if (!QObject::connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readData())))
        emit error(classname, "could not connect to readData");
    QObject::connect(udpSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));

#ifdef Q_OS_WIN32
    /* Windows */
    if (!udpSocket->bind(port, QUdpSocket::ReuseAddressHint))
    {
        emit error(classname, "bind (with ReuseAddressHint) failed (win32)");
        return false;
    }
#else
    if (!udpSocket->bind(port, QUdpSocket::ShareAddress))
    {
        emit error(classname, "bind (with ShareAddress) failed");
        return false;
    }
#endif

    return true;
}

void UDPClient::disconnect()
{
    emit warning(classname, "disconnected");

    // Disconnect
    udpSocket->disconnectFromHost();
    udpSocket->deleteLater();

    // Reset
    udpSocket = 0;
}

void UDPClient::sendData(const QByteArray &data)
{
    if (!udpSocket)
        return;

    sendDataFilter.append(data);

    udpSocket->writeDatagram(data.data(), data.size(), QHostAddress::Broadcast, port);
    udpSocket->flush();

    emit info(classname, "send data: " + QString(data));
}

void UDPClient::readData()
{
    // Now read all available datagrams from the socket
    while (udpSocket->hasPendingDatagrams()) {
        // Create a temporary buffer ...
        QByteArray data;
        data.resize(udpSocket->pendingDatagramSize());
        udpSocket->readDatagram(data.data(), data.size());

        // If it is data we send ourselves, we remove it again from the filterList and do not send it back
        if (sendDataFilter.contains(data))
        {
            sendDataFilter.removeOne(data);
            return;
        }

        emit info(classname, "received data: " + QString(data));
        emit dataReceived(data);
    }
}

void UDPClient::displayError(QAbstractSocket::SocketError socketError)
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
        message = "(QAbstractSocket::default) The following error occured: " + udpSocket->errorString();
    }

    emit error(classname, message);
    disconnect();
}

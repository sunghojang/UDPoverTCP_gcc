// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#include <QNetworkInterface>

#include "snbgui.h"
#include "ui_snbgui.h"

SNBGui::SNBGui(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SNBGui),
    tuStarted(0), utStarted(0),
    _start(true), _stop(false)
{
    ui->setupUi(this);
    classname = "SNBGui";

    QObject::connect(&logger, SIGNAL(logUpdated(QString)), this, SLOT(updateLog(QString)));

    logger.addInfo(classname, "Started");
    logger.setMaxLines(1000);
}

SNBGui::~SNBGui()
{
    delete ui;
}

void SNBGui::updateLog(QString log)
{
    ui->textEditLogger->setHtml(log);
}

void SNBGui::updateConnectionCount(int count)
{
    if(utStarted)
        ui->statusBar->showMessage("Connected TCP Clients: " + QString::number(count));
    else
        ui->statusBar->showMessage("");
}

void SNBGui::on_buttonUTStartStop_clicked()
{
    if(tuStarted)
    {
        logger.addError(classname, "cannot start both services simultaneously");
        return;
    }

    if(utStarted)
    {
        // Set the buttons
        ui->buttonUTStartStop->setText("Start");
        ui->tabTU->setDisabled(false);
        ui->spinBoxUdpListenPort->setDisabled(false);
        ui->spinBoxTcpServerPort->setDisabled(false);

        // Stop the services
        controlTcpServer(_stop);
        controlUdpClient(_stop, true);

        updateConnectionCount(0);

        utStarted = false;
    }
    else
    {
        // Set the buttons
        ui->buttonUTStartStop->setText("Stop");
        ui->tabTU->setDisabled(true);
        ui->spinBoxUdpListenPort->setDisabled(true);
        ui->spinBoxTcpServerPort->setDisabled(true);

        // Create the service
        tcpserver = new TCPServer();
        udpclient = new UDPClient();

        // Add IP Addresses to logwindow
        addIpAddressToLog();


        // Start the services
        controlTcpServer(_start);
        controlUdpClient(_start, true);

        updateConnectionCount(0);

        utStarted = true;
    }
}

void SNBGui::on_buttonTUStartStop_clicked()
{
    if(utStarted)
    {
        logger.addError(classname, "cannot start both services simultaneously");
        return;
    }

    if(tuStarted)
    {
        // Set the buttons
        ui->buttonTUStartStop->setText("Start");
        ui->tabUT->setDisabled(false);
        ui->spinBoxUdpBroadcastPort->setDisabled(false);
        ui->spinBoxTcpClientPort->setDisabled(false);
        ui->lineEditTcpServerAddress->setDisabled(false);
        ui->statusBar->showMessage("");

        // Stop the services
        controlTcpClient(_stop);
        controlUdpClient(_stop, false);

        updateConnectionCount(0);

        tuStarted = false;
    }
    else
    {
        // Set the buttons
        ui->buttonTUStartStop->setText("Stop");
        ui->tabUT->setDisabled(true);
        ui->spinBoxUdpBroadcastPort->setDisabled(true);
        ui->spinBoxTcpClientPort->setDisabled(true);
        ui->lineEditTcpServerAddress->setDisabled(true);
        ui->statusBar->showMessage("Connected to " + ui->lineEditTcpServerAddress->text() + ":" + QString::number(ui->spinBoxTcpClientPort->value()));

        // Creating the service
        udpclient = new UDPClient();
        tcpclient = new TCPClient();

        // Start the services
        controlTcpClient(_start);
        controlUdpClient(_start, false);

        updateConnectionCount(0);

        tuStarted = true;
    }
}

void SNBGui::on_buttonClearLogger_clicked()
{
    logger.clear();
}

bool SNBGui::controlTcpServer(const bool &start)
{
    if(start)
    {
        QObject::connect(tcpserver, SIGNAL(connectionCount(int)), this, SLOT(updateConnectionCount(int)));
        if (ui->checkBoxTUBidirectionalEnabled->isChecked())
        {
            QObject::connect(tcpserver, SIGNAL(dataReceived(QByteArray)), udpclient, SLOT(sendData(QByteArray)));
        }

        // Connect logging
        QObject::connect(tcpserver, SIGNAL(info(QString,QString)), &logger, SLOT(addInfo(QString,QString)));
        QObject::connect(tcpserver, SIGNAL(warning(QString,QString)), &logger, SLOT(addWarning(QString,QString)));
        QObject::connect(tcpserver, SIGNAL(error(QString,QString)), &logger, SLOT(addError(QString,QString)));

        if (!tcpserver->start(ui->spinBoxTcpServerPort->value()))
        {
            logger.addError(classname, "TCP server failed to start");
            return false;
        }
    }
    else
    {
        // Stop and delete the service
        tcpserver->stop();
        tcpserver->deleteLater();
    }
    return true;
}

bool SNBGui::controlTcpClient(const bool &start)
{
    if(start)
    {
        // Create the service
        tcpclient = new TCPClient();

        QObject::connect(tcpclient, SIGNAL(dataReceived(QByteArray)), udpclient, SLOT(sendData(QByteArray)));

        // Connect logging
        QObject::connect(tcpclient, SIGNAL(info(QString,QString)), &logger, SLOT(addInfo(QString,QString)));
        QObject::connect(tcpclient, SIGNAL(warning(QString,QString)), &logger, SLOT(addWarning(QString,QString)));
        QObject::connect(tcpclient, SIGNAL(error(QString,QString)), &logger, SLOT(addError(QString,QString)));

        if (!tcpclient->connect(ui->lineEditTcpServerAddress->text(), ui->spinBoxTcpClientPort->value()))
        {
            logger.addError(classname, "TCP client failed to start");
            return false;
        }
    }
    else
    {
        // Stop and delete the services
        tcpclient->disconnect();
        tcpclient->deleteLater();
    }
    return true;
}

bool SNBGui::controlUdpClient(const bool &start, const bool& server)
{
    if(start)
    {
        if(server)
        {
            QObject::connect(udpclient, SIGNAL(dataReceived(QByteArray)), tcpserver, SLOT(sendData(QByteArray)));
        }
        else
        {
            if (ui->checkBoxUTBidirectionalEnabled->isChecked())
            {
                QObject::connect(udpclient, SIGNAL(dataReceived(QByteArray)), tcpclient, SLOT(sendData(QByteArray)));
            }
        }
        // Connect logging
        QObject::connect(udpclient, SIGNAL(info(QString,QString)), &logger, SLOT(addInfo(QString,QString)));
        QObject::connect(udpclient, SIGNAL(warning(QString,QString)), &logger, SLOT(addWarning(QString,QString)));
        QObject::connect(udpclient, SIGNAL(error(QString,QString)), &logger, SLOT(addError(QString,QString)));

        if(server)
        {if (!udpclient->connect(ui->spinBoxUdpListenPort->value()))
            {
                logger.addError(classname, "UDP client failed to start");
                return false;
            }
        }
        else
        {
            if (!udpclient->connect(ui->spinBoxUdpBroadcastPort->value()))
            {
                logger.addError(classname, "UDP client failed to start");
                return false;
            }
        }
    }
    else
    {
        // Stop and delete the service
        udpclient->disconnect();
        udpclient->deleteLater();
    }
    return true;
}

void SNBGui::addIpAddressToLog()
{
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for(int i = 0; i < list.size(); ++i)
    {
        if (list[i].protocol() == QAbstractSocket::IPv4Protocol )
        {
            logger.addInfo(classname, " - Address IPv4: " + list[i].toString());
        }
        else if (list[i].protocol() == QAbstractSocket::IPv6Protocol )
        {
            logger.addInfo(classname, " - Address IPv6: " + list[i].toString());
        }
        else
        {
            logger.addWarning(classname, " - unknown: " + list[i].toString());
        }
    }
}

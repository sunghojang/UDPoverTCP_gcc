// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#include "snbtests.h"
#include "ui_snbtests.h"

SNBTests::SNBTests(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SNBTests),
    udpListenClient(0),
    started(0)
{
    ui->setupUi(this);

    classname = "SNBTest";

    QObject::connect(&logger, SIGNAL(logUpdated(QString)), this, SLOT(updateLog(QString)));

    logger.setMaxLines(1000);
    logger.addInfo(classname, "Started");

    // Start listening
    on_spinBoxListenPort_valueChanged(0);
}

SNBTests::~SNBTests()
{
    delete ui;
}

void SNBTests::updateLog(QString log)
{
    ui->textEditLogger->setHtml(log);
}

void SNBTests::receivedData(QByteArray data)
{
    logger.addInfo("DATA", QString(data));
}

void SNBTests::on_spinBoxListenPort_valueChanged(int arg1)
{
    Q_UNUSED(arg1);
    if(udpListenClient)
    {
        udpListenClient->disconnect();
        udpListenClient->deleteLater();
    }

    // Start again with new port
    udpListenClient = new UDPClient();
    QObject::connect(udpListenClient, SIGNAL(dataReceived(QByteArray)), this, SLOT(receivedData(QByteArray)));

    // Connect logging
    QObject::connect(udpListenClient, SIGNAL(info(QString,QString)), &logger, SLOT(addInfo(QString,QString)));
    QObject::connect(udpListenClient, SIGNAL(warning(QString,QString)), &logger, SLOT(addWarning(QString,QString)));
    QObject::connect(udpListenClient, SIGNAL(error(QString,QString)), &logger, SLOT(addError(QString,QString)));

    if (!udpListenClient->connect(ui->spinBoxListenPort->value()))
        logger.addError(classname, "UDP client failed to start");
}

void SNBTests::on_buttonSend_clicked()
{
    // Start server and connect logging
    UDPClient *udpSendClient = new UDPClient();

    QObject::connect(udpSendClient, SIGNAL(info(QString,QString)), &logger, SLOT(addInfo(QString,QString)));
    QObject::connect(udpSendClient, SIGNAL(warning(QString,QString)), &logger, SLOT(addWarning(QString,QString)));
    QObject::connect(udpSendClient, SIGNAL(error(QString,QString)), &logger, SLOT(addError(QString,QString)));

    if (!udpSendClient->connect(ui->spinBoxBroadcastPort->value()))
        logger.addError(classname, "UDP client failed to start");

    // Send data
    udpSendClient->sendData(ui->lineEdit->text().toAscii());

    // Stop server
    udpSendClient->disconnect();
    udpSendClient->deleteLater();
}

void SNBTests::on_buttonClearLogger_clicked()
{
    logger.clear();
}

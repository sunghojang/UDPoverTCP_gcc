// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#ifndef SNBGUI_H
#define SNBGUI_H

#include <QMainWindow>
#include <QString>

#include "htmllogger.h"
#include "tcpclient.h"
#include "tcpserver.h"
#include "udpclient.h"
//#include "udpserver.h"

namespace Ui {
class SNBGui;
}

class SNBGui : public QMainWindow
{
    Q_OBJECT

public:
    explicit SNBGui(QWidget *parent = 0);
    ~SNBGui();

private slots:
    void updateLog(QString log);
    void updateConnectionCount(int count);

    void on_buttonUTStartStop_clicked();
    void on_buttonTUStartStop_clicked();

    void on_buttonClearLogger_clicked();

private:
    bool controlTcpServer(const bool &start);
    bool controlTcpClient(const bool &start);
    bool controlUdpClient(const bool &start, const bool &server);

    void addIpAddressToLog();

    Ui::SNBGui *ui;
    HTMLLogger logger;

    TCPClient *tcpclient;
    TCPServer *tcpserver;
    UDPClient *udpclient;
//    UDPServer *udpserver;

    bool tuStarted;
    bool utStarted;

    bool _start;
    bool _stop;

    QString classname;
};

#endif // SNBGUI_H

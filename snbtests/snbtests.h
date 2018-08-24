// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#ifndef SNBTESTS_H
#define SNBTESTS_H

#include <QMainWindow>
#include <QString>

#include "htmllogger.h"
#include "udpclient.h"

namespace Ui {
class SNBTests;
}

class SNBTests : public QMainWindow
{
    Q_OBJECT

public:
    explicit SNBTests(QWidget *parent = 0);
    ~SNBTests();

private slots:
    void updateLog(QString log);
    void receivedData(QByteArray data);

    void on_spinBoxListenPort_valueChanged(int arg1);
    void on_buttonSend_clicked();

    void on_buttonClearLogger_clicked();

private:
    Ui::SNBTests *ui;
    HTMLLogger logger;

    UDPClient *udpListenClient;

    bool started;

    QString classname;
};

#endif // SNBTESTS_H

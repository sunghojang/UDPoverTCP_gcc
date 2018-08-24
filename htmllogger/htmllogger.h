// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#ifndef HTMLLOGGER_H
#define HTMLLOGGER_H

#include <QObject>

#include <QString>
#include <QStringList>

class HTMLLogger : public QObject
{
    Q_OBJECT
public:
    explicit HTMLLogger(QObject *parent = 0);

    void setMaxLines(const int &maxlines);
    int getMaxLines();

    void clear();

signals:
    void logUpdated(QString html);

public slots:
    void addInfo(QString sender, QString info);
    void addWarning(QString sender, QString warning);
    void addError(QString sender, QString error);

private slots:
    void addLine(QString color, QString text);

private:
    QString generateHtmlLog();

    int maxLines;
    int lineCount;
    QString header;
    QString footer;

    QStringList html;
};

#endif // HTMLLOGGER_H

// Copyright (c) 2014 All Right Reserved
//
// author  : Patrick Hanckmann
// email   : hanckmann@gmail.com
// summary :

#include "htmllogger.h"

HTMLLogger::HTMLLogger(QObject *parent) :
    QObject(parent),
    maxLines(0),
    lineCount(0)
{
    html.clear();

    header = "<!DOCTYPE html><html><head><meta charset=\"utf-8\"><title>Logfile</title></head><body>";
    footer = "</body></html>";
}

void HTMLLogger::setMaxLines(const int &maxlines)
{
    maxLines = maxlines;
}

int HTMLLogger::getMaxLines()
{
    return maxLines;
}

void HTMLLogger::clear()
{
    html.clear();

    emit logUpdated(generateHtmlLog());
}

void HTMLLogger::addInfo(QString sender, QString info)
{
    QString color = "black";
    QString text;
    addLine(color, "INFO: (" + sender + ") " + info);
}

void HTMLLogger::addWarning(QString sender, QString warning)
{
    QString color = "orange";
    addLine(color, "WARN: (" + sender + ") " + warning);
}

void HTMLLogger::addError(QString sender, QString error)
{
    QString color = "red";
    addLine(color, "ERROR: (" + sender + ") " + error);
}

void HTMLLogger::addLine(QString color, QString text)
{
    // Contruct html line
    QString line = "<font color=\"grey\">[ " + QString::number(++lineCount) + " ] </font><font color=\"" + color + "\">" + text + "</font><br/>";
    // Add the line at the top
    html.push_front(line);

    // Check for and process maxLines
    if(maxLines > 0)
    {
        while(html.size() > maxLines)
            html.removeLast();
    }

    emit logUpdated(generateHtmlLog());
}

QString HTMLLogger::generateHtmlLog()
{
    return header + html.join("") + footer;
}

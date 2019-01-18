#ifndef READXML_H
#define READXML_H

#include <QtCore>
#include <QtXml>
#include <QDebug>
#include <QString>

#include "globaldata.h"

class ReadXML
{
public:
    ReadXML();

    GlobalData *g_data = GlobalData::getInstance();

    void ReadSystemXML();
    //read system.xml and save data into g_data
    QString getElements(QDomElement root, QString tagname, QString attribute);


    void ListElements(QDomElement root, QString tagname
                      ,QString attribute);

};

#endif // READXML_H

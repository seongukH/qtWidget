#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "strinfomation.h"


#include <QMap>
#include <QList>
#include <QDebug>

#include <QJsonArray>
#include <QJsonObject>

class GlobalData
{
public:
    virtual ~GlobalData();

    static GlobalData *getInstance();

    GlobalData();

    QString getXmlBookData(QString name);

    QMap<QString, QList<QString>> xmlBookData;

    QMap<int, QString> testData;

    InfoSystem infoSystem;

    QJsonArray recvNetwork;

};

#endif // GLOBALDATA_H

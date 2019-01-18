#ifndef GLOBALDATA_H
#define GLOBALDATA_H

#include "strinfomation.h"


#include <QMap>
#include <QList>
#include <QDebug>

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

};

#endif // GLOBALDATA_H

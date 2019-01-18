#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QtSql>
#include <QDateTime>

#include "globaldata.h"

class DBManager
{
public:
    GlobalData *g_data = GlobalData::getInstance();

    DBManager();

    QSqlDatabase db;


    void initConnection(QString ipAddr, QString userName,
                        QString passwd, QString dbName);
};

#endif // DBMANAGER_H

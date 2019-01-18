#include "dbmanager.h"

DBManager::DBManager()
{
    ///
}

void DBManager::initConnection(QString ipAddr, QString userName, QString passwd, QString dbName)
{
    if(db.isOpen()==false){

        db = QSqlDatabase::addDatabase("QMYSQL", "my_sql_db");
        db.setConnectOptions();

        db.setHostName(ipAddr);
        db.setDatabaseName(dbName);
        db.setUserName(userName);
        db.setPassword(passwd);
        db.setPort(3306);

        if(db.open()){
            qDebug()<<"db is open";
            qDebug("Connected");

        }
        else{
        qDebug()<<db.lastError();
        }//db.open

    }//db isOpen
    else{
        qDebug("DB was already connected!");
    }//db isOpne else





}


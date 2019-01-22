#ifndef UDPTEST_H
#define UDPTEST_H

#include <QObject>
#include <QUdpSocket>
#include <QTimer>

#include "globaldata.h"
//#include "strinfomation.h"

class UDPTest : public QObject
{
    Q_OBJECT
public:
    QTimer *timer;

    explicit UDPTest(QObject *parent = nullptr);


signals:

public slots:
    void readyRead();
    void sayHello();

    void init(QString ipaddr, int port);
    void sender(QByteArray bytearray);



private:
       QUdpSocket *socket;
       GlobalData *g_data = GlobalData::getInstance();

       locaionMessage locmessage;
};

#endif // UDPTEST_H

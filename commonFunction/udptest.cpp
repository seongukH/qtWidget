#include "udptest.h"


UDPTest::UDPTest(QObject *parent) : QObject(parent)
{
    /*
    socket = new QUdpSocket(this);
    socket->bind(QHostAddress::LocalHost, g_data->infoSystem.listenPort) ;
    //connect(socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    //timer = new QTimer(this);

    QTimer *timer = new QTimer(this);
          connect(timer, SIGNAL(timeout()), this, SLOT(readyRead()));
          timer->start(10);

          QTimer *Sendtimer = new QTimer(this);
                connect(Sendtimer, SIGNAL(timeout()), this, SLOT(sayHello()));
                Sendtimer->start(1000);
                */
}

void UDPTest::init(QString ipaddr, int port)
{


    //socket->bind(hostAddr, g_data->infoSystem.listenPort);
}

void UDPTest::sender(QByteArray bytearray)
{
    socket = new QUdpSocket(this);
    QHostAddress hostAddr = QHostAddress(g_data->infoSystem.ip_addr);

    //char *p = (char*)&bytearray;

    socket->writeDatagram(bytearray,hostAddr, g_data->infoSystem.listenPort);
    qDebug()<<"send bytearray : "+bytearray<<endl;
}


void UDPTest::sayHello()
{



    QByteArray Data;
    QHostAddress hostAddr = QHostAddress(g_data->infoSystem.ip_addr);



    locmessage.messageType = 0x01;
    locmessage.loc_x = 10.1;
    locmessage.loc_y = 9.1;
    locmessage.rotation = 90;

    //Data.append("Hello from udp land");
    char *p = (char*)&locmessage;

    //socket->writeDatagram(p, QHostAddress::LocalHost, g_data->infoSystem.listenPort);
    socket->writeDatagram(p,hostAddr, g_data->infoSystem.listenPort);

}



void UDPTest::readyRead()
{
    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());



    QHostAddress sender;
    quint16 senderPort;

    if(Buffer.length() != 0){
    socket->readDatagram(Buffer.data(), Buffer.size(), &sender, &senderPort);

    qDebug() <<"Message from: "<<sender.toString();
    qDebug() <<"Message port: "<<senderPort;
    qDebug() <<"Message : "<<Buffer;

    }



}

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
    m_port = port;
    m_ipaddr = ipaddr;

    socket = new QUdpSocket(this);
    socket->bind(QHostAddress(ipaddr), port) ;

    //socket->bind(hostAddr, g_data->infoSystem.listenPort);
}

QJsonObject UDPTest::readUDP(){

    QByteArray Buffer;
    Buffer.resize(socket->pendingDatagramSize());

    QHostAddress hostAddr = QHostAddress(m_ipaddr);

    if(Buffer.length() != 0){
    socket->readDatagram(Buffer.data(), Buffer.size(),
                         &hostAddr, &m_port);

    //qDebug() <<"Message from: "<<hostAddr;
    //qDebug() <<"Message port: "<<m_port;

    QJsonDocument itemDoc = QJsonDocument::fromBinaryData(Buffer);
    QJsonObject recvObject = itemDoc.object();

    //qDebug()<<recvObject;

    qDebug() <<"readUDP : Message : "<<recvObject;


    int temp1 = recvObject["loc_x"].toInt();

    qDebug()<<"recv item : "<<temp1<<endl;

    //locmessage = reinterpret_cast<locationMessage*>(Buffer);

    return recvObject;

    }
}

void UDPTest::sender(QByteArray bytearray)
{
    socket = new QUdpSocket(this);
    QHostAddress hostAddr = QHostAddress(g_data->infoSystem.ip_addr);

    //char *p = (char*)&bytearray;

    socket->writeDatagram(bytearray,hostAddr, g_data->infoSystem.listenPort);
    //ipaddr : 127.0.0.1,  port : 42424





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

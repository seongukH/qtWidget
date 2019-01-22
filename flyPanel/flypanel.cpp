#include "flypanel.h"
#include "ui_flypanel.h"

#include <QKeyEvent>


FlyPanel::FlyPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlyPanel)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);


    ui->graphicsView->setScene(scene);

    ui->lineEdit->text();

    //QKeyEvent *keyEvent;

   plain = new Plain;
    //Plain *plain;
    //locMessage = new locationMessage;

   scene->addRect(10,10, 30,30);


    //plain->setPos(netMsgTrack->pos_x,netMsgTrack->pos_y);

    //plain.setPos(10,10);
    scene->addItem(plain);

   // FlyPanel::sendUDP();

    //if(keyEvent->key() == Qt::Key_Down)
    //    qDebug()<<"space key pressed";

    sendUDP();





}

FlyPanel::~FlyPanel()
{
    timer->stop();
    qDebug()<<"timer stop3";

    delete ui;
}

void FlyPanel::on_pushButton_2_clicked()
{
    //qreal y = plain->y();
    //y = y-1;
    locMessage.loc_y = plain->y();
    locMessage.loc_y --;

    plain->setY(locMessage.loc_y);
}

void FlyPanel::sender()
{

    //locMessage->id = ui->lineEdit->text();

    //char *p = (char*)&locMessage;

    QJsonObject jsonObj;
    //QJsonDocument doc();
   // QString strJson(doc.)

    jsonObj["loc_x"] = 1;
    jsonObj["loc_y"] = 2;
    jsonObj["id"] = "idisid";



    char *p = jsonObj;



    qDebug()<<"locmessage.id : "<< locMessage.id;
    qDebug()<<"locmessage.x : "<<locMessage.loc_x;
    qDebug()<<"locmessage.y : "<<locMessage.loc_y;
    qDebug()<<"locmessage.header : "<<locMessage.header;

   // QByteArray sendBuffer = static_cast<QByteArray>(locMessage);


    //QByteArray byte = locMessage;

    qDebug()<<"sender slot : "<<&p;

    udpTest->sender(p);

}

void FlyPanel::sendUDP()
{
    udpTest = new UDPTest;
    //udpTest->init("127.0.0.1", g_data->infoSystem.listenPort);

    QByteArray buffer;
    buffer = "0x01";

    timer = new QTimer(this);
          connect(timer, SIGNAL(timeout()), this, SLOT(sender()));
          timer->start(1000);
}

void FlyPanel::closeEvent(QCloseEvent *event)
{
    timer->stop();
    qDebug()<<"timer stop4";
}



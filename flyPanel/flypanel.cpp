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

    //QKeyEvent *keyEvent;

   plain = new Plain;
    //Plain *plain;

   scene->addRect(10,10, 30,30);


    plain->setPos(110,100);

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
    qreal y = plain->y();
    y = y-1;

    plain->setY(y);
}

void FlyPanel::sender()
{
    qDebug()<<"sender slot : ok";

    udpTest->sender("aaabbb");
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

void FlyPanel::on_FlyPanel_destroyed()
{
    timer->stop();
    qDebug()<<"timer stop1";
}

void FlyPanel::on_FlyPanel_destroyed(QObject *arg1)
{
    timer->stop();
    qDebug()<<"timer stop2";


}

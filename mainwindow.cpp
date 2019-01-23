#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "mywidget.h"

#include "flyPanel/flypanel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //----------------------
    //----recve udp---------
    //----------------------

    udpTest = new UDPTest;
    udpTest->init("127.0.0.1", 42424);

    udpRecvTimer = new QTimer();
    connect(udpRecvTimer, SIGNAL(timeout()), this, SLOT(recvUDP()));
    udpRecvTimer->start(100);

   // jsonArray.append()

    //----------------------
    //----draw plain--------
    //----------------------
    scene = new QGraphicsScene(this);

    ui->graphicsView->setScene(scene);


    drawPlainTimer = new QTimer;
    connect( drawPlainTimer, SIGNAL(timeout()), this, SLOT(drawPlain()));
    drawPlainTimer->start(1000);


}



MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sayHello()
{
    qDebug()<<"hello";
}




void MainWindow::on_actionNew_Window_2_triggered()
{
    qDebug()<<"makeNewDialog";

    MyDialog mDialog;

    //mDialog.setModal(true);
    mDialog.exec();

}

void MainWindow::on_actionNew_Widget_triggered()
{
    qDebug()<<"make New widget";

    widget = new myWidget;

    widget->show();
}

void MainWindow::on_actionFly_Panel_triggered()
{
    flypanel = new FlyPanel;
    flypanel->show();
}

void MainWindow::recvUDP()
{
    QJsonObject recvJSON = udpTest->readUDP();

}

void MainWindow::drawPlain()
{
    scene->clear();

    for(int i=0; i<jsonArray.size(); i++){

        plain = new Plain;
        plain->setPos(10,30*i);
        plain->setRotation(i);
        scene->addItem(plain);

    }


}

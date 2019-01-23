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

    clearTimer = new QTimer;
    connect( clearTimer, SIGNAL(timeout()), this, SLOT(clearScene()));
    clearTimer->start(1000);


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
    //scene->clear();
    QJsonArray bufferArray;

    bufferArray = g_data->recvNetwork;

    for(int i=0; i<g_data->recvNetwork.size(); i++){    //remove g_data array
        g_data->recvNetwork.removeAt(0);
    }

    for(int i=0; i<bufferArray.size(); i++){

        scene->addRect(-5,-5, 10,10);

        qDebug()<<"recvNetworkArray : "<<bufferArray;

        plain = new Plain;

        plain->setPos(bufferArray.first()["loc_x"].toDouble(), bufferArray.first()["loc_y"].toDouble());
        plain->setRotation(i);
        scene->addItem(plain);

        bufferArray.removeFirst();


        //qDebug()<<g_data->recvNetwork;

    }

    //shoud be inside if



}

void MainWindow::clearScene()
{
    scene->clear();
}

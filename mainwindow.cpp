#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "mywidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    udpTest = new UDPTest;
    udpTest->init("127.0.0.1", 42424);

    udpRecvTimer = new QTimer();
    connect(udpRecvTimer, SIGNAL(timeout()), this, SLOT(recvUDP()));
    udpRecvTimer->start();

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
    udpTest->readUDP();
}

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mydialog.h"
#include "mywidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);



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

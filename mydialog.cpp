#include "mydialog.h"
#include "ui_mydialog.h"


MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);


    scene = new QGraphicsScene(this);
    track = new Track;


    ui->graphicsView->setScene(scene);
    ui->graphicsView->setDragMode(QGraphicsView::ScrollHandDrag);

    QPen blackpen(Qt::black);
    scene->addRect(10,10,  30,30, blackpen);
    scene->addText("hello world");

   // track->setPos(100,100);
    scene->addItem(track);

}

MyDialog::~MyDialog()
{
    delete ui;
}

void MyDialog::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.drawLine(10,10, 100,100);
}

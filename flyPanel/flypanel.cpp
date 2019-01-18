#include "flypanel.h"
#include "ui_flypanel.h"

FlyPanel::FlyPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlyPanel)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);


    ui->graphicsView->setScene(scene);

   plain = new Plain;
    //Plain *plain;

   scene->addRect(10,10, 30,30);


    plain->setPos(110,1100);

    //plain.setPos(10,10);
    scene->addItem(plain);



}

FlyPanel::~FlyPanel()
{
    delete ui;
}

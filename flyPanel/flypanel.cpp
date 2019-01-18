#include "flypanel.h"
#include "ui_flypanel.h"

FlyPanel::FlyPanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FlyPanel)
{
    ui->setupUi(this);
}

FlyPanel::~FlyPanel()
{
    delete ui;
}

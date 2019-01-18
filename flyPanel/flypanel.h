#ifndef FLYPANEL_H
#define FLYPANEL_H

#include <QWidget>

#include "plain.h"

namespace Ui {
class FlyPanel;
}

class FlyPanel : public QWidget
{
    Q_OBJECT

public:
    explicit FlyPanel(QWidget *parent = nullptr);
    ~FlyPanel();

private:
    Ui::FlyPanel *ui;

    QGraphicsScene *scene;
    Plain *plain;
};

#endif // FLYPANEL_H

#ifndef FLYPANEL_H
#define FLYPANEL_H

#include <QWidget>
#include <QDebug>
#include <QTimer>
#include <QJsonObject>


#include "plain.h"
#include "commonFunction/udptest.h"

#include "commonFunction/globaldata.h"

namespace Ui {
class FlyPanel;
}

class FlyPanel : public QWidget
{
    Q_OBJECT

public:
    explicit FlyPanel(QWidget *parent = nullptr);
    ~FlyPanel();

    void sendUDP();

    virtual void closeEvent(QCloseEvent *event);


private slots:
    void on_pushButton_2_clicked();
    void sender();



public slots:


private:
    Ui::FlyPanel *ui;

    QGraphicsScene *scene;
    Plain *plain;
    UDPTest *udpTest;
    GlobalData *g_data = GlobalData::getInstance();
    QTimer *timer;
    locationMessage locMessage;

    QString strRaw;
};

#endif // FLYPANEL_H






#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include <QMainWindow>
//#include <Spreadsheet>
#include <QLabel>
#include <QDebug>
#include <QTimer>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

#include "mywidget.h"
#include "flyPanel/flypanel.h"
#include "flyPanel/plain.h"

#include "commonFunction/udptest.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private: signals:

private slots:



    void sayHello();


    void on_actionNew_Window_2_triggered();

    void on_actionNew_Widget_triggered();

    void on_actionFly_Panel_triggered();

    void recvUDP();

    void drawPlain();

private:
    Ui::MainWindow *ui;

    QDialog *dialog;
    myWidget *widget;
    FlyPanel *flypanel;

    QTimer *udpRecvTimer;
    QTimer *drawPlainTimer;

    UDPTest *udpTest;

    QGraphicsScene *scene;

    Plain *plain;

    QJsonArray jsonArray;
};

#endif // MAINWINDOW_H

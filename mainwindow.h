#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include <QMainWindow>
//#include <Spreadsheet>
#include <QLabel>
#include <QDebug>

#include "mywidget.h"

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

private:
    Ui::MainWindow *ui;

    QDialog *dialog;
    myWidget *widget;

};

#endif // MAINWINDOW_H

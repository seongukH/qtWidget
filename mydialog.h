#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
#include <QtGui>
#include <QtCore>
#include <QGraphicsScene>

#include "track.h"


namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = nullptr);
    ~MyDialog();

private:
    Ui::MyDialog *ui;

    QGraphicsScene *scene;

    Track *track;

protected:
    void paintEvent(QPaintEvent *e);
};

#endif // MYDIALOG_H

#include "mainwindow.h"
#include <QApplication>

#include "commonFunction/readxml.h"

int main(int argc, char *argv[])
{
    ReadXML readXML;

    readXML.ReadSystemXML();


    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}

#include "mainwindow.h"

#include <QApplication>
#include<QGraphicsRectItem>
#include<QGraphicsScene>
#include<QGraphicsView>
#include<QLabel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setFixedSize(w.size());

    return a.exec();
}

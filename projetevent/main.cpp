#include "mainwindow.h"
#include "conncetion.h"
#include "QMessageBox"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
   c.createconnect();

    w.show();

    return a.exec();
}

#include "mainwindow.h"
#include "conncetion.h"
#include "QMessageBox"
#include <QApplication>
#include "QTranslator"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Connection c;
   c.createconnect();
   QTranslator T;
   QStringList languages;
         languages <<"French"<<"English";
         const QString lang=QInputDialog::getItem(NULL,"Select language ","Language",languages);
         if (lang=="English")

       {
            T.load(":/new/traduction/anglais.qm");
       }
       if (lang !="French")
       {
           a.installTranslator(&T);
       }
    w.show();

    return a.exec();
}

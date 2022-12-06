#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gestien.h"
#include "QString"
#include "QMessageBox"
#include "QPixmap"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->incorrect->hide();
    //int h=ui->labelpic->height();
     //  int w = ui->labelpic->width();
    //QPixmap pix("C:/Users/pc/Downloads/close-up-of-recording-video-with-smartphone-during-concert");
    //ui->labelpic->setPixmap(pix.scaled(h,w,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_login_clicked()
{
//      QString a=ui->lineEdituser->text();
    //  QString  p=ui->label_password->text();

      if(ui->lineEdituser->text()=="admin" && ui->lineEdit_password->text()=="admin")
      {
        gestien g;
        //this->hide();
        g.setModal(true);
        g.exec();
        ui->incorrect->hide();

      }
      else
      {
          ui->incorrect->show();

      }
 ui->lineEdit_password->clear();
}


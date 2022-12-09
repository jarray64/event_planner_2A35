#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "home.h"

#include <QMessageBox>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
home h(nullptr);
Connection  c;
QString login;
QString mdp;
login=ui->login->text();
mdp=ui->password->text();
 if(c.Authentification(login,mdp)==1)
{
   QMessageBox::information(this,"Connexion","login et mdp correcte");
 qDebug()<< "Mot de passe et login correct";
 this->hide();
 h.setModal(this);
 h.exec();
}
else
 if(c.Authentification(login,mdp)==0)
{
  QMessageBox::critical(this,"Connexion","login et mdp incorrecte");
  qDebug()<< "Mot de passe et login incorrect";
}
}



#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "societe.h"
#include <QMessageBox>
#include <QIntValidator>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
ui->le_contact->setValidator(new QIntValidator(0,99999999, this));
ui->tab_societe->setModel(S.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{
  int contact=ui->le_contact->text().toInt();
  QString nom=ui->le_nom->text();
  QString mail=ui->le_mail->text();
  QString fcb=ui->le_fcb->text();
  QString produit=ui->le_produit->text();
  Societe S(nom,mail,fcb,produit,contact);
  bool test=S.ajouter();
  if(test)
  {
      QMessageBox::information( nullptr, QObject::tr("ajout"),
                  QObject::tr("ajout successful.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("ajout"),
                  QObject::tr("ajout failed.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{

    Societe S1; S1.setnom(ui->le_nom_supp->text());
    bool test=S1.supprimer(S1.getnom());
    if(test)
    {
        QMessageBox::information( nullptr, QObject::tr("ajout"),
                    QObject::tr("suppression successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

  }
    else
        QMessageBox::critical(nullptr, QObject::tr("ajout"),
                    QObject::tr("suppression failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_2_clicked()
{
     Societe S1; S1.setnom(ui->le_nom_supp_2->text());
     S1.supprimer(S1.getnom());
}


void MainWindow::on_on_pb_modifier_clicked()
{

    int contact=ui->le_contact_2->text().toInt();
    QString nom=ui->le_nom_2->text();
    QString mail=ui->le_mail_2->text();
    QString fcb=ui->le_fcb_2->text();
    QString produit=ui->le_produit_2->text();
    Societe S(nom,mail,fcb,produit,contact);
    S.ajouter();

}


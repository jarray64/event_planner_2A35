#include "gestien.h"
#include "ui_gestien.h"
#include "evenement.h"
#include "QMessageBox"
#include "QPixmap"
gestien::gestien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestien)
{
    ui->setupUi(this);
   // int h=ui->labelpic->height();
   //    int w = ui->labelpic->width();
  //  QPixmap pix("C:/Users/pc/Desktop/projetevent/background_login");
   // ui->labelpic->setPixmap(pix.scaled(h,w,Qt::KeepAspectRatio));
    ui->tabWidget->hide();
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);
    ui->tableView->setModel(etmp.afficher());

    ui->lineEdit_id->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_idmod->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_sup->setValidator(new QIntValidator(0,99999999,this));
}

gestien::~gestien()
{
    delete ui;
}

void gestien::on_pushButton_2_clicked()
{
    //evenement e;
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(true);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);

ui->tabWidget->show();



//ui->pushButton_3->hide();
    //hide();
    //e.setModal(true);
    //e.exec();

}

void gestien::on_pushButton_5_clicked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(true);

ui->tabWidget->hide();
}

void gestien::on_pushButton_6_clicked()
{
        int id=ui->lineEdit_id->text().toInt();
    QString type=ui->lineEdit_type->text();
    QString place=ui->lineEdit_place->text();
    evenement E(id,type,place);
    bool test=E.ajouter();
    if (test)
    {
        ui->tableView->setModel(etmp.afficher());

       QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("OK"),
                                 QObject::tr("Ajout non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);

    ui->lineEdit_id->clear();
    ui->lineEdit_type->clear();
    ui->lineEdit_place->clear();
}

void gestien::on_pushButton_7_clicked()
{
    int id=ui->lineEdit_sup->text().toInt();
    bool test=etmp.supprimer(id);
    if (test)
    {
        ui->tableView->setModel(etmp.afficher());

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppresion effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr,QObject::tr("OK"),
                                 QObject::tr("suppresion non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);

ui->lineEdit_sup->clear();
}

void gestien::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_idmod->text().toInt();
    QString type=ui->lineEdit_typemod->text();
    QString place=ui->lineEdit_placemod->text();


    evenement E(id,type,place);
    bool test=E.modifier(id);
    ui->tableView->setModel(tmp.afficher());
 if(test){

    QMessageBox::information(nullptr,QObject::tr("OK"),
                             QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
}else{
     QMessageBox::information(nullptr,QObject::tr("OK"),
                              QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


 }

 ui->lineEdit_idmod->clear();
 ui->lineEdit_typemod->clear();
 ui->lineEdit_placemod->clear();
}

void gestien::on_pushButton_clicked()
{
    ui->pushButton->setChecked(true);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);

ui->tabWidget->hide();
}

void gestien::on_pushButton_4_clicked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(false);
    ui->pushButton_4->setChecked(true);
    ui->pushButton_5->setChecked(false);

ui->tabWidget->hide();
}

void gestien::on_pushButton_3_clicked()
{
    ui->pushButton->setChecked(false);
    ui->pushButton_2->setChecked(false);
    ui->pushButton_3->setChecked(true);
    ui->pushButton_4->setChecked(false);
    ui->pushButton_5->setChecked(false);

ui->tabWidget->hide();
}




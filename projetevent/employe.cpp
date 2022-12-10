#include "employe.h"
#include <QSqlQuery>
#include <QDebug>
#include <QObject>
#include<QPainter>
#include<QPdfWriter>
#include<QSystemTrayIcon>
#include<QMessageBox>
#include "notification.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QDebug>
#include <QDate>
#include<QPainter>
Employe::Employe()
{
    age=0;
keyperso=0;
nom=" ";
prenom="";
pass="";

}

 Employe::Employe(QString nom,int keyperso,QString prenom,QString pass,int age)
 {
     this->keyperso=keyperso;
     this->nom=nom;
     this->prenom=prenom;
     this->pass=pass;
     this->age=age;  }

 int Employe::get_age(){return age;}
 int Employe::get_keyperso(){return keyperso;}
 QString Employe::get_nom(){return nom;}
 QString Employe::get_prenom(){return prenom;}
 QString Employe::get_pass(){return pass;}

 void Employe::set_pass(QString pass){this->pass=pass;}
 void Employe::set_keyperso(int keyperso){this->keyperso=keyperso;}
 void Employe::set_nom(QString nom){this->nom=nom;}
 void Employe::set_prenom(QString prenom){this->prenom=prenom;}
 void Employe::set_age(int age){this->age=age;}

bool Employe::ajouter()
 {

    QString res=QString::number(keyperso);
QString res1=QString::number(age);
     QSqlQuery query;
          query.prepare("INSERT INTO EMPLOYEE (keyperso,nom,prenom,pass,age) "
                        "VALUES (:keyperso,:nom,:prenom,:pass,:age)");
          query.bindValue(":nom", nom);
          query.bindValue(":keyperso", res);
          query.bindValue(":prenom", prenom);
          query.bindValue(":pass", pass);
          query.bindValue(":age", res1);

        return  query.exec();


 }
QSqlQueryModel * Employe ::afficher()
{

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * FROM EMPLOYEE ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("KEYPERSO "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("pass "));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("age "));




        return model;
}


 bool Employe::supprimer(int keyperso)
 {
     QSqlQuery query;
     query.prepare("Delete from EMPLOYEE where keyperso=:keyperso");
     query.bindValue(":keyperso", keyperso);
  return   query.exec();
}
 bool Employe::modifier(int keyperso)
 {
     QString res=QString::number(keyperso);
QString res1=QString::number(age);
     QSqlQuery query;
     query.prepare("update  EMPLOYEE set  nom=:nom, age=:age,prenom=:prenom ,pass=:pass where keyperso=:keyperso " );
     query.bindValue(":keyperso", res);
     query.bindValue(":nom", nom);
     query.bindValue(":prenom", prenom);
     query.bindValue(":pass", pass);
     query.bindValue(":age", res1);

   return  query.exec();
 }




QSqlQueryModel* Employe::rechercheemp  (QString recherche)
{
     QSqlQueryModel * model= new QSqlQueryModel();
 model->setQuery("SELECT * FROM EMPLOYEE WHERE KEYPERSO LIKE '"+recherche+"%' OR age LIKE '"+recherche+"%' OR NOM LIKE '"+recherche+"%' OR PRENOM LIKE '"+recherche+"%'");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("KEYPERSONOM"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("PASS"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("age"));
 return model;
 }

 void  Employe::genererPDF(){
     QPdfWriter pdf("C:/Users/pc/Desktop/evant_planner2A35/projetevent/Pdf/employes.pdf");
     QPainter painter(&pdf);
    int i = 4000;
         painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 50));
         painter.drawText(1100,1200,"Liste Des employés");
         painter.setPen(Qt::black);
         painter.setFont(QFont("Arial", 15));
         painter.drawRect(100,100,7300,2600);
         painter.drawRect(0,3000,9600,500);
         painter.setFont(QFont("Arial", 9));
         painter.drawText(200,3300,"NOM ");
         painter.drawText(1300,3300,"KEYPERSO");
         painter.drawText(2400,3300,"PRENOM");
            painter.drawText(3500,3300,"PASS");


         QSqlQuery query;
         query.prepare("select * from EMPLOYEE");
         query.exec();
         while (query.next())
         {
             painter.drawText(200,i,query.value(0).toString());
             painter.drawText(1300,i,query.value(1).toString());
             painter.drawText(2400,i,query.value(2).toString());
             painter.drawText(3500,i,query.value(3).toString());



            i = i + 500;
         }


             QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

             notifyIcon->show();
             notifyIcon->showMessage("ALERTE NOTIF ","Un PDF a été crée",QSystemTrayIcon::Information,15000);


 }


 QSqlQueryModel * Employe::trieremp(QString test)
 {
     QSqlQueryModel * model=new QSqlQueryModel();
     if(test == "par défaut"){
         model->setQuery("SELECT * from employee");
     }
     else if(test =="nom")
     {
         model->setQuery("SELECT * from employee order by nom asc ");
     }
     else if(test =="prenom")
     {
         model->setQuery("SELECT * from employee order by prenom desc ");
     }
     else if(test =="cin")
     {
         model->setQuery("SELECT * from employee order by keyperso asc ");
     }
     else if(test =="age")
     {
         model->setQuery("SELECT * from employee order by age asc ");
     }
     return model;
 }


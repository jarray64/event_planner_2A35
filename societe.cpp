#include "societe.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
Societe::Societe()
{
contact=0; nom=""; mail=""; fcb=""; produit="";
}


Societe::Societe(QString nom,QString mail,QString fcb,QString produit,int contact)
{this->nom=nom; this->mail=mail; this->fcb=fcb; this->produit=produit; this->contact=contact;}
QString Societe::getnom(){return nom;}
QString Societe::getmail(){return mail;}
QString Societe::getfcb(){return fcb;}
QString Societe::getproduit(){return produit;}
int Societe::getcontact(){return contact;}

void Societe::setnom(QString nom){this->nom=nom;}
void Societe::setmail(QString mail){this->mail=mail;}
void Societe::setfcb(QString fcb){this->fcb=fcb;}
void Societe::setproduit(QString produit){this->produit=produit;}
void Societe::setcontact(int contact){this->contact=contact;}


bool Societe::ajouter()
{
    QSqlQuery query;
    QString contact_string= QString::number(contact);
    query.prepare("INSERT INTO marketing (nom, mail, fcb, produit, contact) "
                  "VALUES (:nom, :mail, :fcb, :produit, :contact)");
    query.bindValue(":nom", nom);
    query.bindValue(":mail", mail);
    query.bindValue(":fcb", fcb);
    query.bindValue(":produit", produit);
    query.bindValue(":contact", contact_string);
 return query.exec();
}



bool Societe::supprimer(QString nom)
{
    QSqlQuery query;
    query.prepare("delete from marketing where nom=:nom  ");

    query.bindValue(0, nom);

 return query.exec();
}




QSqlQueryModel* Societe::afficher()
{
 QSqlQueryModel* model=new QSqlQueryModel();

 model->setQuery("SELECT* FROM marketing");
 model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
 model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
 model->setHeaderData(2, Qt::Horizontal, QObject::tr("fcb"));
 model->setHeaderData(3, Qt::Horizontal, QObject::tr("produit"));
 model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));

 return model;
}

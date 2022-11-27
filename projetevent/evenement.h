#ifndef EVENEMENT_H
#define EVENEMENT_H
#include "iostream"
#include <QDialog>
#include "QString"
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include "QDateTime"
#include "arduino.h"
using namespace std;

namespace Ui {
class evenement;
}

class evenement : public QDialog
{
    QString type,place;
    int id,cinclient;
    QDateTime date_event;
public:

    evenement();
    evenement(int,QString,QString,QDateTime,int);
    QString getNom(){return type;}
    QString getPrenom(){return place;}
    int getID(){return id;}
    void setNom(QString n){type=n;}
    void setPrenom(QString p){place=p;}
    void setID(int id){this->id=id;}
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int id);
//void datecomp();

   QSqlQueryModel *trierevent(QString test);
   QSqlQueryModel *rechercherevent(QString test);
   int statistiqueevent(int month);

};

#endif // EVENEMENT_H

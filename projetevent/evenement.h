#ifndef EVENEMENT_H
#define EVENEMENT_H
#include "iostream"
#include <QDialog>
#include "QString"
#include <QSqlDatabase>
#include <QSqlQueryModel>
using namespace std;

namespace Ui {
class evenement;
}

class evenement : public QDialog
{
    QString type,place;
    int id;
public:
    evenement();
    evenement(int,QString,QString);
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
};

#endif // EVENEMENT_H

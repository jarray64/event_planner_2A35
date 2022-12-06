#ifndef SOCIETE_H
#define SOCIETE_H
#include <QString>
#include <QSqlQueryModel>
class Societe
{
public:
    Societe();
    Societe(QString,QString,QString,QString,int);
    QString getnom();
    QString getmail();
    QString getfcb();
    QString getproduit();
    int getcontact();

    void setnom(QString);
    void setmail(QString);
    void setfcb(QString);
    void setproduit(QString);
    void setcontact(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    QSqlQueryModel * rechercher(QString);
    bool supprimer(QString);
    bool modifier(QString );
private:
    QString nom,mail,fcb,produit;
    int contact;
};
class projeth
{
public:
       projeth() ;
       projeth(QString,QString,QString) ;
       QString get_nom();
       QString get_datee();
       QString get_fn();
       QSqlQueryModel * afficherhis() ;
       bool ajoutehis();
      // bool modifierhis() ;
       bool supprimerhis() ;
private:

    QString nom,datee,fn ;
};

#endif // SOCIETE_H

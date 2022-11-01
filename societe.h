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
    bool supprimer(QString);
private:
    QString nom,mail,fcb,produit;
    int contact;
};

#endif // SOCIETE_H

#ifndef PARTENAIRE_H
#define PARTENAIRE_H
#include <QString>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlQueryModel>

class partenaire
{
public:
    partenaire();
    partenaire(int,int,int,QString,QString);

    int getid();
    int getnum_partenaire();
    int getprix();
    QString getnom();
    QString getemail();

    void getid(int);
    void getnum_partenaire(int);
    void getprix(int);
    void getnom(QString);
    void getemail(QString);

    void setid(int);
    void setnum_partenaire(int);
    void setprix(int);
    void setnom(QString);
    void setemail(QString);



    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifierpartenaire(int id, int num_partenaire, int prix, QString nom, QString email);
    QSqlQueryModel * trierpartenaireParid();
    QSqlQueryModel * trierpartenairenom();
    QSqlQueryModel * trierpartenaireParnum_partenaire();
    QSqlQueryModel * Recherche(QString);




private:
    int id,num_partenaire,prix;
    QString nom,email;

};

#endif // PARTENAIRE_H

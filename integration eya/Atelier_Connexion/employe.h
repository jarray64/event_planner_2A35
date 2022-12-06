#ifndef EMPLOYE_H
#define EMPLOYE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include<QPrintDialog>
#include<QPainter>
#include<QTextDocument>
#include<QString>
#include<QSqlQueryModel>
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include<QPrinter>
#include<QPrintDialog>
#include<QPainter>
#include<QTextDocument>
class Employe
{
public:





    bool supprimer(int);
    bool modifier(int,QString,QString,QString,int);

    QSqlQueryModel* tri(QString,QString);
    QSqlQueryModel * rechercheemp(QString);
void genererPDF();
//new
QSqlQueryModel* afficher( int a,int);
Employe();
Employe(QString nom,int keyperso,QString prenom,QString pass,int age);
int get_keyperso();
QString get_nom();
QString get_pass();
QString get_prenom();
int get_age();
void set_pass(QString);
void set_keyperso(int);
void set_nom(QString);
void set_prenom(QString);
void set_age(int);
  bool ajouter();
  Employe chercher(int keyperso);
  bool persoExists(  int keyperso);
//
private:
    int keyperso;
    int age;
    QString pass,nom,prenom;
};

#endif // EMPLOYE_H

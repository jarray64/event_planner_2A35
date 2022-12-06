#ifndef HISTORIQUES_H
#define HISTORIQUES_H

#include<QString>
#include<QMessageBox>
#include <QDateTime>
#include <QFile>
#include <QTextStream>
#include <QDebug>


class Historiques
{
    QString Nom;
    QString Prenom;
    QString Gmail;
    QString cin;
    QString Numero ;
    QString tmp;
public:
    Historiques();
    Historiques(QString Nom, QString Prenom, QString Gmail, QString cin, QString Numero, QString tmp);

    void saveClient();
    QString loadClients();
    void saveUpdateClient(QString Nom, QString Prenom, QString Gmail, QString cin, QString Numero);
    void saveDeleteClient();
};

#endif // HISTORIQUES_H

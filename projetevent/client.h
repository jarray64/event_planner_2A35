#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQueryModel>
class CLIENT
{
public:
    CLIENT();
    CLIENT(QString ,QString, QString ,QString, QString );
    QString getNom();
    QString getPrenom();
    QString getcin();
    QString getNumero();
    QString getGmail();
    void setNom(QString);
    void setPrenom(QString);
    void setcin(QString);
    void setNumero(QString);
    void setGmail(QString);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprime(QString);
     bool modifier(QString);

     QSqlQueryModel *trierClient(QString test);
     int statistiqueCilents(int month);
     QSqlQueryModel * rechercherClient(QString chaine);
     QSqlQuery afficher(QString cin);

     int clientFidele();
     QSqlQuery clientFideleDetails();


private:
    QString Nom , Prenom , Gmail , cin , Numero ;
};

#endif // CLIENT_H

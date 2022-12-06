#include "client.h"
#include<QSqlQuery>
#include<QtDebug>
#include "QMessageBox"
CLIENT::CLIENT()
{
    cin="";
    Prenom="";
    Nom="";
    Numero="";
    Gmail="";
}
CLIENT::CLIENT (QString Nom ,QString Prenom, QString cin,QString Numero, QString Gmail )
{
    this->Nom=Nom;this->Prenom=Prenom;this->cin=cin;this->Numero=Numero;this->Gmail=Gmail;
}
void CLIENT::setcin(QString n){cin=n;}
void CLIENT::setPrenom(QString n){Prenom=n;}
void CLIENT::setNom(QString n){Nom=n;}
void CLIENT::setNumero(QString n){Numero=n;}
void CLIENT::setGmail(QString n){Gmail=n;}


QString CLIENT::getcin(){return cin;}
QString CLIENT::getPrenom(){return Prenom;}
QString CLIENT::getNom(){return Nom;}
QString CLIENT::getNumero(){return Numero;}
QString CLIENT::getGmail(){return Gmail;}



bool CLIENT::ajouter()
{
    QSqlQuery query;
    query.prepare("INSERT INTO CLIENT (NOM, PRENOM, cinclient,NUMERO,GMAIL) "
                  "VALUES (:Nom, :Prenom, :cin,:Numero,:Gmail)");
    query.bindValue(":Nom", Nom);
    query.bindValue(":Prenom", Prenom);
    query.bindValue(":cin", cin);
    query.bindValue(":Numero", Numero);
    query.bindValue(":Gmail", Gmail);
    return query.exec();

}


bool CLIENT:: supprime(QString cin)
{
    QSqlQuery query;
    query.prepare("Delete from CLIENT where cinclient=:cin");
    query.bindValue(":cin",cin);
    return query.exec();
    }

QSqlQueryModel * CLIENT::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("select *from CLIENT");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("CIN"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("PRENOM"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("NUMERO"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("GMAIL"));
    return model;

}

bool CLIENT::modifier(QString ){

    QSqlQuery query;


          query.prepare("UPDATE CLIENT "" SET cinclient=:cin, NOM=:nom, PRENOM=:prenom, NUMERO=:numero, GMAIL=:gmail"
                        " where cinclient=:cin ");


                query.bindValue(":cin", cin);
                query.bindValue(":nom", Nom);
                query.bindValue(":prenom", Prenom);
                query.bindValue(":gmail", Gmail);
                query.bindValue(":numero", Numero);

            return query.exec();

}

//**************************trie*******************************************
QSqlQueryModel * CLIENT::trierClient(QString test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(test == "par défaut"){
        model->setQuery("SELECT * from client");
    }
    else if(test =="nom")
    {
        model->setQuery("SELECT * from client order by nom asc ");
    }
    else if(test =="date")
    {
        model->setQuery("SELECT * from client order by dateC desc ");
    }
    else if(test =="prenom")
    {
        model->setQuery("SELECT * from client order by prenom asc ");
    }
    else if(test =="gmail")
    {
        model->setQuery("SELECT * from client order by gmail asc ");
    }
    return model;
}

//*******************************statistique Client********************************************************

int CLIENT::statistiqueCilents(int month)
{
    QSqlQuery query;
    query.prepare("select count(*) from client where extract(month from dateC)=:month ");
    query.bindValue(":month",month);
    query.exec();

    int count =-1;

            while(query.next())
                    {
                        count = query.value(0).toInt();
                    }

    return count;

}

//**************************recherche*****************************
QSqlQueryModel * CLIENT::rechercherClient(QString chaine)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from client where ( nom LIKE'%"+chaine+"%' OR prenom LIKE'%"+chaine+"%' OR numero LIKE'%"+chaine+"%' OR cinclient LIKE'%"+chaine+"%' OR gmail LIKE'%"+chaine+"%') ");


    return model ;
}



QSqlQuery CLIENT::afficher(QString cin)
{
    QSqlQuery query;
        query.prepare("select * from client where cinclient=:cin ");
        query.bindValue(":cin",cin);

        query.exec();
        return query;

}

//****************************************client fidele

int CLIENT::clientFidele(){
    QSqlQuery query;

    query.prepare("select max(myCount) from (select cinClient,count(cinClient) mycount from evenement group by cinClient ) ");

    query.exec();

    int count =-1;

            while(query.next())
                    {
                        count = query.value(0).toInt();
                    }

    return count;

}

QSqlQuery CLIENT::clientFideleDetails(){
    QSqlQuery query, query2;

    query.prepare("select cinClient, count(cinClient) from evenement group by cinClient having count (cinClient)=(select max(mycount) from(select cinClient, count(cinClient) mycount from evenement group by cinClient ) )   ");
    query.exec();
    query.next();

    query2.prepare("select * from CLIENT where cinclient=:cin ");
    query2.bindValue(":cin", query.value(0).toString());




    /*

    QString cin ="-1";

            while(query.next())
                    {
                        cin = query.value(0).toString();
                    }

    return cin;
*/
    query2.exec();
    return query2;

}















#include "conncetion.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("source_projet2A");
db.setUserName("SYSTEM");//inserer nom de l'utilisateur
db.setPassword("admin");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;





    return  test;
}


int Connection::Authentification(QString nom,QString pass)
{
    QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        QSqlQuery query2;

        query.prepare("SELECT KEYPERSO FROM EMPLOYEE WHERE NOM = \'"+nom+"\' AND PASS =\'"+pass+"\'");

        query.exec();

        if (query.next())
        {
             return 1;
        }

        else {
            return 0;
        }



}

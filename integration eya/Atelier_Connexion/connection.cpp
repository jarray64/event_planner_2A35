#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{bool test=false;
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("projet_2A");
db.setUserName("eya");//inserer nom de l'utilisateur
db.setPassword("eya");//inserer mot de passe de cet utilisateur

if (db.open())
test=true;

    return  test;
}
int Connection::Authentification(QString nom,QString pass)
{
    QSqlDatabase bd = QSqlDatabase::database();

        QSqlQuery query;
        QSqlQuery query2;

        query.prepare("SELECT KEYPERSO FROM G_PERSONNELS WHERE NOM = \'"+nom+"\' AND PASS =\'"+pass+"\'");

        query.exec();

        if (query.next())
        {
             return 1;
        }

        else {
            return 0;
        }



}
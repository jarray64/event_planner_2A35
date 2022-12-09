#ifndef CONNCETION_H
#define CONNCETION_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connection
{
public:
    Connection();
    bool createconnect();
    int Authentification(QString login,QString pwd);

};

#endif // CONNCETION_H

#include "evenement.h"
#include "gestien.h"
#include "QString"
#include <QSqlQuery>
evenement::evenement()
{
    id=0;
    type="";
    place="";
}
evenement::evenement(int id, QString type, QString place)
{
this->id=id;
this->type=type;
this ->place=place;
}
bool evenement::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);

    query.prepare("insert into evenement (ID,TYPE,PLACE )""values(:id,:type,:place)");
    query.bindValue(":id", res);
    query.bindValue(":type", type);
    query.bindValue(":place", place);
return query.exec();
}


QSqlQueryModel *evenement::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from evenement");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("PLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
return model;
}

bool evenement::supprimer(int id)
{
QSqlQuery query;
QString res=QString::number(id);
query.prepare("Delete from evenement where ID=:id");
query.bindValue(":id",res);
return query.exec();
}
bool evenement::modifier(int id){

    QSqlQuery query;
        QString res=QString::number(id);


          query.prepare("UPDATE evenement "" SET ID=:id, TYPE=:type, PLACE=:place where ID='"+res+"' ");


                query.bindValue(":id", res);
                query.bindValue(":type", type);
                query.bindValue(":place", place);

            return query.exec();

}




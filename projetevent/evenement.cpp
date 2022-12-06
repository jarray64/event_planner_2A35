#include "evenement.h"
#include "gestien.h"
#include "QString"
#include <QSqlQuery>
#include "QDateTime"
#include "QDebug"
#include "ui_gestien.h"

evenement::evenement()
{
    id=0;
    type="";
    place="";
    date_event=QDateTime::fromString("01.01.2000","DD.MM.YYYY");
    cinclient=0;

}
evenement::evenement(int id, QString type, QString place,QDateTime date,int cinclient)
{
this->id=id;
this->type=type;
this ->place=place;
this->date_event=date;
this->cinclient=cinclient;
}
bool evenement::ajouter()
{
    QSqlQuery query;
    QString res=QString::number(id);
QString res1=QString::number(cinclient);

    query.prepare("insert into evenement (ID,TYPE,PLACE,DATEE,CINCLIENT )""values(:id,:type,:place,:date_event,:cinclient)");
    query.bindValue(":id", res);
    query.bindValue(":type", type);
    query.bindValue(":place", place);
    query.bindValue(":date_event", date_event);
    query.bindValue(":cinclient", cinclient);
return query.exec();
}


QSqlQueryModel *evenement::afficher()
{
QSqlQueryModel *model=new QSqlQueryModel();
model->setQuery("select * from evenement");
model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
model->setHeaderData(1,Qt::Horizontal,QObject::tr("PLACE"));
model->setHeaderData(2,Qt::Horizontal,QObject::tr("TYPE"));
model->setHeaderData(3,Qt::Horizontal,QObject::tr("DATE"));
model->setHeaderData(4,Qt::Horizontal,QObject::tr("CINCLIENT"));
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
 QString res1=QString::number(cinclient);

          query.prepare("UPDATE evenement "" SET ID=:id, TYPE=:type, PLACE=:place , DATEE=:date, CINCLIENT=:cinclient where ID='"+res+"' ");


                query.bindValue(":id", res);
                query.bindValue(":type", type);
                query.bindValue(":place", place);
                query.bindValue(":date", date_event);
                query.bindValue(":cinclient", res1);


            return query.exec();

}



/*============TRI===============*/

QSqlQueryModel * evenement::trierevent(QString test)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    if(test == "par défaut"){
        model->setQuery("SELECT * from evenement");
    }
    else if(test =="type")
    {
        model->setQuery("SELECT * from evenement order by type asc ");
    }
    else if(test =="date")
    {
        model->setQuery("SELECT * from evenement order by datee desc ");
    }
    else if(test =="place")
    {
        model->setQuery("SELECT * from evenement order by PLACE asc ");
    }
    else if(test =="id")
    {
        model->setQuery("SELECT * from evenement order by id asc ");
    }
    return model;
}
/*============================*/
QSqlQueryModel * evenement::rechercherevent(QString chaine)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("SELECT * from evenement where ( id LIKE'%"+chaine+"%' OR type LIKE'%"+chaine+"%' OR place LIKE'%"+chaine+"%' OR datee LIKE'%"+chaine+"%') ");


    return model ;
}

/*=======stat=================*/

int evenement::statistiqueevent(int month)
{
    QSqlQuery query;
    query.prepare("select count(*) from evenement where extract(month from datee)=:month ");
    query.bindValue(":month",month);
    query.exec();

    int count =-1;

            while(query.next())
                    {
                        count = query.value(0).toInt();
                    }

    return count;

}

//===============================0noticfication
/*void evenement::datecomp()
{
    int d=QDate::currentDate().month();
        QSqlQuery query;
        query.prepare("select datee from evenement where extract(month from datee) =:date");

      query.bindValue(":date",d);

        query.exec();

        query.next();

       QString dateE=query.value(0).toString();
       if (dateE!="")
           //return 1 ;
       else
       //    return 0;




}
*/

#include "partenaire.h"

partenaire::partenaire()
{

    id=0; num_partenaire=0; prix=0;nom="";email="";

}
partenaire::partenaire(int i,int n,int p,QString no,QString e)
{
   id=i;
   num_partenaire=n;
   prix=p;
   nom=no;
   email=e;

}
int partenaire::getid(){return id;}
int partenaire::getnum_partenaire(){return num_partenaire;}
int partenaire::getprix(){return prix;}
QString partenaire::getnom(){return nom;}
QString partenaire::getemail(){return email;}


void partenaire::setid(int id){this->id=id;}
void partenaire::setnum_partenaire(int num_partenaire){this->num_partenaire=num_partenaire;}
void partenaire::setprix(int prix){this->prix=prix;}
void partenaire::setnom(QString nom){this->nom=nom;}
void partenaire::setemail(QString email){this->email=email;}


bool partenaire::ajouter()
{


QSqlQuery query;
QString id_string= QString::number(id);
query.prepare("INSERT INTO PARTENAIRE (id,numero,prix,nom,mail) "
              "VALUES (:id, :num_partenaire, :prix, :nom,:email)");

 query.bindValue(":id", id); //remplir id dans id
 query.bindValue(":num_partenaire", num_partenaire);
  query.bindValue(":prix", prix);
 query.bindValue(":nom",nom);
 query.bindValue(":email",email);

 return query.exec();



}
QSqlQueryModel * partenaire::afficher()
{ QSqlQueryModel * model=new QSqlQueryModel();

    model->setQuery("select * from partenaire");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));


    return  model;

}
bool partenaire::supprimer(int id)
{

    QSqlQuery query;
    QString res=QString::number(id);
    query.prepare("DELETE FROM partenaire WHERE ID= :id");
    query.bindValue(":id",res);
    return query.exec();

}
bool partenaire::modifierpartenaire(int id, int num_partenaire, int prix, QString nom, QString email)

{



    QSqlQuery query;

    query.prepare("update partenaire set numero=:num_partenaire,prix=:prix,nom=:nom,mail=:email where id=:id");

    query.bindValue(":id",id);
    query.bindValue(":num_partenaire",num_partenaire);
    query.bindValue(":prix",prix);
    query.bindValue(":nom",nom);

    query.bindValue(":email",email);



    return query.exec();



}

//Trie Par id
QSqlQueryModel * partenaire::trierpartenaireParid()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM partenaire order by id ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}

//Trie Par nom
QSqlQueryModel * partenaire::trierpartenairenom()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("partenaire * FROM partenaire order by nom ASC");
           q->exec();
           model->setQuery(*q);
           return model;

}

//Trie Par num_partenaire
QSqlQueryModel * partenaire::trierpartenaireParnum_partenaire()
{

    QSqlQuery * q = new  QSqlQuery ();
           QSqlQueryModel * model = new  QSqlQueryModel ();
           q->prepare("SELECT * FROM partenaire order by num_partenaire ASC");
           q->exec();
           model->setQuery(*q);
           return model;
}
QSqlQueryModel * partenaire::Recherche(QString a)
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM partenaire WHERE (ID LIKE '%"+a+"%' OR numero LIKE '%"+a+"%' OR prix LIKE '%"+a+"%' OR nom LIKE '%"+a+"%' OR mail LIKE '%"+a+"%' ) ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("numero"));
       model->setHeaderData(2,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("email"));


    return model;
}




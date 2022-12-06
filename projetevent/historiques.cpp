#include "historiques.h"

Historiques::Historiques()
{

}


Historiques::Historiques(QString Nom, QString Prenom, QString Gmail, QString cin, QString Numero, QString tmp){
    this->Nom = Nom;
    this->Prenom = Prenom;
    this->Gmail = Gmail;
    this->cin = cin;
    this->Numero = Numero;
    this->tmp = tmp;
}


void Historiques::saveClient(){
    QFile file ("C:/Users/pc/Desktop/evant_planner2A35/projetevent/historique.txt");
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n Nom: "+Nom + ", Prenom: " +Prenom+ ", Gmail: " +Gmail+ ", cin: " +cin +", Numero: " +Numero<< "\n" "un nouveau client a etat ajouter le " +sDate << "\n";
}

void Historiques::saveUpdateClient(QString nom, QString prenom, QString gmail, QString Cin, QString numero){
    QFile file ("C:/Users/pc/Desktop/evant_planner2A35/projetevent/historique.txt");
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n""*****************************************Update********************************";
    out << "\n Nom: "+Nom + ", Prenom: " +Prenom+ ", Gmail: " +Gmail+ ", cin: " +cin +", Numero: " +Numero;
    out << "\n Nom: "+nom + ", Prenom: " +prenom+ ", Gmail: " +gmail+ ", cin: " +Cin +", Numero: " +numero<< "\n" "Cet client a été modifié le " +sDate << "\n";
    out <<"*****************************************Update********************************" "\n";

}


void Historiques::saveDeleteClient(){
    QFile file ("C:/Users/pc/Desktop/evant_planner2A35/projetevent/historique.txt");
    if (!file.open(QIODevice::WriteOnly|  QIODevice::Append | QIODevice::Text))
        return;

    QTextStream out(&file);
    out.setCodec("UTF-8");
    QString sDate = QDateTime::currentDateTime().toString("dddd dd MMMM yyyy hh:mm:ss.zzz");
    out << "\n Nom: "+Nom + ", Prenom: " +Prenom+ ", Gmail: " +Gmail+ ", cin: " +cin +", Numero: " +Numero<< "\n" "Cet client a été supprimé le " +sDate << "\n";

}



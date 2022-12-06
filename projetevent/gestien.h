#ifndef GESTIEN_H
#define GESTIEN_H

#include <QDialog>
#include "evenement.h"
#include <QDialog>
#include "popup.h"
#include "QDataWidgetMapper"
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include "client.h"
#include "arduino.h"
#include "notification.h"
#include "partenaire.h"
#include"qrcode.h"
namespace Ui {
class gestien;
}

class gestien : public QDialog
{
    Q_OBJECT

public:
    explicit gestien(QWidget *parent = nullptr);
    ~gestien();

private slots:




    void on_pushButton_modifier_clicked();








    void on_pushButton_lab_clicked();

    void on_pushButton_ev_clicked();

    void on_pushButton_prt_clicked();

    void on_pushButton_mrk_clicked();

    void on_pushButton_emp_clicked();

    void on_pushButton_cl_clicked();

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_hide_clicked();

    void on_trie_commande_clicked();


    void on_chercherevent_textChanged();

    void on_genpdf_clicked();

    void on_stats_clicked();



    void on_logoutBtn_clicked();

    void on_excel_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_map_clicked();
     void setcin_combo();

     void on_mail_clicked();
     void sendMail();
     void mailsent(QString);
     void browse();

     void notification();

     void on_addimg_clicked();



     void on_clientadd_clicked();

     void on_pushButton_2_clicked();

     void on_pushButton_3_clicked();

     void on_rechercherClient_textChanged(const QString &arg1);

     void on_trierClientBtn_clicked();

     void on_pdfClient_clicked();

     void on_historiqueClient_clicked();

     void on_clientFidele_clicked();

     void on_tableView_2_clicked(const QModelIndex &index);

     void on_pushButton_clicked();



     void on_ajouter_partenair_clicked();

     void on_suprimer_partenair_clicked();

     void on_tableView_3_clicked(const QModelIndex &index);

     void on_fichier_xl_clicked();

     void on_pushButton_5_clicked();


     void on_rechercher_partenaire_textChanged(const QString &arg1);

     void on_trier_partenaire_activated();

     void on_modifier_partenair_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();
     void sendMailpart();
     void mailsentpart(QString);
     void browsepart();



     void on_statistique_clicked();

private:
    Ui::gestien *ui;
    evenement etmp;
    evenement tmp;
  QStringList files;
  PopUp *popUp;
  CLIENT c,c1;
  Arduino A;
  Arduino B;

partenaire p;
};

#endif // GESTIEN_H

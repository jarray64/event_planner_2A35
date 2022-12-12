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
#include "societe.h"
#include <QMainWindow>
#include <QMediaPlaylist>
#include <QMediaPlayer>//pub
#include <QVideoWidget>//pub
#include <QAbstractVideoSurface>
#include <QFileDialog>   //pup
#include <QProgressBar>  //pub
#include <QSlider>//pub
#include <QTranslator>
#include<QComboBox>
#include <QDialog>
 #include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include "employe.h"
#include "mainwindow.h"
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
//   void smscheck();



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

     void on_rechercherClient_textChanged();

     void on_trierClientBtn_clicked();

     void on_pdfClient_clicked();

     void on_historiqueClient_clicked();

     void on_clientFidele_clicked();

     void on_tableView_2_clicked(const QModelIndex &index);

    // void on_pushButton_clicked();



     void on_ajouter_partenair_clicked();

     void on_suprimer_partenair_clicked();

     void on_tableView_3_clicked(const QModelIndex &index);

     void on_fichier_xl_clicked();

     void on_pushButton_5_clicked();


     void on_rechercher_partenaire_textChanged(const QString &arg1);



     void on_modifier_partenair_clicked();

     void on_pushButton_7_clicked();

     void on_pushButton_6_clicked();
     void sendMailpart();
     void mailsentpart(QString);
     void browsepart();



     void on_statistique_clicked();



     void on_add_mark_clicked();

     void on_mod_mark_clicked();

     void on_pdf_mark_clicked();

     void on_browse_mark_clicked();

     void on_tableView_4_clicked(const QModelIndex &index);

     void on_del_mark_clicked();

     void on_triemark_clicked();

     void on_recherchemark_textChanged(const QString &arg1);

     void on_parametreee_clicked();



     void on_play_2_clicked();

     void on_pause_2_clicked();

     void on_stop_2_clicked();

     void on_mute_2_clicked();

     void on_volume_2_valueChanged(int value);

     void on_tableView_5_clicked(const QModelIndex &index);

     void on_pb_ajouter_3_clicked();

     void on_supprimer_keyperso_btn_clicked();

     void on_pb_modifier_7_clicked();

     void on_trieemp_clicked();

     void on_recherceremp_textChanged(const QString &arg1);

     void on_pushButton_8_clicked();

     void on_pushButton_9_clicked();

     void on_pushButton_10_clicked();

     void on_pushButton_4_clicked();

private:
    Ui::gestien *ui;
    evenement etmp;

  QStringList files;
  PopUp *popUp;
  CLIENT c,c1;
  Arduino A;
  Arduino B;
  QByteArray data;

partenaire p;

Societe S,S1;
QMediaPlayer* player;//pub
QVideoWidget* vw;//pub
QMediaPlayer * mMediaPlayer;
QTranslator *translator=new QTranslator;
projeth tmp;
Employe emp;

};

#endif // GESTIEN_H

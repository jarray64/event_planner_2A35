#ifndef HOME_H
#define HOME_H
#include <QMainWindow>
#include <QMediaPlayer>//pub
#include <QVideoWidget>//pub
#include <QFileDialog>   //pup
#include <QProgressBar>  //pub
#include <QSlider>//pub
#include <QTranslator>
#include<QComboBox>
#include <QDialog>
 #include <QPieSlice>
#include <QPieSeries>
#include <QtCharts>
#include "societe.h"
#include "arduino.h"
#include"employe.h"
namespace Ui {
class home;
}
class QMediaPlayer;
class home : public QDialog
{
    Q_OBJECT

public:
    explicit home(QWidget *parent = nullptr);
    ~home();
private slots:

 void on_pushButton_clicked();
 void on_pushButton_2_clicked();

void on_pushButton_5_clicked();



    void on_pb_ajouter_4_clicked();







    void on_radio_keyperso_clicked();

    void on_radio_nom_clicked();

    void on_radio_age_clicked();

    void on_supprimer_keyperso_btn_2();

    void on_chercher_modifier_3_clicked();

    void on_pb_modifier_8_clicked();

    void on_tabWidget_2_currentChanged(int index);


    void on_decroissant_clicked();

    void on_croissant_5_clicked();

    void on_pushButton_10_clicked();

    void on_reset_ajouter_6_clicked();

    void on_reset_ajouter_5_clicked();



     /////////////////////////anis////////////////////////////////////////////////

    void on_pb_ajouter_clicked();

    void on_pb_modifier_2_clicked();
    void on_pb_supprimer_clicked();

    void on_historique_clicked();


    void on_home_2_clicked();

    void on_parametre_clicked();


    void on_apropos_clicked();
    void on_browse_clicked();

    void on_ouvrir_clicked() ;


    void on_play_clicked();


    void on_pause_clicked();


    void on_stop_clicked();


    void on_mute_clicked();


    void on_volume_valueChanged(int) ;

    void on_re_afficher_clicked();


    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_jour_toggled(bool);

    void on_radioButton_nuit_toggled(bool);

    void on_Historiqueanis_clicked();


    void on_pb_recherche_clicked();


    void on_pdf_clicked();


    void on_marketing_clicked();

    void on_employee_clicked();



    void on_ouvrir_2_clicked();
    void on_fermer_clicked();
    void on_on_clicked();
    void on_off_clicked();
    void on_auto_clicked();
    void update_label();



private:
    Ui::home *ui;
    Employe em;
    int order =1;
    int ho=1;
     /////////////////////////anis////////////////////////////////////////////////
    Societe S;
    QMediaPlayer* player;//pub
    QVideoWidget* vw;//pub

    QMediaPlayer * mMediaPlayer;
    QTranslator *translator=new QTranslator;
    projeth tmp;

    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire

 };

#endif // HOME_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>//pub
#include <QVideoWidget>//pub
#include <QFileDialog>   //pup
#include <QProgressBar>  //pub
#include <QSlider>//pub
#include <QTranslator>
#include<QComboBox>
#include "societe.h"
#include "arduino.h"
namespace Ui {
class MainWindow;
}
class QMediaPlayer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

  //  QMediaPlayer * mMediaPlayer = new QMediaPlayer(this);

private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_2_clicked();

    void on_home_clicked();

    void on_parametre_clicked();

    void on_apropos_clicked();

    void on_historique_clicked();





    void on_browse_clicked();//pub


    void on_ouvrir_clicked();

    void on_play_clicked();

    void on_pause_clicked();

    void on_stop_clicked();

    void on_mute_clicked();

    void on_volume_valueChanged(int value);

    void on_radioButton_2_clicked();

    void on_radioButton_4_clicked();

    void on_re_afficher_clicked();

    void on_radioButton_7_clicked();

    void on_radioButton_6_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_jour_toggled(bool checked);

    void on_radioButton_nuit_toggled(bool checked);

    void on_Historiqueanis_clicked();

    void on_pb_recherche_clicked();

    ///////////////////////////arduino
    void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
    // ce slot est lancé à chaque réception d'un message de Arduino

    void on_pushButton_clicked();   // bouton ON

    void on_pushButton_2_clicked(); // bouton OFF

    void on_pushButton_3_clicked(); // bouton +

    void on_pushButton_4_clicked(); // bouton -

    void on_pdf_clicked();

//    void on_refresh_clicked();

    void on_pushButton_5_clicked();






private:
    Ui::MainWindow *ui;
    Societe S;
    QMediaPlayer* player;//pub
    QVideoWidget* vw;//pub

    QMediaPlayer * mMediaPlayer;
    QTranslator *translator=new QTranslator;
    projeth tmp;

    QByteArray data; // variable contenant les données reçues
    Arduino A; // objet temporaire

};

#endif // MAINWINDOW_H

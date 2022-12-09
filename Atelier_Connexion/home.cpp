#include "home.h"
#include "ui_home.h"
 #include "employe.h"
#include "societe.h"
#include "arduino.h"

#include<QGraphicsView>
#include<QtPrintSupport/QPrintDialog>
#include<QPdfWriter>
#include<QSqlQueryModel>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include<QMediaPlayer>
#include<QUrlQuery>
#include <QDate>
#include<QMessageBox>
#include<QSqlTableModel>
#include <QtPrintSupport/QPrinter>
#include <QDesktopServices>
#include <QCoreApplication>
#include <QSqlDatabase>
#include <qmessagebox.h>
#include <QSqlQuery>
#include <QIntValidator>
#include <QValidator>
#include "QMessageBox"
#include<QPrinter>
#include<QPrintDialog>
#include "notification.h"
#include <QtCharts>
#include <QChartView>
#include <QPieSeries>
#include <QSqlQuery>
#define file_rx  ("^[A-Za-z ]+$")
home::home(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::home)
{
    ui->setupUi(this);

     ui->tab_chercher_2->setModel(em.afficher(-1,1));
ui->age_ajout-> setValidator( new QIntValidator(0, 99, this));
ui->keyperso_ajout-> setValidator( new QIntValidator(0, 999999, this));


ui->prenom_ajout->setValidator(new QRegExpValidator( QRegExp(file_rx),this));
ui->pass_ajout->setValidator(new QRegExpValidator( QRegExp(file_rx),this));
ui->nom_ajout->setValidator(new QRegExpValidator( QRegExp(file_rx),this));
mMediaPlayer = new QMediaPlayer(this);

/////////////////////////////////////////////////anis////////////////////////////////////////////////////////////////////////////////////

/*connect(mMediaPlayer, &QMediaPlayer::positionChanged,[&](qint64 ){
    //ui->avancement->setValue(pos);
});*/
QString path="C:/Users/MSI/Desktop/projet QT/image/12.WAV";
mMediaPlayer->setMedia(QUrl::fromLocalFile(path));
mMediaPlayer->setVolume(ui->volume->value());
on_play_clicked();


ui->le_contact->setValidator(new QIntValidator(0,999999999, this));
ui->tab_societe->setModel(S.afficher());
ui->tab_his->setModel(tmp.afficherhis()) ;

player = new QMediaPlayer(this);//pub

vw = new QVideoWidget(this);//pub

if (home::on_marketing_clicked())
{
player->setVideoOutput(vw);
     vw->setGeometry(520,1,623,230);
 QString pathVideo="C:/Users/MSI/Desktop/projet QT/image/coffeepub.mp4";
 player->setMedia(QUrl::fromLocalFile(pathVideo));
player->play();//pub
}





////////////////////////arduino

int ret=A.connect_arduino(); // lancer la connexion à arduino
switch(ret){
case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
   break;
case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
  break;
case(-1):qDebug() << "arduino is not available";
}
QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
//le slot update_label suite à la reception du signal readyRead (reception des données).



}

home::~home()
{
    delete ui;
}




void home::on_pushButton_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}

void home::on_pushButton_2_clicked()
{

    em.genererPDF();
}
/*void MainWindow::on_le_keyperso_3_textChanged(const QString &arg1)
{
    ui->tableView->setModel(em.recherche(arg1));
}
*/
void home::on_pushButton_4_clicked()
{
    {
            QSqlQueryModel * model= new QSqlQueryModel();
                             model->setQuery("select * from EMPLOYEE where AGE < 18 ");
                             float code=model->rowCount();
                             model->setQuery("select * from EMPLOYEE where AGE  between 18 and 50 ");
                             float codee=model->rowCount();
                             model->setQuery("select * from EMPLOYEE where AGE >50 ");
                             float codeee=model->rowCount();
                             float total=code+codee+codeee;
                             QString a=QString("moins de 18 \t"+QString::number((code*100)/total,'f',2)+"%" );
                             QString b=QString("entre 18 et 50 \t"+QString::number((codee*100)/total,'f',2)+"%" );
                             QString c=QString("+50 \t"+QString::number((codeee*100)/total,'f',2)+"%" );
                             QPieSeries *series = new QPieSeries();
                             series->append(a,code);
                             series->append(b,codee);
                             series->append(c,codeee);
                     if (code!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if ( codee!=0)
                     {
                              // Add label, explode and define brush for 2nd slice
                              QPieSlice *slice1 = series->slices().at(1);
                              //slice1->setExploded();
                              slice1->setLabelVisible();
                     }
                     if(codeee!=0)
                     {
                              // Add labels to rest of slices
                              QPieSlice *slice2 = series->slices().at(2);
                              //slice1->setExploded();
                              slice2->setLabelVisible();
                     }
                             // Create the chart widget
                             QChart *chart = new QChart();
                             // Add data to chart with title and hide legend
                             chart->addSeries(series);
                             chart->setTitle("Pourcentage Par AGE :Nombre Des PERSONNELS "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);
                             chartView->show();



        }
}





/*void Dialog::on_pushButton_8_clicked()
{
ui->stackedWidget->setCurrentIndex(4);
QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("SELECT * FROM userr order by userr_keyperso  ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("userr_keyperso"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("username"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("password"));

ui->tableView->setModel(model);
}*/

void home::on_pb_ajouter_3_clicked()
{Notification n;
   QString nom= ui->nom_ajout->text();
   int keyperso= ui->keyperso_ajout->text().toInt() ;
   QString prenom= ui->prenom_ajout->text() ;
   QString pass= ui->pass_ajout->text();
   int age= ui->age_ajout->text().toInt();

Employe e(nom,keyperso,prenom,pass,age);
      bool test=e.ajouter();
     if (test)
     {     n.notification_ajout();
                  QMessageBox::information(nullptr, QObject::tr("OK"),
                             QObject::tr("ajout effectué.\n"
                                         "Click Cancel to exit."), QMessageBox::Cancel);}
                 else
                    { QMessageBox::critical(nullptr, QObject::tr("not OK"),
                                 QObject::tr("ajout failed.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);
        n.notification_ajoutpas();}
         ui->nom_ajout->clear();
      ui->keyperso_ajout->clear();
        ui->prenom_ajout->clear();
          ui->pass_ajout->clear();
          ui->age_ajout->clear();
   ui->tab_chercher_2->setModel(em.afficher(-1,this->order));
}


void home::on_radio_keyperso_clicked()
{    int a=1;
     if(!ui->croissant_5->isChecked()){a=-1;}
    ui->tab_chercher_2->setModel(em.afficher(0,a));
ho=1;
}

void home::on_radio_nom_clicked()
{
   int a=1;
     if(!ui->croissant_5->isChecked()){a=-1;}
    ui->tab_chercher_2->setModel(em.afficher(1,a));
ho=2;
}

void home::on_radio_age_clicked()
{    int a=1;
      if(!ui->croissant_5->isChecked()){a=-1;}
    ui->tab_chercher_2->setModel(em.afficher(2,a));
ho=3;
}

void home::on_supprimer_keyperso_btn_clicked()
{
    //supprimer_keyperso
    Employe e1;
    e1=e1.chercher(ui->supprimer_keyperso->text().toInt());

        if(e1.get_nom()!="user not found")
      {Notification n;

            n.notification_supprimer();
 em.supprimer(ui->supprimer_keyperso->text().toInt());
 QMessageBox::information(nullptr, QObject::tr("supprimer une animateur"),
  QObject::tr("animateur supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);
       ui->supprimer_keyperso->clear();
 ui->tab_chercher_2->setModel(em.afficher(-1,this->order));
      }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("supprimer une animateur"),
                        QObject::tr("animateur introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }


}

void home::on_chercher_modifier_2_clicked()
{
    Employe e1;
    e1=e1.chercher(ui->keyperso_modifier_2->text().toInt());

        if(e1.get_nom()!="user not found")
      {


           ui->keyperso_modifier->setText( QString::number(e1.get_keyperso()));
           ui->nom_modifier->setText(  (e1.get_nom()));
           ui->prenom_modifier->setText( e1.get_prenom());
           ui->pass_modifier->setText( e1.get_pass());
           ui->age_modifier->setText( QString::number(e1.get_age()));


      }
        else
        {
         ui->keyperso_modifier->clear();
         ui->nom_modifier->clear();
         ui->prenom_modifier->clear();
             ui->pass_modifier->clear();
               ui->age_modifier->clear();

            QMessageBox::critical(nullptr, QObject::tr("chercher une animateur"),
                        QObject::tr("animateur introuvable !.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

        }
}

void home::on_pb_modifier_7_clicked()
{Notification n;
    QString nom= ui->nom_modifier->text();
    int keyperso= ui->keyperso_modifier->text().toInt() ;
    QString prenom= ui->prenom_modifier->text() ;
    QString pass= ui->pass_modifier->text();
    int age= ui->age_modifier->text().toInt();


Employe e(nom,keyperso,prenom,pass,age);
  Employe m1;
  bool test=m1.persoExists(keyperso);
  qDebug() <<test<<"test";
  if(test==true)
  {int test1=m1.modifier(keyperso,nom,prenom,pass,age);
      if(test1==true){n.notification_modifier();
          QMessageBox::information(nullptr, QObject::tr("modifier une mession"),
                            QObject::tr("mession modifié.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
     ui->tab_chercher_2->setModel(em.afficher(-1,this->order));
      }
      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un modifé"),
                      QObject::tr("Erreur de modification!.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }

  }

      else
      {
          QMessageBox::critical(nullptr, QObject::tr("Supprimer un employee"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

      }
}

void home::on_tabWidget_2_currentChanged(int index)
{
    ui->tab_chercher_2->setModel(em.afficher(-1,this->order));
}


void home::on_decroissant_clicked()
{   int a=1;
    if(ui->radio_age->isChecked()){a=5;}else if(ui->radio_age->isChecked()){a=0;}

         ui->tab_chercher_2->setModel(em.afficher(a,-1));
}

void home::on_croissant_5_clicked()
{
   int a=1;
    if(ui->radio_age->isChecked()){a=5;}else if(ui->radio_age->isChecked()){a=0;}
        ui->tab_chercher_2->setModel(em.afficher( a,1));
}

void home::on_pushButton_10_clicked()
{
    QPrinter  printer;
        printer.setPrinterName("test");
        QPrintDialog dialog(&printer,this);
        if (dialog.exec()==QDialog::Rejected) return;
}

void home::on_reset_ajouter_6_clicked()
{
    ui->nom_modifier->clear();
 ui->keyperso_modifier->clear();
   ui->prenom_modifier->clear();
     ui->pass_modifier->clear();
     ui->age_modifier->clear();


}

void home::on_reset_ajouter_5_clicked()
{
    ui->nom_ajout->clear();
 ui->keyperso_ajout->clear();
   ui->prenom_ajout->clear();
     ui->pass_ajout->clear();
     ui->age_ajout->clear();
}


/////////////////////////////////////////////anis/////////////////////////////////////////////////////

void home::on_pb_ajouter_clicked()
{


  QString nom=ui->le_nom->text();
  QString mail=ui->le_mail->text();
  QString fcb=ui->le_fcb->text();
  QString produit=ui->le_produit->text();
  int contact=ui->le_contact->text().toInt();


Societe S(nom,mail,fcb,produit,contact);

  bool test=S.ajouter();
  if(test)
  {
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->showMessage("MARKETING ","marketing ajouté",QSystemTrayIcon::Information,15000);
              srand (time(NULL));
              QDate d = QDate::currentDate() ;
               QString datee =d.toString("dd / MM / yyyy ") ;
               QString fn="ajouter" ;
              QString nom1 = ui->le_nom->text();
            projeth pp(nom1,datee,fn) ;
            bool test1=pp.ajoutehis() ;
}
else
  {
            QSystemTrayIcon *notifyIcon= new QSystemTrayIcon;
                          notifyIcon->show();
      notifyIcon->showMessage("MARKETING ","marketing non ajouté",QSystemTrayIcon::Information,15000);
  }
          ui->le_nom->clear();
          ui->le_mail->clear();
          ui->le_fcb->clear();
          ui->le_produit->clear();
          ui->le_contact->clear();
}

void home::on_pb_supprimer_clicked()
{

    Societe S1; S1.setnom(ui->le_nom_supp->text());
    bool test=S1.supprimer(S1.getnom());
    QString nom;
    if(S1.supprimer(nom))
    {
    srand (time(NULL));
    QDate d = QDate::currentDate() ;
     QString datee =d.toString("dd / MM / yyyy ") ;
     QString fn="supprimer" ;
    QString nom1 = ui->le_nom_supp->text();
  projeth pp(nom1,datee,fn) ;
  bool test1=pp.supprimerhis() ;
    }
    if(test)
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                notifyIcon->show();
                notifyIcon->showMessage("MARKETING ","marketing supprimé",QSystemTrayIcon::Information,15000);

  }
    ui->le_nom_supp->clear();

}

void home::on_pb_modifier_2_clicked()
{
    int contact=ui->le_contact->text().toInt();
    QString nom=ui->le_nom->text();
    QString mail=ui->le_mail->text();
    QString fcb=ui->le_fcb->text();
    QString produit=ui->le_produit->text();


    Societe S (nom,mail,fcb,produit,contact);

      bool test=S.modifier(nom);

      if(test)
      {
          QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
                  notifyIcon->show();
                  notifyIcon->showMessage("MARKETING ","marketing modifié",QSystemTrayIcon::Information,15000);
                  srand (time(NULL));
                  QDate d = QDate::currentDate() ;
                   QString datee =d.toString("dd / MM / yyyy ") ;
                   QString fn="modifier" ;
                  QString nom1 = ui->le_nom->text();
                projeth pp(nom1,datee,fn) ;
                bool test1=pp.ajoutehis() ;
    }

              ui->le_nom->clear();
              ui->le_mail->clear();
              ui->le_fcb->clear();
              ui->le_produit->clear();
              ui->le_contact->clear();


}




void home::on_historique_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(3);

}

void home::on_home_2_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);

}

void home::on_parametre_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);

}


void home::on_apropos_clicked()
{
     ui->stackedWidget_2->setCurrentIndex(0);

}


bool home::on_marketing_clicked()
{
        ui->stackedWidget->setCurrentIndex(0);

       player->setVideoOutput(vw);
            vw->setGeometry(520,1,623,230);
        QString pathVideo="C:/Users/MSI/Desktop/projet QT/image/coffeepub.mp4";
        player->setMedia(QUrl::fromLocalFile(pathVideo));
       player->play();//pub




}

void home::on_employee_clicked()
{
        ui->stackedWidget->setCurrentIndex(1);
        vw->setGeometry(1,0,0,0);
  //  player->setVideoOutput(vw);

    QString pathVideo="C:/Users/MSI/Desktop/projet QT/image/coffeepub.mp4";
    player->setMedia(QUrl::fromLocalFile(pathVideo));
    player->play();//pub


}






void home::on_browse_clicked()//pub
{


    QString filename = QFileDialog::getOpenFileName(this,"open a file","","video file (*.avi, *.mpg, *.mp4");

    player->setMedia(QUrl::fromLocalFile(filename));
    player->play();

}

void home::on_ouvrir_clicked() //music
{
  //  QMediaPlayer * mMediaPlayer = new QMediaPlayer(this);

    QString filename = QFileDialog::getOpenFileName(this,"ouvrir");
    if (filename.isEmpty())
    {return;}
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->volume->value());
    on_play_clicked();
}

void home::on_play_clicked()
{
     mMediaPlayer->play();
}

void home::on_pause_clicked()
{
     mMediaPlayer->pause();
}

void home::on_stop_clicked()
{
       mMediaPlayer->stop();
        mMediaPlayer->play();
}

void home::on_mute_clicked()
{
    if(ui->mute->text()=="mute"){
    mMediaPlayer->setMuted(true);
    ui->mute->setText("unmute");
    }else {mMediaPlayer->setMuted(false);
        ui->mute->setText("mute");
    }
}

void home::on_volume_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}




void home::on_re_afficher_clicked()
{
            ui->tab_societe->setModel(S.afficher());
}


void home::on_radioButton_2_clicked()
{
    {QMessageBox msgBox ;
            QSqlQueryModel * model= new QSqlQueryModel();


               model->setQuery("select * from marketing order by nom");

               model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
               model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
               model->setHeaderData(2, Qt::Horizontal, QObject::tr("fcb"));
               model->setHeaderData(3, Qt::Horizontal, QObject::tr("produit"));
               model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));


                        ui->tab_societe->setModel(model);
                        ui->tab_societe->show();


        }
}


void home::on_radioButton_4_clicked()
{
    QMessageBox msgBox ;
        QSqlQueryModel * model= new QSqlQueryModel();



           model->setQuery("select * from marketing order by produit");

           model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
           model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
           model->setHeaderData(2, Qt::Horizontal, QObject::tr("fcb"));
           model->setHeaderData(3, Qt::Horizontal, QObject::tr("produit"));
           model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));

                    ui->tab_societe->setModel(model);
                    ui->tab_societe->show();

}




void home::on_radioButton_7_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();



       model->setQuery("select * from marketing order by mail");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("fcb"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("produit"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));

                ui->tab_societe->setModel(model);
                ui->tab_societe->show();
}

void home::on_radioButton_6_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();



       model->setQuery("select * from marketing order by fcb");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("fcb"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("produit"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));

                ui->tab_societe->setModel(model);
                ui->tab_societe->show();
}

void home::on_radioButton_5_clicked()
{

    QSqlQueryModel * model= new QSqlQueryModel();



       model->setQuery("select * from marketing order by contact");

       model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
       model->setHeaderData(1, Qt::Horizontal, QObject::tr("mail"));
       model->setHeaderData(2, Qt::Horizontal, QObject::tr("fcb"));
       model->setHeaderData(3, Qt::Horizontal, QObject::tr("produit"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("contact"));

                ui->tab_societe->setModel(model);
                ui->tab_societe->show();
}



void home::on_radioButton_jour_toggled(bool checked)
{
    this->setStyleSheet("font: 12pt \"Tekton pro\";"
                        "color: rgb(255, 255, 255);");

        QList<QPushButton *> butts = this->findChildren<QPushButton *>();

        for (int i=0; i<butts.size();i++)
        {
            butts.at(i)->setStyleSheet("QPushButton { background-color: rgb(0,102,204); }");
        }
       /* QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

        for (int i=0; i<tabs.size();i++)
        {
            tabs.at(i)->setStyleSheet("QTabBar::tab { background-color: rgb(0,102,204);}");
        }*/
}

void home::on_radioButton_nuit_toggled(bool checked)
{

        this->setStyleSheet("font: 12pt \"Tekton pro\";"
                            "color: rgb(255, 255, 255);");



        QList<QPushButton *> butts = this->findChildren<QPushButton *>();

        for (int i=0; i<butts.size();i++)
        {
            butts.at(i)->setStyleSheet("QPushButton { background-color: rgb(0,76,153); }");
        }


  /*     QList<QTabWidget *> tabs = this->findChildren<QTabWidget *>();

        for (int i=0; i<tabs.size();i++)
        {
            tabs.at(i)->setStyleSheet("QTabBar::tab { color: rgb(0,76,153);}");
        }
*/

}




void home::on_Historiqueanis_clicked()
{
    ui->tab_his->setModel(tmp.afficherhis()) ;
    ui->tab_his->setModel(tmp.afficherhis());//refresh
}





void home::on_pb_recherche_clicked()
{
    QString rech =ui->le_nom_supp->text();
   ui->tab_societe->setModel(S.rechercher(rech));
      ui->le_nom_supp->clear();
}





void home::on_pdf_clicked()
{
    QPdfWriter pdf("C:/Users/MSI/Desktop/projet QT/pdf/anis.pdf");
                       QPainter painter(&pdf);
                      int i = 4000;
                           painter.setPen(Qt::red);
                           painter.setFont(QFont("Comic Sans MS", 30));
                           painter.drawText(1100,1100,"Liste Des marketing");
                           painter.setPen(Qt::blue);
                           painter.setFont(QFont("Comic Sans MS", 50));
                           painter.drawRect(100,100,7300,1900);
                           painter.drawPixmap(QRect(7200,70,2600,2200),QPixmap("C:/Users/MSI/Desktop/projet QT/image/new"));
                           painter.setPen(Qt::blue);

                           painter.drawRect(0,3000,9600,500);
                           painter.setPen(Qt::darkGreen);

                           painter.setFont(QFont("Calibri", 15));
                           painter.drawText(200,3300,"nom");
                           painter.drawText(1800,3300,"mail");
                           painter.drawText(3300,3300,"fcb");
                           painter.drawText(5300,3300,"produit");
                           painter.drawText(6800,3300,"contact");




                           QSqlQuery query;
                           query.prepare("select * from MARKETING");
                           query.exec();
                           while (query.next())
                           {
                               painter.setPen(Qt::blue);
                               painter.drawText(200,i,query.value(0).toString());
                               painter.setPen(Qt::black);
                               painter.drawText(1800,i,query.value(1).toString());
                               painter.drawText(3300,i,query.value(2).toString());
                               painter.drawText(5300,i,query.value(3).toString());
                               painter.drawText(6800,i,query.value(4).toString());
                               painter.setPen(Qt::red);

                               painter.drawText(8300,i,query.value(5).toString());



                              i = i + 500;
                           }
                           int reponse = QMessageBox::question(this, "Génerer PDF", "PDF Enregistré! -Voulez-Vous Affichez Le PDF ?",QMessageBox::Yes |  QMessageBox::No);
                               if (reponse == QMessageBox::Yes)
                               {
                                   QDesktopServices::openUrl(QUrl::fromLocalFile("C:/Users/MSI/Desktop/projet QT/pdf/anis.pdf"));
                                   painter.end();
                               }
                               if (reponse == QMessageBox::No)
                               {
                                    painter.end();
                               }
}

///////////////////////////////////arduino
void home::update_label()
{
    data=A.read_from_arduino();

    if(data=="15")
{
        ui->temperature->setText("  15°"); // si les données reçues de arduino via la liaison série sont égales à 1
    // alors afficher ON
}
    else if (data=="16")
    {
                ui->temperature->setText("  16°");
    }
    else if (data=="17")
    {
                ui->temperature->setText("  17°");
    }
    else if (data=="18")
    {
                ui->temperature->setText("  18°");
    }
    else if (data=="19")
    {
                ui->temperature->setText("  19°");
    }
    else if (data=="20")
    {
                ui->temperature->setText("  20°");
    }
    else if (data=="21")
    {
                ui->temperature->setText("  21°");
    }

    else if (data=="22")
    {

        ui->temperature->setText("  22°");   // si les données reçues de arduino via la liaison série sont égales à 0
     //alors afficher ON
}
else if (data=="23")
{
            ui->temperature->setText("  23°");
}

    else if (data=="24")
    {
                ui->temperature->setText("  24°");
    }

    else if (data=="25")
    {
                ui->temperature->setText("  25°");
    }

    else if (data=="26")
    {
                ui->temperature->setText("  26°");
    }

    else if (data=="27")
    {
                ui->temperature->setText("  27°");
    }
    else if (data=="28")
    {
                ui->temperature->setText("  28°");
    }
    else if (data=="29")
    {
                ui->temperature->setText("  29°");
    }


}


void home::on_ouvrir_2_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("1"); //envoyer 1 à arduino

      QString porte="ouvert" ;
      QSqlQuery query;
      query.prepare("INSERT INTO ALARME (PORTEEE) "
                    "VALUES (:porte)");
      query.bindValue(":porte", porte);

          query.exec();

}


void home::on_fermer_clicked()  // implémentation du slot bouton off
{

     A.write_to_arduino("0");  //envoyer 0 à arduino

                    A.write_to_arduino("7");


                     QString porte="fermer" ;

                     QSqlQuery query;
                     query.prepare("INSERT INTO ALARME (PORTEEE) "
                                   "VALUES (:porte)");
                     query.bindValue(":porte", porte);

                         query.exec();

}


void home::on_on_clicked()  // implémentation du slot bouton +
{
    A.write_to_arduino("2");   //envoyer 2 à arduino

}


void home::on_off_clicked() // implémentation du slot bouton -
{
    A.write_to_arduino("3");  //envoyer 3 à arduino
}


void home::on_auto_clicked()
{
      A.write_to_arduino("4");
}




///////////////////////////////////////////////////////////////////////////////////


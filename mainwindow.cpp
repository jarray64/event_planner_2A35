#include "mainwindow.h"
#include "ui_mainwindow.h"
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





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    mMediaPlayer = new QMediaPlayer(this);


    connect(mMediaPlayer, &QMediaPlayer::positionChanged,[&](qint64 ){
        //ui->avancement->setValue(pos);
    });
    QString path="C:/Users/MSI/Desktop/projet QT/image/12.WAV";
    mMediaPlayer->setMedia(QUrl::fromLocalFile(path));
    mMediaPlayer->setVolume(ui->volume->value());
    on_play_clicked();


ui->le_contact->setValidator(new QIntValidator(0,999999999, this));
ui->tab_societe->setModel(S.afficher());
    ui->tab_his->setModel(tmp.afficherhis()) ;


player = new QMediaPlayer(this);//pub

vw = new QVideoWidget(this);//pub

vw->setGeometry(330,12,723,150);
player->setVideoOutput(vw);
QString pathVideo="C:/Users/MSI/Desktop/projet QT/image/coffeepub.mp4";
player->setMedia(QUrl::fromLocalFile(pathVideo));
player->play();//pub


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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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

void MainWindow::on_pb_modifier_2_clicked()
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




void MainWindow::on_historique_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_home_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_parametre_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_apropos_clicked()
{
     ui->stackedWidget->setCurrentIndex(0);
}









void MainWindow::on_browse_clicked()//pub
{


    QString filename = QFileDialog::getOpenFileName(this,"open a file","","video file (*.avi, *.mpg, *.mp4");

    player->setMedia(QUrl::fromLocalFile(filename));
    player->play();

}

void MainWindow::on_ouvrir_clicked() //music
{
  //  QMediaPlayer * mMediaPlayer = new QMediaPlayer(this);

    QString filename = QFileDialog::getOpenFileName(this,"ouvrir");
    if (filename.isEmpty())
    {return;}
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
    mMediaPlayer->setVolume(ui->volume->value());
    on_play_clicked();
}

void MainWindow::on_play_clicked()
{
     mMediaPlayer->play();
}

void MainWindow::on_pause_clicked()
{
     mMediaPlayer->pause();
}

void MainWindow::on_stop_clicked()
{
       mMediaPlayer->stop();
        mMediaPlayer->play();
}

void MainWindow::on_mute_clicked()
{
    if(ui->mute->text()=="mute"){
    mMediaPlayer->setMuted(true);
    ui->mute->setText("unmute");
    }else {mMediaPlayer->setMuted(false);
        ui->mute->setText("mute");
    }
}

void MainWindow::on_volume_valueChanged(int value)
{
    mMediaPlayer->setVolume(value);
}




void MainWindow::on_re_afficher_clicked()
{
            ui->tab_societe->setModel(S.afficher());
}


void MainWindow::on_radioButton_2_clicked()
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


void MainWindow::on_radioButton_4_clicked()
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




void MainWindow::on_radioButton_7_clicked()
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

void MainWindow::on_radioButton_6_clicked()
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

void MainWindow::on_radioButton_5_clicked()
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



void MainWindow::on_radioButton_jour_toggled(bool checked)
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

void MainWindow::on_radioButton_nuit_toggled(bool checked)
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




void MainWindow::on_Historiqueanis_clicked()
{
    ui->tab_his->setModel(tmp.afficherhis()) ;
    ui->tab_his->setModel(tmp.afficherhis());//refresh
}





void MainWindow::on_pb_recherche_clicked()
{
    QString rech =ui->le_nom_supp->text();
   ui->tab_societe->setModel(S.rechercher(rech));
      ui->le_nom_supp->clear();
}





void MainWindow::on_pdf_clicked()
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
void MainWindow::update_label()
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


void MainWindow::on_pushButton_clicked()   // implémentation du slot bouton on
{
     A.write_to_arduino("1"); //envoyer 1 à arduino

      QString porte="ouvert" ;
      QSqlQuery query;
      query.prepare("INSERT INTO ALARME (PORTEEE) "
                    "VALUES (:porte)");
      query.bindValue(":porte", porte);

          query.exec();

}


void MainWindow::on_pushButton_2_clicked()  // implémentation du slot bouton off
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


void MainWindow::on_pushButton_3_clicked()  // implémentation du slot bouton +
{
    A.write_to_arduino("2");   //envoyer 2 à arduino

}


void MainWindow::on_pushButton_4_clicked() // implémentation du slot bouton -
{
    A.write_to_arduino("3");  //envoyer 3 à arduino
}


void MainWindow::on_pushButton_5_clicked()
{
      A.write_to_arduino("4");
}




///////////////////////////////////////////////////////////////////////////////////



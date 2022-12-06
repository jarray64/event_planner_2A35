 #include "gestien.h"
#include "ui_gestien.h"
#include "evenement.h"
#include "QMessageBox"
#include "QPixmap"
#include "QGraphicsDropShadowEffect"
#include "QGraphicsBlurEffect"
#include "QDateTime"
#include "QMessageBox"
#include "QSqlQuery"
#include "QPdfWriter"
#include "QPainter"
#include "client.h"
#include "mainwindow.h"
#include "exportexcelobject.h"
#include <QDebug>
#include <QSslSocket>
#include "smtp.h"
#include "popup.h"
#include "historiques.h"
#include "arduino.h"
#include"notification.h"
 notification N;
 QString test,test1;
 int occ=0;

gestien::gestien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestien)
{
    int ret=A.connect_arduino(); // lancer la connexion à arduino
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
     break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
   case(-1):qDebug() << "arduino is not available";
}

    popUp= new PopUp();

    ui->setupUi(this);
notification();
smscheck();
    ui->pushButton_prt->setChecked(false);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_emp->setChecked(false);
    ui->pushButton_mrk->setChecked(false);
   ui->tableView->setModel(etmp.afficher());
   ui->tableView_3->setModel(p.afficher());
    ui->lineEdit_id->setValidator(new QIntValidator(0,99999999,this));
    ui->lineEdit_id->setValidator(new QIntValidator(0,99999999,this));
                                      /*===============EFFFECTS=============================*/



    QGraphicsDropShadowEffect *effect1 = new QGraphicsDropShadowEffect;
        effect1->setBlurRadius(20);
        effect1->setXOffset(2);
        effect1->setYOffset(2);
        effect1->setColor(Qt::lightGray);
    QGraphicsDropShadowEffect *effect = new QGraphicsDropShadowEffect;
            effect->setBlurRadius(20);
            effect->setXOffset(2);
            effect->setYOffset(2);
            effect->setColor(Qt::lightGray);
            QGraphicsDropShadowEffect *effect3 = new QGraphicsDropShadowEffect;
                    effect3->setBlurRadius(20);
                    effect3->setXOffset(2);
                    effect3->setYOffset(2);
                    effect3->setColor(Qt::lightGray);
                    QGraphicsDropShadowEffect *effect5 = new QGraphicsDropShadowEffect;
                            effect5->setBlurRadius(20);
                            effect5->setXOffset(2);
                            effect5->setYOffset(2);
                            effect5->setColor(Qt::lightGray);
                            QGraphicsDropShadowEffect *effect2 = new QGraphicsDropShadowEffect;
                                    effect2->setBlurRadius(20);
                                    effect2->setXOffset(2);
                                    effect2->setYOffset(2);
                                    effect2->setColor(Qt::green);
                                    QGraphicsDropShadowEffect *effect4 = new QGraphicsDropShadowEffect;
                                            effect4->setBlurRadius(20);
                                            effect4->setXOffset(2);
                                            effect4->setYOffset(2);
                                            effect4->setColor(Qt::red);
                              /*===================end effects=====*/
    ui->tricombo->setGraphicsEffect(effect5);
    ui->groupBox->setGraphicsEffect(effect1);
    ui->groupBox_3->setGraphicsEffect(effect);
    ui->chercherevent->setGraphicsEffect(effect3);
    ui->label_done->setGraphicsEffect(effect2);
    ui->label_wrong->setGraphicsEffect(effect4);
    /*=====================effects ============0*/
    ui->label_cl->hide();
    ui->loginlab->show();
    ui->eventlab->hide();
    ui->label_done->hide();
    ui->label_wrong->hide();
    ui->pushButton_hide->hide();
    ui->label_lab->show();
    ui->label_prt->hide();
    ui->label_ev->hide();
    ui->label_mrk->hide();
    ui->label_emp->hide();
    ui->pushButton_ev->setFocus();
    ui->WebBrowser->hide();
    ui->tab_client->hide();
    ui->tabpartenaire->hide();
    ui->mailframe->hide();
    QWidget::setWindowTitle("E-event");
    QWidget::setWindowOpacity(50);


  /*======trieitem=========*/
  ui->tricombo->addItem("par défaut");
  ui->tricombo->addItem("id");
  ui->tricombo->addItem("date");
  ui->tricombo->addItem("type");
  ui->tricombo->addItem("place");
                          //======================================stasss======================
  QBarSet *set1 = new QBarSet("Nombre de evenement par mois");
  int id=0;
  QString type="";
  QString place="";
QDateTime date=QDateTime::fromString("01.01.2000","MM.DD.YYYY");
int cinclient=0;
   evenement E(id,type,place,date,cinclient);

      *set1 <<  E.statistiqueevent(1)
            <<  E.statistiqueevent(2)
            <<  E.statistiqueevent(3)
            <<  E.statistiqueevent(4)
            << E.statistiqueevent(5)
            << E.statistiqueevent(6)
            << E.statistiqueevent(7)
            << E.statistiqueevent(8)
            << E.statistiqueevent(9)
            << E.statistiqueevent(10)
            << E.statistiqueevent(11)
            << E.statistiqueevent(12) ;



          QBarSeries *series = new QBarSeries();

          series->append(set1);

          QColor color(227, 227, 227);
          set1->setColor(color);


          QChart *chart = new QChart();

              chart->addSeries(series);
              chart->setTitle("");
             chart->setBackgroundVisible(false);

                 QStringList categories;
              categories << "Jan" << "Fiv" << "Mar" << "Avr" << "Mai" << "Juin" << "Jui" <<"Aou" << "sep" << "Oct" << "Nov" << "Dec" ;
              QBarCategoryAxis *axis = new QBarCategoryAxis();


              axis->append(categories);

              chart->createDefaultAxes();
              chart->setAxisX(axis, series);


              chart->setVisible(true);
              chart->legend()->setAlignment(Qt::AlignBottom);


              QChartView *chartView = new QChartView(chart);

              chartView->setRenderHint(QPainter::Antialiasing);
              QPalette pal = qApp->palette();

              chartView->setMaximumWidth(1000);
              chartView->setMaximumHeight(290);

              chartView->setParent(ui->statfarme);
              chartView->show();
//===================================================================
          /*   QSqlQueryModel *model=new QSqlQueryModel();
              model->setQuery("select cinclient from client");
            int n=model->rowCount();
            for (int i=0;i<n;i++)
            {
                ui->combcin->model()->data(,i)
                qDebug() <<  combo -> currentText();
                ui->combcin->addItem(model->data(value(4).toString())
}
*/
              QBarSet *set2 = new QBarSet("Nombre de clients par mois");

              QString cin="";
              QString nom="";
              QString prenom="";
              QString numero="";
              QString gmail="";

               CLIENT c(nom,prenom,cin,numero,gmail);

                  *set2 <<  c.statistiqueCilents(1)
                        <<  c.statistiqueCilents(2)
                        <<  c.statistiqueCilents(3)
                        <<  c.statistiqueCilents(4)
                        << c.statistiqueCilents(5)
                        << c.statistiqueCilents(6)
                        << c.statistiqueCilents(7)
                        << c.statistiqueCilents(8)
                        << c.statistiqueCilents(9)
                        << c.statistiqueCilents(10)
                        << c.statistiqueCilents(11)
                        << c.statistiqueCilents(12) ;

                      //qDebug()<< c.statistiqueCilents(2);

                      QBarSeries *series1 = new QBarSeries();

                      series1->append(set2);

                      QColor color1(0x6568F3);
                      set2->setColor(color1);


                      QChart *chart1 = new QChart();

                          chart1->addSeries(series1);
                          chart1->setTitle("");
                         chart1->setBackgroundVisible(false);

                             QStringList categories1;
                          categories1 << "Jan" << "Fiv" << "Mar" << "Avr" << "Mai" << "Juin" << "Jui" <<"Aou" << "sep" << "Oct" << "Nov" << "Dec" ;
                          QBarCategoryAxis *axis1 = new QBarCategoryAxis();


                          axis1->append(categories1);

                          chart1->createDefaultAxes();
                          chart1->setAxisX(axis1, series1);


                          chart1->setVisible(true);
                          chart1->legend()->setAlignment(Qt::AlignBottom);


                          QChartView *chartView1 = new QChartView(chart1);

                          chartView1->setRenderHint(QPainter::Antialiasing);
                          QPalette pal1 = qApp->palette();

                          chartView1->setMaximumWidth(650);
                          chartView1->setMaximumHeight(290);


                          chartView1->setMinimumSize(561,331);
                          chartView1->setParent(ui->statclient);
                          chartView1->show();


                          //*******************add trie options**************************
                              ui->clientComboBox->addItem("par défaut");
                              ui->clientComboBox->addItem("nom");
                              ui->clientComboBox->addItem("prenom");
                              ui->clientComboBox->addItem("date");
                              ui->clientComboBox->addItem("gmail");
                          //*******************add trie options***************************

                        ui->tableView->setModel(c.afficher());
                          QString trieOption=ui->clientComboBox->currentText();
                          ui->tableView_2->setModel(c.trierClient(trieOption));


                          ui->lineEdit_cin->setValidator(new QIntValidator(0,99999999,this));
                          ui->lineEdit_Numero->setValidator(new QIntValidator(0,99999999,this));


              //maillllll
              connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
              connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));









              /****************************************************************/

              //ui->stackedWidget_2->setCurrentIndex(1);
                 QSqlQueryModel * model= new QSqlQueryModel();
                 model->setQuery("select * from partenaire where prix < 500 ");
                 float place1=model->rowCount();
                 model->setQuery("select * from partenaire where prix  between 500 and 1500 ");
                 float place2=model->rowCount();
                 model->setQuery("select * from partenaire where prix > 1500 ");
                 float place3=model->rowCount();
                 float total=place1+place2+place3;

                 QString a=QString("inferier 500 DT . "+QString::number((place1*100)/total,'f',2)+"%" );
                 QString b=QString("entre 500 et 1500 DT.  "+QString::number((place2*100)/total,'f',2)+"%" );
                 QString cc=QString("plus de 1500 DT.   "+QString::number((place3*100)/total,'f',2)+"%" );

                 QPieSeries *series2 = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
                 series2->append(a,place1);
                 series2->append(b,place2);//concatiner 2 chaines
                 series2->append(cc,place3);
                 if (place1!=0)
                 {QPieSlice *slice = series2->slices().at(0);//the percentage the actual slice
                     slice->setLabelVisible();
                     slice->setPen(QPen(Qt::red));}
                 if ( place2!=0)
                 {
                     // Add label, explode and define brush for 2nd slice
                     QPieSlice *slice1 = series2->slices().at(1);
                     //slice1->setExploded();
                     slice1->setLabelVisible();
                 }
                 if(place3!=0)
                 {
                     // Add labels to rest of slices
                     QPieSlice *slice2 = series2->slices().at(2);
                     //slice1->setExploded();
                     slice2->setLabelVisible();// Sets the label visibility for all contours in the collection
                 }
                 // Create the chart widget
               //  QChart *chart = new QChart();
                 // Add data to chart with title and hide legend
          //       chart->addSeries(series); // widget
          //       chart->setTitle("PRIX  "+ QString::number(total));
          //       chart->legend()->hide();
                 // Used to display the chart
          //      // QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
          //       chartView->setRenderHint(QPainter::Antialiasing);
          //       chartView->resize(1000,500);
          //       chartView->show();
                 QChart *chart2 = new QChart();

                     chart2->addSeries(series2);
                     chart2->setTitle("");
                    chart2->setBackgroundVisible(false);



                 chart2->setVisible(true);
                 chart2->legend()->setAlignment(Qt::AlignBottom);


                 QChartView *chartView2 = new QChartView(chart2);

                 chartView2->setRenderHint(QPainter::Antialiasing);
                 QPalette pal2 = qApp->palette();

                 chartView2->setMaximumWidth(731);
                 chartView2->setMaximumHeight(381);
                 chartView2->setMinimumWidth(731);
                 chartView2->setMinimumHeight(381);
                 chartView2->setParent(ui->statpart);
                 chartView2->show();
                 connect(ui->sendBtn_2, SIGNAL(clicked()),this, SLOT(sendMailpart()));
                 connect(ui->browseBtn_2, SIGNAL(clicked()), this, SLOT(browsepart()));

}

gestien::~gestien()
{
    delete ui;
}




void gestien::on_pushButton_modifier_clicked()
{
    int id=ui->lineEdit_id->text().toInt();
    QString type=ui->type_event->currentText();
    QString place=ui->lineEdit_place->text();
   QDateTime date=ui->date_event->dateTime();
   int cinclient=ui->combcin->currentText().toUInt();
    evenement E(id,type,place,date,cinclient);
    bool test=E.modifier(id);
    ui->tableView->setModel(tmp.afficher());
 if(test){

     ui->label_done->show();
     ui->pushButton_hide->show();

}else{
     ui->label_wrong->show();

     ui->pushButton_hide->show();


 }

 ui->lineEdit_id->clear();
 ui->type_event->setCurrentIndex(-1);
 ui->lineEdit_place->clear();
}






void gestien::on_pushButton_lab_clicked()
{
    ui->pushButton_prt->setChecked(false);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_lab->setChecked(true);
    ui->pushButton_mrk->setChecked(false);
    ui->pushButton_emp->setChecked(false);
   // ui->label_labpic->show();

 //   ui->groupBox->hide();
 //   ui->groupBox_3->hide();
    ui->label_cl->hide();
    ui->label_lab->show();
    ui->label_prt->hide();
    ui->label_ev->hide();
    ui->label_mrk->hide();
    ui->label_emp->hide();
   // ui->tricombo->hide();
  //  ui->chercherevent->hide();
//    ui->trie_commande->hide();
  //  ui->logoutBtn->show();
 //   ui->user->show();
 //   ui->admin->show();
    ui->loginlab->show();
    ui->eventlab->hide();
    ui->WebBrowser->hide();
    ui->tab_client->hide();
ui->tabpartenaire->hide();
 ui->mailframe->hide();

}

void gestien::on_pushButton_ev_clicked()
{
    ui->pushButton_prt->setChecked(false);
    ui->pushButton_ev->setChecked(true);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_mrk->setChecked(false);
    ui->pushButton_emp->setChecked(false);
 //   ui->label_labpic->hide();

   // ui->groupBox->show();
  //  ui->groupBox_3->show();
    ui->label_cl->hide();
    ui->label_lab->hide();
    ui->label_prt->hide();
    ui->label_ev->show();
    ui->label_mrk->hide();
    ui->label_emp->hide();
   /* ui->tricombo->show();
    ui->chercherevent->show();
    ui->trie_commande->show();
    ui->logoutBtn->hide();
    ui->user->hide();
    ui->admin->hide();*/
    ui->loginlab->hide();
    ui->eventlab->show();
    ui->framemail->hide();
    ui->tab_client->hide();
ui->tabpartenaire->hide();
 ui->mailframe->hide();



}

void gestien::on_pushButton_prt_clicked()
{
    ui->pushButton_prt->setChecked(true);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_mrk->setChecked(false);
    ui->pushButton_emp->setChecked(false);
   // ui->label_labpic->hide();

   // ui->groupBox->hide();
   // ui->groupBox_3->hide();
    ui->label_cl->hide();
    ui->label_lab->hide();
    ui->label_prt->show();
    ui->label_ev->hide();
    ui->label_mrk->hide();
    ui->label_emp->hide();
    /*ui->tricombo->hide();
    ui->chercherevent->hide();
    ui->trie_commande->hide();
    ui->logoutBtn->hide();
    ui->user->hide();
    ui->admin->hide();*/
    ui->loginlab->hide();
    ui->eventlab->hide();
    ui->WebBrowser->hide();
    ui->tab_client->hide();
ui->tabpartenaire->show();
 ui->mailframe->hide();
}

void gestien::on_pushButton_mrk_clicked()
{  ui->pushButton_prt->setChecked(false);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_mrk->setChecked(true);
    ui->pushButton_emp->setChecked(false);
   /* ui->label_labpic->hide();

    ui->groupBox->hide();
    ui->groupBox_3->hide();*/
    ui->label_cl->hide();
    ui->label_lab->hide();
    ui->label_prt->hide();
    ui->label_ev->hide();
    ui->label_mrk->show();
    ui->label_emp->hide();
   /* ui->tricombo->hide();
    ui->chercherevent->hide();
    ui->trie_commande->hide();
    ui->logoutBtn->hide();
    ui->user->hide();
    ui->admin->hide();*/

    ui->loginlab->hide();
    ui->eventlab->hide();
    ui->WebBrowser->hide();

    ui->tab_client->hide();
ui->tabpartenaire->hide();
 ui->mailframe->hide();
}

void gestien::on_pushButton_emp_clicked()
{
    ui->pushButton_prt->setChecked(false);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_mrk->setChecked(false);
    ui->pushButton_emp->setChecked(true);
  /*  ui->label_labpic->hide();

    ui->groupBox->hide();
    ui->groupBox_3->hide();*/
    ui->label_cl->hide();
    ui->label_lab->hide();
    ui->label_prt->hide();
    ui->label_ev->hide();
    ui->label_mrk->hide();
    ui->label_emp->show();
   /* ui->tricombo->hide();
    ui->chercherevent->hide();
    ui->trie_commande->hide();
    ui->logoutBtn->hide();
    ui->user->hide();
    ui->admin->hide();*/
    ui->loginlab->hide();
    ui->eventlab->hide();
    ui->WebBrowser->hide();

    ui->tab_client->hide();
ui->tabpartenaire->hide();
 ui->mailframe->hide();

}

void gestien::on_pushButton_cl_clicked()
{
    ui->pushButton_prt->setChecked(false);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_cl->setChecked(true);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_mrk->setChecked(false);
    ui->pushButton_emp->setChecked(false);
  /*  ui->label_labpic->hide();

    ui->groupBox->hide();
    ui->groupBox_3->hide();*/
    ui->label_cl->show();
    ui->label_lab->hide();
    ui->label_prt->hide();
    ui->label_ev->hide();
    ui->label_mrk->hide();
    ui->label_emp->hide();
    /*ui->tricombo->hide();
    ui->chercherevent->hide();
    ui->trie_commande->hide();
    ui->logoutBtn->hide();
    ui->user->hide();
    ui->admin->hide();*/
    ui->loginlab->hide();
    ui->eventlab->hide();
    ui->WebBrowser->hide();
    ui->tab_client->show();
ui->tabpartenaire->hide();
 ui->mailframe->hide();


}

void gestien::on_pushButton_add_clicked()
{

    int id=ui->lineEdit_id->text().toInt();
QString type=ui->type_event->currentText();
QString place=ui->lineEdit_place->text();
QDateTime date=ui->date_event->dateTime();
int cinclient=ui->combcin->currentText().toInt();
evenement E(id,type,place,date,cinclient);
bool test=E.ajouter();
if (test)
{
    ui->tableView->setModel(etmp.afficher());

    ui->label_done->show();
    ui->pushButton_hide->show();

}
else{
    ui->label_wrong->show();
    ui->pushButton_hide->show();

}
ui->lineEdit_id->clear();
ui->type_event->setCurrentIndex(-1);
ui->lineEdit_place->clear();
ui->date_event->clear();
}

void gestien::on_pushButton_del_clicked()
{
    int i;
    QModelIndex index=ui->tableView->currentIndex();
i=index.row();
QModelIndex in=index.sibling(i,0);

int val=ui->tableView->model()->data(in).toInt();
    //int id=ui->lineEdit_idsup->text().toInt();
    bool test=etmp.supprimer(val);
    if (test)
    {
        ui->tableView->setModel(etmp.afficher());

        ui->label_done->show();
        ui->pushButton_hide->show();
    }
    else
    {
        ui->label_wrong->show();
        ui->pushButton_hide->show();

     }


}

void gestien::on_pushButton_hide_clicked()
{
    ui->label_wrong->hide();
    ui->label_done->hide();
    ui->pushButton_hide->hide();
     ui->WebBrowser->hide();
     ui->framemail->hide();

}

void gestien::on_trie_commande_clicked()
{
    int id=0;
    QString type="";
    QString place="";
    QDateTime date=QDateTime::fromString("01.01.2000","MM.DD.YYYY");
int cinclient=0;

    evenement E(id,type,place,date,cinclient);
    QString trieOption=ui->tricombo->currentText();
     ui->tableView->setModel(E.trierevent(trieOption));
}

void gestien::on_chercherevent_textChanged()
{
    QString chaine_c=ui->chercherevent->text();

    int id=0;
    QString type="";
    QString place="";
 QDateTime date=QDateTime::fromString("01.01.2000","MM.DD.YYYY");
int cinclient=0;
    evenement E(id,type,place,date,cinclient);

    if(chaine_c !="")
    {
    ui->tableView->setModel(E.rechercherevent(chaine_c));
    }
    else
    {
        QString trieOption=ui->tricombo->currentText();
        ui->tableView->setModel(E.trierevent(trieOption));
    }
}

 void gestien::on_genpdf_clicked()
{
    QPdfWriter pdf("C:/Users/pc/Desktop/event_planner_2A35/projetevent/Pdf/List_evenement.pdf");

       QPainter painter(&pdf);
       int i = 4100;
   const QImage image("C:/Users/pc/Desktop/event_planner_2A35/projetevent/image/logo.png");
                   const QPoint imageCoordinates(155,0);
                   int width1 = 1600;
                   int height1 = 1600;
                   QImage img=image.scaled(width1,height1);
                   painter.drawImage(imageCoordinates, img );


              QColor dateColor(0x4a5bcf);
              painter.setPen(dateColor);

              painter.setFont(QFont("Montserrat SemiBold", 11));
              QDate cd = QDate::currentDate();
              painter.drawText(8400,250,cd.toString("Tunis"));
              painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

              QColor titleColor(0x341763);
              painter.setPen(titleColor);
              painter.setFont(QFont("Montserrat SemiBold", 25));

              painter.drawText(3000,2700,"Liste des evenements");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              //painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(500,3600,"ID");
              painter.drawText(2000,3600,"place");
              painter.drawText(3300,3600,"date");
              painter.drawText(7500,3600,"type");
              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from evenement");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3300,i,query.value(3).toString());
                  painter.drawText(7500,i,query.value(2).toString());

                 i = i + 500;
              }
              ui->label_done->show();
              ui->pushButton_hide->show();
}

void gestien::on_stats_clicked()
{
    notification();
    QBarSet *set1 = new QBarSet("Nombre de evenement par mois");

    int id=0;
    QString type="";
    QString place="";
 QDateTime date=QDateTime::fromString("01.01.2000","MM.DD.YYYY");
int cinclient=0;
     evenement E(id,type,place,date,cinclient);

        *set1 <<  E.statistiqueevent(1)
              <<  E.statistiqueevent(2)
              <<  E.statistiqueevent(3)
              <<  E.statistiqueevent(4)
              << E.statistiqueevent(5)
              << E.statistiqueevent(6)
              << E.statistiqueevent(7)
              << E.statistiqueevent(8)
              << E.statistiqueevent(9)
              << E.statistiqueevent(10)
              << E.statistiqueevent(11)
              << E.statistiqueevent(12) ;



            QBarSeries *series = new QBarSeries();

            series->append(set1);

            QColor color(0x6568F3);
            set1->setColor(color);


            QChart *chart = new QChart();

                chart->addSeries(series);
                chart->setTitle("");
               chart->setBackgroundVisible(false);

                   QStringList categories;
                categories << "Jan" << "Fiv" << "Mar" << "Avr" << "Mai" << "Juin" << "Jui" <<"Aou" << "sep" << "Oct" << "Nov" << "Dec" ;
                QBarCategoryAxis *axis = new QBarCategoryAxis();


                axis->append(categories);

                chart->createDefaultAxes();
                chart->setAxisX(axis, series);


                chart->setVisible(true);
                chart->legend()->setAlignment(Qt::AlignBottom);


                QChartView *chartView = new QChartView(chart);

                chartView->setRenderHint(QPainter::Antialiasing);
                QPalette pal = qApp->palette();

                chartView->setMaximumWidth(650);
                chartView->setMaximumHeight(290);

                chartView->setParent(ui->statfarme);
                chartView->show();

setcin_combo();
 qDebug()<<QSslSocket::supportsSsl() << QSslSocket::sslLibraryBuildVersionString() << QSslSocket::sslLibraryVersionString();

}



void gestien::on_logoutBtn_clicked()
{
       this->hide();
}

void gestien::on_excel_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                    tr("Excel Files (*.xls)"));
    if (fileName.isEmpty())
        return;

    ExportExcelObject obj(fileName, "mydata", ui->tableView);

    //colums to export
    obj.addField(0, "id", "char(20)");
    obj.addField(1, "place", "char(20)");
    obj.addField(2, "type", "char(20)");
    obj.addField(3, "datee", "char(20)");
    obj.addField(4, "cinclient", "char(20)");



    int retVal = obj.export2Excel();
    if( retVal > 0)
    {
        ui->label_done->show();
        ui->pushButton_hide->show();

    }

}




void gestien::on_tableView_clicked(const QModelIndex &index)
{

        int i;
    i=index.row();
    QModelIndex in=index.sibling(i,0);
    QString val=ui->tableView->model()->data(in).toString();


        QSqlQuery qry;
        qry.prepare("select id,place,type,datee,cinclient from evenement where id='"+val+"' " );


        if(qry.exec())
        {
            while(qry.next())
            {
                ui->lineEdit_id->setText(qry.value(0).toString());
                ui->lineEdit_place->setText(qry.value(1).toString());
                ui->type_event->setCurrentText(qry.value(2).toString());
                ui->date_event->setDateTime(qry.value(3).toDateTime());
          //      ui->dateTimeEdit->setDate(qry.value(4).toDate());
    //
            }
    }}


void gestien::on_tableView_doubleClicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,1);
QString val=ui->tableView->model()->data(in).toString();

QSettings settings(QSettings::IniFormat, QSettings::UserScope,
                   QCoreApplication::organizationName(), QCoreApplication::applicationName());

ui->WebBrowser->dynamicCall("Navigate(const QString&)", "https://www.google.com/maps/dir//"+val+" tunisie");

}

void gestien::on_map_clicked()
{
     ui->WebBrowser->show();
     ui->pushButton_hide->show();
}

void gestien::setcin_combo()
{

    QSqlQueryModel * modal=new QSqlQueryModel();

     QSqlQuery query;
     query.prepare("select cinclient from client ");
     query.exec();
     modal->setQuery(query);
     ui->combcin->setModel(modal);

}

void gestien::on_mail_clicked()
{
    ui->framemail->show();
    ui->pushButton_hide->show();
}

void  gestien::browse()
{
    files.clear();
   QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   gestien::sendMail()
{
    Smtp* smtp = new Smtp("monam.jr123@gmail.com",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailsent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("monam.jr123@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("monam.jr123@gmail.com", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}
void   gestien::mailsent(QString status)
{

    if(status == "Message sent")
    { ui->label_done->show();
    ui->pushButton_hide->show();
    }
    ui->rcpt->clear();
    ui->subject->clear();
    ui->file->clear();
    ui->msg->clear();
    ui->mail_pass->clear();
}

void gestien::notification()
{



    int d=QDate::currentDate().day();
    int m=QDate::currentDate().month();
    int y=QDate::currentDate().year();

         QSqlQuery query;
         query.prepare("select datee ,id,type,place from evenement  where extract(month  from datee)=:month and extract(day  from datee)=:day and extract(year  from datee)=:year ");
      query.bindValue(":day",d);
      query.bindValue(":month",m);
      query.bindValue(":year",y);

         query.exec();

 //query.next();
         QString dd=QDate::currentDate().toString("yyyy.MM.dd");
             while  (query.next())
              {
                QString dateE=query.value(0).toString();
                QString cordonnerid=query.value(1).toString();
                QString cordonnertype=query.value(2).toString();
                QString cordonnerplace=query.value(3).toString();

         if(dateE!="dd")
    {
     popUp->setPopupText(" votre evenement :\n "+cordonnerid+"  "+cordonnertype+ "  est toujour a "+cordonnerplace);

    }
 else {
     popUp->setPopupText("pas des evenements toujours");
 }
 popUp->show();
 query.next();
 qDebug ()<<dateE;
      }
}
void gestien::on_addimg_clicked()
{
    QString imageFile = QFileDialog ::getOpenFileName(0,"Select Image","/home/","Image Files (*.png)");

          QFileInfo info(imageFile);
        QFileInfo  filename = info.fileName(); //path de l'image

        QPixmap image (imageFile);
          ui->upimg->setSizePolicy( QSizePolicy::Ignored, QSizePolicy::Ignored );
          image = image.scaled(110,110,Qt::IgnoreAspectRatio,Qt::FastTransformation);
          ui->upimg->setPixmap(image);
          ui->upimg->show();

}

void gestien::on_clientadd_clicked()
{
    QString Nom=ui->lineEdit_Nom->text();
    QString Prenom=ui->lineEdit_Prenom->text();
    QString cin=ui->lineEdit_cin->text();
    QString Numero=ui->lineEdit_Numero->text();
    QString Gmail=ui->lineEdit_Gmail->text();
    CLIENT C(Nom,Prenom,cin,Numero,Gmail);
    bool test=C.ajouter();
    if (test)
    {
         ui->tableView_2->setModel(c.afficher());
         Historiques h(Nom, Prenom, Gmail, cin, Numero,"");
         h.saveClient();

        QMessageBox::information(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
    {
        ui->tableView->setModel(c.afficher());
        QMessageBox::critical(nullptr, QObject::tr("ajouter"),
                    QObject::tr("ajouter failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
}

void gestien::on_pushButton_2_clicked()
{

    int i;
    QModelIndex index=ui->tableView_2->currentIndex();
i=index.row();
QModelIndex in=index.sibling(i,0);

QString val=ui->tableView_2->model()->data(in).toString();
     bool test=c.supprime(val);
     if (test)
     {
         CLIENT c("","","","","");
         QSqlQuery clientInfo = c.afficher(val);
         clientInfo.next();
         Historiques h(clientInfo.value(1).toString(), clientInfo.value(2).toString(), clientInfo.value(3).toString(), clientInfo.value(0).toString(), clientInfo.value(4).toString(), "");
         h.saveDeleteClient();

         ui->tableView_2->setModel(c.afficher());
        QMessageBox::information(nullptr, QObject::tr("supprimer"),
                     QObject::tr("delete successful.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);
     }
     else
     {
         QMessageBox::critical(nullptr, QObject::tr("delete"),
                     QObject::tr("delete failed.\n"
                                 "Click Cancel to exit."), QMessageBox::Cancel);

     }
}

void gestien::on_pushButton_3_clicked()
{
    QString cin=ui->lineEdit_cin->text();
    QString prenom=ui->lineEdit_Prenom->text();
        QString nom=ui->lineEdit_Nom->text();
          QString numero=ui->lineEdit_Numero->text();
          QString gmail=ui->lineEdit_Gmail->text();


          CLIENT c("","","","","");
          QSqlQuery clientInfo = c.afficher(cin);
          clientInfo.next();
          Historiques h(clientInfo.value(1).toString(), clientInfo.value(2).toString(), clientInfo.value(3).toString(), clientInfo.value(0).toString(), clientInfo.value(4).toString(), "");


        CLIENT C(nom,prenom,cin,numero,gmail);
        bool test=C.modifier(cin);
        ui->tableView_2->setModel(c.afficher());
     if(test){

         h.saveUpdateClient(nom, prenom, gmail, cin, numero);

        QMessageBox::information(nullptr,QObject::tr("OK"),
                                 QObject::tr("modification effectué \n""Click Cancel to exit"),QMessageBox::Cancel);
    }else{
         QMessageBox::information(nullptr,QObject::tr("OK"),
                                  QObject::tr("modification non effectué \n""Click Cancel to exit"),QMessageBox::Cancel);


     }
}

void gestien::on_rechercherClient_textChanged(const QString &arg1)
{
    QString chaine_c=ui->rechercherClient->text();

    QString cin="";
    QString nom="";
    QString prenom="";
    QString numero="";
    QString gmail="";

    CLIENT c(nom,prenom,cin,numero,gmail);

    if(chaine_c !="")
    {
    ui->tableView_2->setModel(c.rechercherClient(chaine_c));
    }
    else
    {
        QString trieOption=ui->clientComboBox->currentText();
        ui->tableView_2->setModel(c.trierClient(trieOption));
    }
}

void gestien::on_trierClientBtn_clicked()
{
    QString cin="";
    QString nom="";
    QString prenom="";
    QString numero="";
    QString gmail="";

    CLIENT c(nom,prenom,cin,numero,gmail);
    QString trieOption=ui->clientComboBox->currentText();
     ui->tableView_2->setModel(c.trierClient(trieOption));
}

void gestien::on_pdfClient_clicked()
{

    QPdfWriter pdf("C:/Users/pc/Desktop/event_planner_2A35/projetevent/Pdf/List_Client.pdf");

       QPainter painter(&pdf);
       int i = 4100;
      const QImage image(":/image/image/logo.png/logo.png");
                   const QPoint imageCoordinates(155,0);
                   int width1 = 1600;
                   int height1 = 1600;
                   QImage img=image.scaled(width1,height1);
                   painter.drawImage(imageCoordinates, img );


              QColor dateColor(0x4a5bcf);
              painter.setPen(dateColor);

              painter.setFont(QFont("Montserrat SemiBold", 11));
              QDate cd = QDate::currentDate();
              painter.drawText(8400,250,cd.toString("Tunis"));
              painter.drawText(8100,500,cd.toString("dd/MM/yyyy"));

              QColor titleColor(0x341763);
              painter.setPen(titleColor);
              painter.setFont(QFont("Montserrat SemiBold", 25));

              painter.drawText(3000,2700,"Liste des clients");

              painter.setPen(Qt::black);
              painter.setFont(QFont("Time New Roman", 15));
              //painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3300,9400,500);

              painter.setFont(QFont("Montserrat SemiBold", 10));

              painter.drawText(500,3600,"Cin");
              painter.drawText(2000,3600,"Nom");
              painter.drawText(3300,3600,"Prenom");
              painter.drawText(4500,3600,"Email");
              painter.drawText(7500,3600,"Numero");
              painter.setFont(QFont("Montserrat", 10));
              painter.drawRect(100,3300,9400,9000);

              QSqlQuery query;
              query.prepare("select * from client");
              query.exec();
              int y=4300;
              while (query.next())
              {
                  painter.drawLine(100,y,9490,y);
                  y+=500;
                  painter.drawText(500,i,query.value(0).toString());
                  painter.drawText(2000,i,query.value(1).toString());
                  painter.drawText(3300,i,query.value(3).toString());
                  painter.drawText(4500,i,query.value(4).toString());
                  painter.drawText(7500,i,query.value(2).toString());

                 i = i + 500;
              }
              QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
              QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void gestien::on_historiqueClient_clicked()
{
      QDesktopServices::openUrl(QUrl(tr("file:///C:/Users/pc/Desktop/evant_planner2A35/projetevent/historique.txt")));
}

void gestien::on_clientFidele_clicked()
{

    QString cin="";
    QString nom="";
    QString prenom="";
    QString numero="";
    QString gmail="";

    CLIENT c(nom,prenom,cin,numero,gmail);

    int maxEvent = c.clientFidele();
    QString max = QString::number(maxEvent);

     //QString cinClientFidele = c.clientFideleDetails();
     //qDebug() << "cinmaxEvent" << cinClientFidele ;

    QSqlQuery clientInfo = c.clientFideleDetails();
    clientInfo.next();



    qDebug() << "maxEvent" << max ;


    ui->nbEventLabel->setText(max);
    ui->clientNameLabel->setText(clientInfo.value(1).toString());
    ui->clientPrenomLabel->setText(clientInfo.value(3).toString());
    ui->clientCinLabel->setText(clientInfo.value(0).toString());


}

void gestien::on_tableView_2_clicked(const QModelIndex &index)
{
    int i;
i=index.row();
QModelIndex in=index.sibling(i,0);
QString val=ui->tableView_2->model()->data(in).toString();


    QSqlQuery qry;
    qry.prepare("select cinclient,nom,prenom,numero,gmail from client where cinclient='"+val+"' " );


    if(qry.exec())
    {
        while(qry.next())
        {
            ui->lineEdit_cin->setText(qry.value(0).toString());
            ui->lineEdit_Nom->setText(qry.value(1).toString());
            ui->lineEdit_Prenom->setText(qry.value(2).toString());
            ui->lineEdit_Numero->setText(qry.value(3).toString());
            ui->lineEdit_Gmail->setText(qry.value(4).toString());
            ui->numlabel->setText(qry.value(3).toString());
}}}
using namespace std;





void gestien::on_ajouter_partenair_clicked()
{
    int id=ui->le_id->text().toInt(); //convertir en entier
      int num_partenaire=ui->le_num->text().toInt();
       int prix=ui->le_prix->text().toInt();
      QString nom=ui->le_nom->text();
      QString email=ui->le_email->text();

      partenaire p(id,num_partenaire,prix,nom,email);

      bool test=p.ajouter();
      if(test)
      {

N.notification_ajoutpartenair();
          ui->tableView_3->setModel( p.afficher());
          QMessageBox::information(nullptr,QObject::tr("ok"),
                                 QObject::tr("ajout effectue\n"
                                             "click cancel to exit."),QMessageBox::Cancel);

      }
      else  QMessageBox::critical(nullptr,QObject::tr("Not ok"),
                                     QObject::tr("ajout non effectue\n"
                                                 "click cancel to exit."),QMessageBox::Cancel);
      ui->le_id->clear();
      ui->le_num->clear();
      ui->le_prix->clear();
       ui->le_nom->clear();
       ui->le_email->clear();
}

void gestien::on_suprimer_partenair_clicked()
{
    bool i;
         int id_del;


         id_del=ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),0)).toInt();

         i=p.supprimer(id_del);
         if(i)
         {
N.notification_supprimerpartenair();
             ui->tableView_3->setModel(p.afficher());
             QMessageBox::information(nullptr, QObject::tr("OK"),
                         QObject::tr("suppression effectué.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel);

     }
         else
            { QMessageBox::critical(nullptr, QObject::tr("not OK"),
                         QObject::tr("problème de suppression.\n"
                                     "Click Cancel to exit."), QMessageBox::Cancel); }
}

void gestien::on_tableView_3_clicked(const QModelIndex &index)
{
    ui->le_id->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),0)).toString());
    ui->le_num->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),1)).toString());
    ui->le_prix->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),2)).toString());
    ui->le_nom->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),3)).toString());
    ui->le_email->setText(ui->tableView_3->model()->data(ui->tableView_3->model()->index(index.row(),4)).toString());



}

void gestien::on_fichier_xl_clicked()
{
    QString nomFile=ui->fichier->text();
    QMessageBox msg;
    if(!nomFile.length()){

        msg.setText("entrer le nom du fichier");
        msg.exec();
    }
    else{
    QFile file("C:/Users/pc/Desktop/evant_planner2A35/projetevent/excel/"+nomFile+".csv");
    QString finalmsg="fichier modifie avec succes";
     if(!file.exists()){
     finalmsg="fichier cree avec succes";
     }
    file.open(QFile::WriteOnly | QFile::Text);
    QTextStream txt(&file);
    for(int i=0;i<100;i++){

    QString id= ui->tableView_3->model()->index(i,0).data().toString();
        QString num_partenaire= ui->tableView_3->model()->index(i,3).data().toString();
    QString prix= ui->tableView_3->model()->index(i,1).data().toString();
    QString nom= ui->tableView_3->model()->index(i,2).data().toString();
    QString email= ui->tableView_3->model()->index(i,2).data().toString();


    if(id.length()){

    txt<< "id: '"+ id +"'       ";
    txt<< "'num_partenaire : '"+ num_partenaire   +"'      ";
    txt<< "'prix: '"+ prix +"'      ";
     txt<< "'nom: '"+ nom +"'     ";
    txt<< "'email: '"+ email +"' \n";

    }
    }
    msg.setText(finalmsg);
    msg.exec();
    file.close();
    }
}

void gestien::on_pushButton_5_clicked()
{
    QString text ="dosssier partenaire details :"+ ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),1)).toString()
                         +" "+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),2)).toString()
                         +" "+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),3)).toString()
                         +" "+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),4)).toString()
                         +" "+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),5)).toString()
                         +" "+ui->tableView_3->model()->data(ui->tableView_3->model()->index(ui->tableView_3->currentIndex().row(),6)).toString();
                 //text="user data";
                 using namespace qrcodegen;
                   // Create the QR Code object
                   QrCode qr = QrCode::encodeText( text.toUtf8().data(), QrCode::Ecc::MEDIUM );
                   qint32 sz = qr.getSize();
                   QImage im(sz,sz, QImage::Format_RGB32);
                     QRgb black = qRgb(  0,  0,  0);
                     QRgb white = qRgb(255,255,255);
                   for (int y = 0; y < sz; y++)
                     for (int x = 0; x < sz; x++)
                       im.setPixel(x,y,qr.getModule(x, y) ? black : white );
                   ui->qr_code->setPixmap( QPixmap::fromImage(im.scaled(256,256,Qt::KeepAspectRatio,Qt::FastTransformation),Qt::MonoOnly) );

}


void gestien::on_rechercher_partenaire_textChanged(const QString &arg1)
{
    ui->tableView_3->setModel(p.Recherche(arg1));
}

void gestien::on_trier_partenaire_activated()
{
    if (ui->trier_partenaire->currentText()=="Tri Par ID")
    {
        ui->tableView_3->setModel(p.trierpartenaireParid());
    }
    else if(ui->trier_partenaire->currentText()=="Tri Par NOM")
    {
        ui->tableView_3->setModel(p.trierpartenairenom());
    }
    else
    {
        ui->tableView_3->setModel(p.trierpartenaireParnum_partenaire());
    }
}

void gestien::on_modifier_partenair_clicked()
{
    int id=ui->le_id->text().toInt();
        int num_partenaire=ui->le_num->text().toInt();
        int prix=ui->le_prix->text().toInt();
        QString nom=ui->le_nom->text();
        QString email=ui->le_email->text();

        partenaire p(id,num_partenaire,prix,nom,email);

            bool test=p.modifierpartenaire(p.getid(),p.getnum_partenaire(),p.getprix(),p.getnom(),p.getemail());

            QMessageBox msgBox;

            if(test)
                {
N.notification_modifierpartenair();
                    msgBox.setText("Modification avec succes.");
                    ui->tableView_3->setModel(p.afficher());
                }
            else
                msgBox.setText("Echec de Modification!!!!!!");
                msgBox.exec();
}

void gestien::on_pushButton_7_clicked()
{
     ui->mailframe->show();
}

void gestien::on_pushButton_6_clicked()
{
     ui->mailframe->hide();
}





void  gestien::browsepart()
{
    files.clear();
   QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}
void   gestien::sendMailpart()
{
    Smtp* smtp = new Smtp("abdelmonam.jarray@esprit.tn",ui->mail_pass_2->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailsent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("abdelmonam.jarray@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText(), files );
    else
        smtp->sendMail("abdelmonam.jarray@esprit.tn", ui->rcpt_2->text() , ui->subject_2->text(),ui->msg_2->toPlainText());
}
void   gestien::mailsentpart(QString status)
{

    if(status == "Message sent")
    { ui->label_done->show();
    ui->pushButton_hide->show();
    }
    ui->rcpt_2->clear();
    ui->subject_2->clear();
    ui->file_2->clear();
    ui->msg_2->clear();
    ui->mail_pass_2->clear();
}

void gestien::on_statistique_clicked()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from partenaire where prix < 500 ");
    float place1=model->rowCount();
    model->setQuery("select * from partenaire where prix  between 500 and 1500 ");
    float place2=model->rowCount();
    model->setQuery("select * from partenaire where prix > 1500 ");
    float place3=model->rowCount();
    float total=place1+place2+place3;

    QString a=QString("inferier 500 DT . "+QString::number((place1*100)/total,'f',2)+"%" );
    QString b=QString("entre 500 et 1500 DT.  "+QString::number((place2*100)/total,'f',2)+"%" );
    QString cc=QString("plus de 1500 DT.   "+QString::number((place3*100)/total,'f',2)+"%" );

    QPieSeries *series2 = new QPieSeries();//PieSeries object calculates the percentage the actual size of the slice in the chart.
    series2->append(a,place1);
    series2->append(b,place2);//concatiner 2 chaines
    series2->append(cc,place3);
    if (place1!=0)
    {QPieSlice *slice = series2->slices().at(0);//the percentage the actual slice
        slice->setLabelVisible();
        slice->setPen(QPen(Qt::red));}
    if ( place2!=0)
    {
        // Add label, explode and define brush for 2nd slice
        QPieSlice *slice1 = series2->slices().at(1);
        //slice1->setExploded();
        slice1->setLabelVisible();
    }
    if(place3!=0)
    {
        // Add labels to rest of slices
        QPieSlice *slice2 = series2->slices().at(2);
        //slice1->setExploded();
        slice2->setLabelVisible();// Sets the label visibility for all contours in the collection
    }
    // Create the chart widget
  //  QChart *chart = new QChart();
    // Add data to chart with title and hide legend
//       chart->addSeries(series); // widget
//       chart->setTitle("PRIX  "+ QString::number(total));
//       chart->legend()->hide();
    // Used to display the chart
//      // QChartView *chartView = new QChartView(chart);//creation de la fenetre de widget
//       chartView->setRenderHint(QPainter::Antialiasing);
//       chartView->resize(1000,500);
//       chartView->show();
    QChart *chart2 = new QChart();

        chart2->addSeries(series2);
        chart2->setTitle("");
       chart2->setBackgroundVisible(false);



    chart2->setVisible(true);
    chart2->legend()->setAlignment(Qt::AlignBottom);


    QChartView *chartView2 = new QChartView(chart2);

    chartView2->setRenderHint(QPainter::Antialiasing);
    QPalette pal2 = qApp->palette();

    chartView2->setMaximumWidth(731);
    chartView2->setMaximumHeight(381);
    chartView2->setMinimumWidth(731);
    chartView2->setMinimumHeight(381);
    chartView2->setParent(ui->statpart);
    chartView2->show();
}


void gestien::smscheck()
{

QSqlQuery q;
    data=A.read_from_arduino();

   test1=data;
   test=test1.left(test1.length()-2);

if (test[0]!="�"&& test[0]!="+"&& test!=""&& occ==0)
{
 popUp->setPopupText(test);
 popUp->show();
 QSqlQuery q;

 q.prepare("insert into massege (MASSEGE)""values(:msg)");

 q.bindValue(":msg", test);
 q.exec();
    occ=1;

}

}

void gestien::on_pushButton_clicked()
{


QString num=ui->numlabel->text();
qDebug()<<num<<endl;


//A.write_to_arduino("m"); //envoyer 'm' à arduino
//for (int i=0;i<8;i++){
//    QString myString = num.at(i);

if (num=="52940699"){
A.write_to_arduino("a");
}else if (num=="24262449"){
    A.write_to_arduino("b");
    }else if (num=="24262449"){
    A.write_to_arduino("b");
}else if (num=="53273182"){
    A.write_to_arduino("c");
}







 }
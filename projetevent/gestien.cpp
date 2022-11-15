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

#include "mainwindow.h"
#include "exportexcelobject.h"
#include <QDebug>
#include <QSslSocket>
#include "smtp.h"
#include "popup.h"

gestien::gestien(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestien)
{
    popUp= new PopUp();

    ui->setupUi(this);
notification();

    ui->pushButton_prt->setChecked(false);
    ui->pushButton_cl->setChecked(false);
    ui->pushButton_ev->setChecked(false);
    ui->pushButton_lab->setChecked(false);
    ui->pushButton_emp->setChecked(false);
    ui->pushButton_mrk->setChecked(false);
   ui->tableView->setModel(etmp.afficher());
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

              //maillllll
              connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
              connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
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
    Smtp* smtp = new Smtp("abdelmonam.jarray@esprit.tn",ui->mail_pass->text(), "smtp.gmail.com");
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailsent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail("abdelmonam.jarray@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail("abdelmonam.jarray@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
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

         if(dateE!=dd)
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

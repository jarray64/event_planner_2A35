/********************************************************************************
** Form generated from reading UI file 'home.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOME_H
#define UI_HOME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_home
{
public:
    QLabel *label_20;
    QTabWidget *tabWidget_2;
    QWidget *AjouterEmployee_3;
    QGroupBox *groupBox_7;
    QPushButton *pb_ajouter_3;
    QPushButton *reset_ajouter_5;
    QLabel *label_50;
    QWidget *layoutWidget_15;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_19;
    QLabel *label_66;
    QLabel *label_62;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_64;
    QVBoxLayout *verticalLayout_20;
    QLineEdit *keyperso_ajout;
    QLineEdit *nom_ajout;
    QLineEdit *prenom_ajout;
    QLineEdit *pass_ajout;
    QLineEdit *age_ajout;
    QWidget *tab_7;
    QTableView *tab_chercher_2;
    QGroupBox *groupBox_8;
    QWidget *layoutWidget_19;
    QVBoxLayout *verticalLayout_31;
    QRadioButton *radio_keyperso;
    QRadioButton *radio_nom;
    QRadioButton *radio_age;
    QGroupBox *groupBox_3;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QRadioButton *croissant_5;
    QRadioButton *decroissant;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_10;
    QWidget *tab_8;
    QGroupBox *suppression_5;
    QLabel *label_78;
    QLineEdit *supprimer_keyperso;
    QPushButton *supprimer_keyperso_btn;
    QWidget *tab_9;
    QGroupBox *suppression_6;
    QLabel *label_79;
    QLineEdit *keyperso_modifier_2;
    QPushButton *chercher_modifier_2;
    QGroupBox *groupBox_9;
    QPushButton *pb_modifier_7;
    QPushButton *reset_ajouter_6;
    QWidget *layoutWidget_16;
    QHBoxLayout *horizontalLayout_16;
    QVBoxLayout *verticalLayout_23;
    QLabel *label_80;
    QLabel *label_81;
    QLabel *label_82;
    QLabel *label_83;
    QLabel *label_84;
    QVBoxLayout *verticalLayout_24;
    QLineEdit *keyperso_modifier;
    QLineEdit *nom_modifier;
    QLineEdit *prenom_modifier;
    QLineEdit *pass_modifier;
    QLineEdit *age_modifier;

    void setupUi(QDialog *home)
    {
        if (home->objectName().isEmpty())
            home->setObjectName(QStringLiteral("home"));
        home->resize(1081, 601);
        home->setStyleSheet(QLatin1String(" \n"
"background-color: rgb(170, 166, 155);\n"
" "));
        label_20 = new QLabel(home);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(0, 650, 131, 16));
        tabWidget_2 = new QTabWidget(home);
        tabWidget_2->setObjectName(QStringLiteral("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(100, 10, 901, 581));
        QFont font;
        font.setKerning(true);
        tabWidget_2->setFont(font);
        tabWidget_2->setStyleSheet(QLatin1String("QWidget{background:transparent} QTabWidget::pane{border: 1px;border-color:red;background-color: transparent;} \n"
"QTabBar::tab {background-color: transparent;color: #ccc;width: 200px;height:48px;font-size:15px} \n"
"\n"
"QTabBar::tab:hover{\n"
"color: white;\n"
"background-color:#000000;\n"
"border-width: 2px;\n"
"border-color: #ffffff;;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 20px;\n"
"\n"
"\n"
"}"));
        tabWidget_2->setTabPosition(QTabWidget::North);
        tabWidget_2->setTabShape(QTabWidget::Triangular);
        tabWidget_2->setIconSize(QSize(10, 10));
        tabWidget_2->setElideMode(Qt::ElideNone);
        tabWidget_2->setUsesScrollButtons(true);
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        tabWidget_2->setTabBarAutoHide(false);
        AjouterEmployee_3 = new QWidget();
        AjouterEmployee_3->setObjectName(QStringLiteral("AjouterEmployee_3"));
        groupBox_7 = new QGroupBox(AjouterEmployee_3);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));
        groupBox_7->setEnabled(true);
        groupBox_7->setGeometry(QRect(20, 30, 821, 471));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 0));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox_7->setPalette(palette);
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setPointSize(14);
        font1.setBold(true);
        font1.setWeight(75);
        groupBox_7->setFont(font1);
        groupBox_7->setTabletTracking(false);
        groupBox_7->setAutoFillBackground(false);
        pb_ajouter_3 = new QPushButton(groupBox_7);
        pb_ajouter_3->setObjectName(QStringLiteral("pb_ajouter_3"));
        pb_ajouter_3->setGeometry(QRect(640, 360, 131, 41));
        QFont font2;
        pb_ajouter_3->setFont(font2);
        pb_ajouter_3->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        reset_ajouter_5 = new QPushButton(groupBox_7);
        reset_ajouter_5->setObjectName(QStringLiteral("reset_ajouter_5"));
        reset_ajouter_5->setGeometry(QRect(500, 360, 131, 41));
        reset_ajouter_5->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        label_50 = new QLabel(groupBox_7);
        label_50->setObjectName(QStringLiteral("label_50"));
        label_50->setGeometry(QRect(130, 470, 251, 21));
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush3(QColor(255, 255, 255, 128));
        brush3.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(0, 0, 0, 128));
        brush4.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_50->setPalette(palette1);
        QFont font3;
        font3.setPointSize(15);
        font3.setBold(true);
        font3.setWeight(75);
        label_50->setFont(font3);
        layoutWidget_15 = new QWidget(groupBox_7);
        layoutWidget_15->setObjectName(QStringLiteral("layoutWidget_15"));
        layoutWidget_15->setGeometry(QRect(10, 70, 491, 251));
        horizontalLayout_11 = new QHBoxLayout(layoutWidget_15);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_19 = new QVBoxLayout();
        verticalLayout_19->setObjectName(QStringLiteral("verticalLayout_19"));
        label_66 = new QLabel(layoutWidget_15);
        label_66->setObjectName(QStringLiteral("label_66"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_66->setPalette(palette2);
        label_66->setFont(font3);

        verticalLayout_19->addWidget(label_66);

        label_62 = new QLabel(layoutWidget_15);
        label_62->setObjectName(QStringLiteral("label_62"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        QBrush brush5(QColor(255, 255, 255, 0));
        brush5.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette3.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        QBrush brush6(QColor(127, 127, 127, 0));
        brush6.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Dark, brush6);
        QBrush brush7(QColor(170, 170, 170, 0));
        brush7.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Mid, brush7);
        QBrush brush8(QColor(0, 0, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        QBrush brush9(QColor(255, 255, 255, 127));
        brush9.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        QBrush brush10(QColor(255, 255, 220, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette3.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette3.setBrush(QPalette::Inactive, QPalette::Mid, brush7);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Mid, brush7);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette3.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette3.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_62->setPalette(palette3);
        label_62->setFont(font3);

        verticalLayout_19->addWidget(label_62);

        label_53 = new QLabel(layoutWidget_15);
        label_53->setObjectName(QStringLiteral("label_53"));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_53->setPalette(palette4);
        label_53->setFont(font3);

        verticalLayout_19->addWidget(label_53);

        label_54 = new QLabel(layoutWidget_15);
        label_54->setObjectName(QStringLiteral("label_54"));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_54->setPalette(palette5);
        label_54->setFont(font3);

        verticalLayout_19->addWidget(label_54);

        label_64 = new QLabel(layoutWidget_15);
        label_64->setObjectName(QStringLiteral("label_64"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_64->setPalette(palette6);
        label_64->setFont(font3);

        verticalLayout_19->addWidget(label_64);


        horizontalLayout_11->addLayout(verticalLayout_19);

        verticalLayout_20 = new QVBoxLayout();
        verticalLayout_20->setObjectName(QStringLiteral("verticalLayout_20"));
        keyperso_ajout = new QLineEdit(layoutWidget_15);
        keyperso_ajout->setObjectName(QStringLiteral("keyperso_ajout"));
        keyperso_ajout->setFont(font2);
        keyperso_ajout->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_20->addWidget(keyperso_ajout);

        nom_ajout = new QLineEdit(layoutWidget_15);
        nom_ajout->setObjectName(QStringLiteral("nom_ajout"));
        nom_ajout->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_20->addWidget(nom_ajout);

        prenom_ajout = new QLineEdit(layoutWidget_15);
        prenom_ajout->setObjectName(QStringLiteral("prenom_ajout"));
        prenom_ajout->setFont(font2);
        prenom_ajout->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_20->addWidget(prenom_ajout);

        pass_ajout = new QLineEdit(layoutWidget_15);
        pass_ajout->setObjectName(QStringLiteral("pass_ajout"));
        pass_ajout->setFont(font2);
        pass_ajout->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_20->addWidget(pass_ajout);

        age_ajout = new QLineEdit(layoutWidget_15);
        age_ajout->setObjectName(QStringLiteral("age_ajout"));
        age_ajout->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_20->addWidget(age_ajout);


        horizontalLayout_11->addLayout(verticalLayout_20);

        tabWidget_2->addTab(AjouterEmployee_3, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QStringLiteral("tab_7"));
        tab_chercher_2 = new QTableView(tab_7);
        tab_chercher_2->setObjectName(QStringLiteral("tab_chercher_2"));
        tab_chercher_2->setGeometry(QRect(200, 20, 521, 261));
        tab_chercher_2->setStyleSheet(QLatin1String("QTableView\n"
"{\n"
"    alternate-background-color: #1F1F1F;\n"
"    gridline-color: white;\n"
"    color: white;\n"
"\n"
"    font: 75 9pt \"MS Shell Dlg 2\";\n"
"}\n"
"QTableView::item \n"
"{\n"
"    color: white;\n"
"}\n"
"\n"
"QTableView::item:focus\n"
"{\n"
"    color: gray;\n"
"    background: #0063cd;\n"
"}\n"
"QTableView::item:selected\n"
"{\n"
"    color: red;\n"
"    background: #0063cd;\n"
"}\n"
"\n"
"QCheckBox::indicator:checked, QCheckBox::indicator:unchecked{\n"
"    color: #b1b1b1;\n"
"    background-color: #323232;\n"
"    border: 1px solid #b1b1b1;\n"
"    border-radius: 1px;\n"
"    width: 7px;\n"
"    height: 7px;\n"
"    margin: 0px 5px 0 5px;\n"
"}\n"
"\n"
"    padding-left:10px;\n"
"    height:100px;\n"
"    width:180px;\n"
"    color: #5a5a5a;\n"
"    border-bottom :1px solid #f0f0f0;"));
        groupBox_8 = new QGroupBox(tab_7);
        groupBox_8->setObjectName(QStringLiteral("groupBox_8"));
        groupBox_8->setGeometry(QRect(20, 40, 141, 201));
        groupBox_8->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));
        layoutWidget_19 = new QWidget(groupBox_8);
        layoutWidget_19->setObjectName(QStringLiteral("layoutWidget_19"));
        layoutWidget_19->setGeometry(QRect(10, 30, 104, 71));
        verticalLayout_31 = new QVBoxLayout(layoutWidget_19);
        verticalLayout_31->setObjectName(QStringLiteral("verticalLayout_31"));
        verticalLayout_31->setContentsMargins(0, 0, 0, 0);
        radio_keyperso = new QRadioButton(layoutWidget_19);
        radio_keyperso->setObjectName(QStringLiteral("radio_keyperso"));
        radio_keyperso->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_31->addWidget(radio_keyperso);

        radio_nom = new QRadioButton(layoutWidget_19);
        radio_nom->setObjectName(QStringLiteral("radio_nom"));
        radio_nom->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_31->addWidget(radio_nom);

        radio_age = new QRadioButton(layoutWidget_19);
        radio_age->setObjectName(QStringLiteral("radio_age"));
        radio_age->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout_31->addWidget(radio_age);

        groupBox_3 = new QGroupBox(groupBox_8);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 110, 120, 80));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 103, 46));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        croissant_5 = new QRadioButton(layoutWidget);
        croissant_5->setObjectName(QStringLiteral("croissant_5"));

        verticalLayout->addWidget(croissant_5);

        decroissant = new QRadioButton(layoutWidget);
        decroissant->setObjectName(QStringLiteral("decroissant"));

        verticalLayout->addWidget(decroissant);

        pushButton_2 = new QPushButton(tab_7);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 300, 111, 41));
        pushButton_2->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        pushButton_4 = new QPushButton(tab_7);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(40, 250, 111, 41));
        pushButton_4->setFont(font2);
        pushButton_4->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        pushButton_10 = new QPushButton(tab_7);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));
        pushButton_10->setGeometry(QRect(40, 350, 111, 41));
        pushButton_10->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QStringLiteral("tab_8"));
        suppression_5 = new QGroupBox(tab_8);
        suppression_5->setObjectName(QStringLiteral("suppression_5"));
        suppression_5->setGeometry(QRect(90, 0, 631, 101));
        suppression_5->setStyleSheet(QLatin1String("\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"color:white"));
        label_78 = new QLabel(suppression_5);
        label_78->setObjectName(QStringLiteral("label_78"));
        label_78->setGeometry(QRect(130, 30, 121, 41));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_78->setPalette(palette7);
        QFont font4;
        font4.setFamily(QStringLiteral("MS Shell Dlg 2"));
        font4.setPointSize(15);
        font4.setBold(false);
        font4.setItalic(false);
        font4.setWeight(9);
        label_78->setFont(font4);
        supprimer_keyperso = new QLineEdit(suppression_5);
        supprimer_keyperso->setObjectName(QStringLiteral("supprimer_keyperso"));
        supprimer_keyperso->setGeometry(QRect(270, 30, 181, 41));
        supprimer_keyperso->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        supprimer_keyperso_btn = new QPushButton(suppression_5);
        supprimer_keyperso_btn->setObjectName(QStringLiteral("supprimer_keyperso_btn"));
        supprimer_keyperso_btn->setGeometry(QRect(530, 70, 93, 28));
        supprimer_keyperso_btn->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        tabWidget_2->addTab(tab_8, QString());
        tab_9 = new QWidget();
        tab_9->setObjectName(QStringLiteral("tab_9"));
        suppression_6 = new QGroupBox(tab_9);
        suppression_6->setObjectName(QStringLiteral("suppression_6"));
        suppression_6->setGeometry(QRect(90, 10, 611, 141));
        suppression_6->setStyleSheet(QLatin1String("\n"
"font: 75 15pt \"MS Shell Dlg 2\";\n"
"color:white"));
        label_79 = new QLabel(suppression_6);
        label_79->setObjectName(QStringLiteral("label_79"));
        label_79->setGeometry(QRect(80, 50, 151, 41));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_79->setPalette(palette8);
        label_79->setFont(font4);
        keyperso_modifier_2 = new QLineEdit(suppression_6);
        keyperso_modifier_2->setObjectName(QStringLiteral("keyperso_modifier_2"));
        keyperso_modifier_2->setGeometry(QRect(260, 50, 181, 41));
        keyperso_modifier_2->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        chercher_modifier_2 = new QPushButton(suppression_6);
        chercher_modifier_2->setObjectName(QStringLiteral("chercher_modifier_2"));
        chercher_modifier_2->setGeometry(QRect(310, 100, 93, 28));
        chercher_modifier_2->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        groupBox_9 = new QGroupBox(tab_9);
        groupBox_9->setObjectName(QStringLiteral("groupBox_9"));
        groupBox_9->setEnabled(true);
        groupBox_9->setGeometry(QRect(0, 160, 821, 371));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        groupBox_9->setPalette(palette9);
        groupBox_9->setFont(font1);
        groupBox_9->setTabletTracking(false);
        groupBox_9->setAutoFillBackground(false);
        pb_modifier_7 = new QPushButton(groupBox_9);
        pb_modifier_7->setObjectName(QStringLiteral("pb_modifier_7"));
        pb_modifier_7->setGeometry(QRect(540, 320, 131, 41));
        pb_modifier_7->setFont(font2);
        pb_modifier_7->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        reset_ajouter_6 = new QPushButton(groupBox_9);
        reset_ajouter_6->setObjectName(QStringLiteral("reset_ajouter_6"));
        reset_ajouter_6->setGeometry(QRect(680, 320, 131, 41));
        reset_ajouter_6->setStyleSheet(QLatin1String("QPushButton{\n"
"\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"\n"
"}\n"
"QPushButton:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));
        layoutWidget_16 = new QWidget(groupBox_9);
        layoutWidget_16->setObjectName(QStringLiteral("layoutWidget_16"));
        layoutWidget_16->setGeometry(QRect(20, 60, 491, 251));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget_16);
        horizontalLayout_16->setObjectName(QStringLiteral("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        verticalLayout_23 = new QVBoxLayout();
        verticalLayout_23->setObjectName(QStringLiteral("verticalLayout_23"));
        label_80 = new QLabel(layoutWidget_16);
        label_80->setObjectName(QStringLiteral("label_80"));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_80->setPalette(palette10);
        label_80->setFont(font3);

        verticalLayout_23->addWidget(label_80);

        label_81 = new QLabel(layoutWidget_16);
        label_81->setObjectName(QStringLiteral("label_81"));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Light, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Midlight, brush5);
        palette11.setBrush(QPalette::Active, QPalette::Dark, brush6);
        palette11.setBrush(QPalette::Active, QPalette::Mid, brush7);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush8);
        palette11.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush8);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Shadow, brush8);
        palette11.setBrush(QPalette::Active, QPalette::AlternateBase, brush9);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipBase, brush10);
        palette11.setBrush(QPalette::Active, QPalette::ToolTipText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Light, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Midlight, brush5);
        palette11.setBrush(QPalette::Inactive, QPalette::Dark, brush6);
        palette11.setBrush(QPalette::Inactive, QPalette::Mid, brush7);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Shadow, brush8);
        palette11.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush9);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush10);
        palette11.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush4);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Light, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Midlight, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::Dark, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Mid, brush7);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush6);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Shadow, brush8);
        palette11.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush10);
        palette11.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush8);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_81->setPalette(palette11);
        label_81->setFont(font3);

        verticalLayout_23->addWidget(label_81);

        label_82 = new QLabel(layoutWidget_16);
        label_82->setObjectName(QStringLiteral("label_82"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_82->setPalette(palette12);
        label_82->setFont(font3);

        verticalLayout_23->addWidget(label_82);

        label_83 = new QLabel(layoutWidget_16);
        label_83->setObjectName(QStringLiteral("label_83"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_83->setPalette(palette13);
        label_83->setFont(font3);

        verticalLayout_23->addWidget(label_83);

        label_84 = new QLabel(layoutWidget_16);
        label_84->setObjectName(QStringLiteral("label_84"));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush3);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        label_84->setPalette(palette14);
        label_84->setFont(font3);

        verticalLayout_23->addWidget(label_84);


        horizontalLayout_16->addLayout(verticalLayout_23);

        verticalLayout_24 = new QVBoxLayout();
        verticalLayout_24->setObjectName(QStringLiteral("verticalLayout_24"));
        keyperso_modifier = new QLineEdit(layoutWidget_16);
        keyperso_modifier->setObjectName(QStringLiteral("keyperso_modifier"));
        keyperso_modifier->setFont(font2);
        keyperso_modifier->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_24->addWidget(keyperso_modifier);

        nom_modifier = new QLineEdit(layoutWidget_16);
        nom_modifier->setObjectName(QStringLiteral("nom_modifier"));
        nom_modifier->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_24->addWidget(nom_modifier);

        prenom_modifier = new QLineEdit(layoutWidget_16);
        prenom_modifier->setObjectName(QStringLiteral("prenom_modifier"));
        prenom_modifier->setFont(font2);
        prenom_modifier->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_24->addWidget(prenom_modifier);

        pass_modifier = new QLineEdit(layoutWidget_16);
        pass_modifier->setObjectName(QStringLiteral("pass_modifier"));
        pass_modifier->setFont(font2);
        pass_modifier->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_24->addWidget(pass_modifier);

        age_modifier = new QLineEdit(layoutWidget_16);
        age_modifier->setObjectName(QStringLiteral("age_modifier"));
        age_modifier->setStyleSheet(QLatin1String("QLineEdit{\n"
"color: white;\n"
"background-color:Transparent;;\n"
"border-width: 2px;\n"
"border-color: #F9F9F9;\n"
"border-style: solid;\n"
"border-radius: 7;\n"
"padding: 3px;\n"
"font-size: 15px;\n"
"\n"
"}\n"
"QLineEdit:focus\n"
"{border:2px solid #FBAD25;\n"
"}"));

        verticalLayout_24->addWidget(age_modifier);


        horizontalLayout_16->addLayout(verticalLayout_24);

        tabWidget_2->addTab(tab_9, QString());

        retranslateUi(home);

        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(home);
    } // setupUi

    void retranslateUi(QDialog *home)
    {
        home->setWindowTitle(QApplication::translate("home", "Dialog", Q_NULLPTR));
        label_20->setText(QString());
#ifndef QT_NO_TOOLTIP
        groupBox_7->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox_7->setTitle(QApplication::translate("home", "Ajout", Q_NULLPTR));
        pb_ajouter_3->setText(QApplication::translate("home", "Valider", Q_NULLPTR));
        reset_ajouter_5->setText(QApplication::translate("home", "reset", Q_NULLPTR));
        label_50->setText(QApplication::translate("home", "MATRICULE", Q_NULLPTR));
        label_66->setText(QApplication::translate("home", "cin", Q_NULLPTR));
        label_62->setText(QApplication::translate("home", "Nom", Q_NULLPTR));
        label_53->setText(QApplication::translate("home", "Prenom", Q_NULLPTR));
        label_54->setText(QApplication::translate("home", "pass", Q_NULLPTR));
        label_64->setText(QApplication::translate("home", "age", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(AjouterEmployee_3), QApplication::translate("home", "Ajouter animateur", Q_NULLPTR));
        groupBox_8->setTitle(QApplication::translate("home", "trier par", Q_NULLPTR));
        radio_keyperso->setText(QApplication::translate("home", "cin", Q_NULLPTR));
        radio_nom->setText(QApplication::translate("home", "nom", Q_NULLPTR));
        radio_age->setText(QApplication::translate("home", "age", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("home", "ORDER", Q_NULLPTR));
        croissant_5->setText(QApplication::translate("home", "CROISASNT", Q_NULLPTR));
        decroissant->setText(QApplication::translate("home", "DECROISSANT", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("home", "pdf", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("home", "statiqtique", Q_NULLPTR));
        pushButton_10->setText(QApplication::translate("home", "imprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("home", "Afficher animateur", Q_NULLPTR));
        suppression_5->setTitle(QApplication::translate("home", "Suppression", Q_NULLPTR));
        label_78->setText(QApplication::translate("home", "CIN", Q_NULLPTR));
        supprimer_keyperso_btn->setText(QApplication::translate("home", "Supprimer", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("home", "Supprimer animateur", Q_NULLPTR));
        suppression_6->setTitle(QApplication::translate("home", "Modification", Q_NULLPTR));
        label_79->setText(QApplication::translate("home", "CIN", Q_NULLPTR));
        chercher_modifier_2->setText(QApplication::translate("home", "Chercher", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        groupBox_9->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        groupBox_9->setTitle(QApplication::translate("home", "modifier", Q_NULLPTR));
        pb_modifier_7->setText(QApplication::translate("home", "modifier", Q_NULLPTR));
        reset_ajouter_6->setText(QApplication::translate("home", "reset", Q_NULLPTR));
        label_80->setText(QApplication::translate("home", "keyperso :", Q_NULLPTR));
        label_81->setText(QApplication::translate("home", "Nom", Q_NULLPTR));
        label_82->setText(QApplication::translate("home", "Prenom", Q_NULLPTR));
        label_83->setText(QApplication::translate("home", "pass", Q_NULLPTR));
        label_84->setText(QApplication::translate("home", "age", Q_NULLPTR));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_9), QApplication::translate("home", "Modifier animateur", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class home: public Ui_home {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOME_H

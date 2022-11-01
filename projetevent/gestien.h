#ifndef GESTIEN_H
#define GESTIEN_H

#include <QDialog>
#include "evenement.h"
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
    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_modifier_clicked();

    void on_pushButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_ajouter_clicked();

    void on_pushButton_supprimer_clicked();

    void on_pushButton_6_pressed();

    void on_pushButton_3_pressed();

private:
    Ui::gestien *ui;
    evenement etmp;
    evenement tmp;
};

#endif // GESTIEN_H

#include "notification.h"

#include <QSystemTrayIcon>
#include<QString>
notification::notification()
{

}

void notification::notification_ajoutpartenair()
{

    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des partenair ","nouveau partenair est ajouté ",QSystemTrayIcon::Information,15000);
}

void notification::notification_supprimerpartenair(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des partenair","nouveau partenair est supprimé",QSystemTrayIcon::Information,15000);
}


void notification::notification_modifierpartenair(){
    QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

   // notifyIcon->setIcon(QIcon(":/new/prefix1/MyResources/computer-icons-avatar-user-login-avatar.jpg"));
    notifyIcon->show();
    notifyIcon->showMessage("Gestion des partenair ","nouveau partenair est modifié",QSystemTrayIcon::Information,15000);

}


















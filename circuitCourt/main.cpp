#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
          db.setHostName("localhost");
          db.setDatabaseName("dbCircuitsCourts");
          db.setUserName("userCircuitsCourts");
          db.setPassword("57-Ze!_eR");
          bool ok = db.open();
          if(ok){
              qDebug()<<"Base de données connectée.";
          }
    qDebug()<<argv[1];
    QApplication a(argc, argv);
    //on récupère l'argument
    MainWindow w(argv[1]);
    w.show();

    return a.exec();
}

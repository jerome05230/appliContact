#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QSqlDatabase dbContact=QSqlDatabase::addDatabase("QMYSQL");
    dbContact.setDatabaseName("dbContact");
    dbContact.setUserName("adminDbContact");
    dbContact.setPassword("123456789");
    if(dbContact.open())
    {
        mainWindow w;
        w.show();
        return a.exec();
    }
    else
    {
        qDebug() << "erreur de connexion à la base de donnée" << endl;
         return -125;
    }
}

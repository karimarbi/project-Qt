#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connexion.h"
#include <QtSql/QSqlDatabase>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connexion c;
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("Connexion successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("Connexion failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}


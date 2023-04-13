#include "Maman.h"
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QSqlQueryModel>
#include <QSystemTrayIcon>
#include <QTableView>
#include <QTableWidget>
#include <QPainter>
#include <QtGui>
#include <QTextDocument>
#include <QFileDialog>
#include "ui_mainwindow.h"
#include <QMainWindow>

Maman::Maman()

    {nom=" ";prenom=" ";IDD=0;age=0;enfant=0;tel="";}
    Maman::Maman(QString nom, QString prenom ,int IDD,int age,int enfant,QString tel)
    {this->nom=nom;this->prenom=prenom;this->IDD=IDD;this->age=age;this->enfant=enfant;this->tel=tel;}

    QString Maman::getnom(){return nom;}
    QString Maman::getprenom(){return prenom;}
    int Maman::getIDD(){return IDD;}
    int Maman::getage (){return age;}
    int Maman::getenfant (){return enfant;}
    QString Maman::gettel(){return tel;}

    void Maman::setnom (QString nom){this->nom=nom;}
    void Maman::setprenom (QString prenom){this->prenom=prenom;}
    void Maman::setenfant (int enfant){this->enfant=enfant;}
    void Maman::setage(int age) {this->age=age;}
    void Maman::setIDD(int IDD){this->IDD=IDD;}
    void Maman::settel(QString tel){this->tel=tel;}




    bool Maman::ajouter()

    {
        QSqlQuery query;
        QString IDD_string=QString::number(IDD);
        QString age_string= QString::number(age);
        QString enfant_string= QString::number(enfant);
             query.prepare("INSERT INTO Maman (nom,prenom,IDD,age,enfant,tel) "
                           "VALUES (:nom, :prenom,:IDD, :age,:enfant, :tel)");

             query.bindValue(":nom", nom);
             query.bindValue(":prenom", prenom);
             query.bindValue(":IDD", IDD_string);
             query.bindValue(":age",age_string);
             query.bindValue(":enfant", enfant_string);
             query.bindValue(":tel",tel);


             return query.exec();
    }




    bool Maman::modifier(int IDD)
    {


    QSqlQuery query;
    QString IDD_string= QString::number(IDD);
    QString age_string= QString::number(age);
    QString enfant_string= QString::number(enfant);

    query.prepare("UPDATE Maman set nom=:nom,prenom=:prenom,IDD=:IDD,age=:age, enfant =:enfant, tel=:tel" " WHERE IDD=:IDD");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
     query.bindValue(":IDD", IDD_string);
    query.bindValue(":age", age_string);
    query.bindValue(":enfant", enfant_string);
    query.bindValue(":tel", tel);
    return    query.exec();
    }




    bool Maman::supprimer(int IDD )
    {   QSqlQuery query;


             query.prepare("delete from Maman where IDD=:IDD");
             query.bindValue(0, IDD);


             return query.exec();




    }

    QSqlQueryModel* Maman::afficher()
    {
        QSqlQueryModel* model=new QSqlQueryModel();
        model ->setQuery("SELECT * FROM Maman");
        model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("nom"));
        model ->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
        model ->setHeaderData(2,Qt::Horizontal,QObject::tr("IDD"));
        model ->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
        model ->setHeaderData(4,Qt::Horizontal,QObject::tr("enfant"));
        model ->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));


        return model;
    }


    bool Maman::chercher(int IDD)
    {
        QSqlQuery query;
         QString IDD_string= QString::number(IDD);
        query.exec("SELECT * FROM Maman WHERE IDD='"+IDD_string+"'");


        while (query.next()) {
            return  true;

        }
        return false;

    }








    QSqlQueryModel * Maman::trie()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

                model->setQuery("SELECT * FROM Maman ORDER BY IDD ASC ");
                model ->setHeaderData(0, Qt::Horizontal ,QObject::tr("nom"));
                model ->setHeaderData(1,Qt::Horizontal,QObject::tr("prenom"));
                model ->setHeaderData(2,Qt::Horizontal,QObject::tr("IDD"));
                model ->setHeaderData(3,Qt::Horizontal,QObject::tr("age"));
                model ->setHeaderData(4,Qt::Horizontal,QObject::tr("enfant"));
                model ->setHeaderData(5,Qt::Horizontal,QObject::tr("tel"));
        return model;
    }




    void Maman::notifications_ajouter()
    {

        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

        notifyIcon->show();
        notifyIcon->showMessage("Gestion des Mamans ","Maman ajoutée ",QSystemTrayIcon::Information,15000);
    }

    void Maman::notifications_supprimer()
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;


        notifyIcon->show();
        notifyIcon->showMessage("Gestion des Mamans ","Maman Supprimée",QSystemTrayIcon::Information,15000);
    }


    void Maman::notifications_modifier()
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

        notifyIcon->show();
        notifyIcon->showMessage("Gestion des Mamans ","Maman est modifiée",QSystemTrayIcon::Information,15000);

    }

    void Maman::notifications_trouver()
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

        notifyIcon->show();
        notifyIcon->showMessage("Gestion des Mamans ","Compte trouvé",QSystemTrayIcon::Information,15000);

    }


    void Maman::notifications_donetri()
    {
        QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;

        notifyIcon->show();
        notifyIcon->showMessage("Gestion des Mamans ","Data trié",QSystemTrayIcon::Information,15000);

    }




    void Maman::statistique(QVector<double>* ticks,QVector<QString> *labels)

        {QSqlQuery q;

            int i=0;

            q.exec("SELECT enfant FROM Maman");

            while (q.next())

            {

                QString enfant = q.value(0).toString();

                i++;

                *ticks<<i;

                *labels <<enfant;

            }

    }


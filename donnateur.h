#ifndef DONNATEUR_H
#define DONNATEUR_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QGridLayout>
#include <QtCharts>
#include <QChartView>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSlice>


class Donnateur
{
public:
   Donnateur();
   Donnateur(int,QString,QString,QString,QString);
   int getid();
   QString getnom();
   QString getprenom();
   QString getemail();
   QString gettel();
   void setid(int);
    void setnom(QString);
     void setprenom(QString);
      void setemail(QString);
      void settel(QString);
      bool ajouter();
      bool supprimer(int id);
      QSqlQueryModel* afficher();
 bool modifier(int id,QString nom,QString prenom,QString adresse,QString num_telephone);
       QSqlQueryModel*  tester();
       QSqlQueryModel* findbyid(QString);
       QSqlQueryModel* trie(QString croissance,QString critere);
       QChartView *stat_capacite();
void  imprimer(QString id);
void  sendEmail();

private:
   int id;
   QString nom;
   QString prenom;
   QString adresse;
   QString num_telephone;


};

#endif // DONNATEUR_H


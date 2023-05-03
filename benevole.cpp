#include "benevole.h"
#include<QSqlQuery>
#include<QtDebug>
#include <iostream>
#include<QObject>
#include <QString>
using namespace std;
//ici c'st la gestion de client
Benevole::Benevole()
{
    id_benevole=0;
    nom="";
    prenom="";

   tel="";
   adresse="";


}
Benevole::Benevole(int id_benevole ,QString nom,QString prenom,QString tel , QString adresse)
{

    this->id_benevole=id_benevole;
    this->nom=nom;
    this->prenom=prenom;
   this->tel=tel;
   this->adresse=adresse;


};
int Benevole::getid()
{
    return id_benevole;

}
QString Benevole::getnom()
{
    return nom;

}
QString Benevole::getprenom()
{
    return prenom;

}

QString Benevole::gettel()
{
    return tel;

}
QString Benevole::getadresse()
{return adresse;}
void Benevole::setid(int id)
{
    this->id_benevole=id;

}
void Benevole::setnom(QString nom)
{
    this->nom=nom;
}
void Benevole::setprenom(QString prenom)
{
    this->prenom=prenom;
}
void Benevole::settel(QString tel)

{
    this->tel=tel;
}
void Benevole::setadresse(QString adresse)
{
    this->adresse=adresse;
}

bool Benevole::ajouter()
{//bool test=false;
    QSqlQuery query;


          query.prepare("INSERT INTO benevoles (id_benevole,nom,prenom,tel,adresse) "
                        "VALUES (:id_benevole,:nom,:prenom,:tel,:adresse)");
          query.bindValue(":id_benevole",id_benevole);
          query.bindValue(":nom",nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":tel", tel);
          query.bindValue(":adresse",adresse);



          return query.exec();   //execution de requette
};

 QSqlQueryModel* Benevole:: afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM Benevoles");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Benevole"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Telephone"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));

     return model;

 }



 bool Benevole::supprimer(int id)
 {
     QSqlQuery query;
     QString res=QString::number(id);
     query.prepare("Delete From Benevoles where id_benevole = :id");
     query.bindValue(0, res);
     return query.exec();


 }
 bool Benevole::modifier(int id_benevole,QString nom,QString prenom,QString tel,QString adresse)
 {
      QSqlQuery query;
     query.prepare("update benevoles set id_benevole=:id_benevole,nom=:nom,prenom=:prenom,tel=:tel ,adresse=:adresse where id_benevole=:id_benevole");
     query.bindValue(":id_benevole",id_benevole);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":tel",tel);
     query.bindValue(":adresse",adresse);

     return query.exec();

 }
 QSqlQueryModel* Benevole:: tester()
 {
     QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
    model->setQuery("SELECT id_benevole FROM Benevoles");// ce modele contient les id Benevole des Benevoles seulement
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID Benevole"));
    return model;
 }

 QSqlQueryModel *Benevole::rechercher(QString rech)
 {
     QSqlQueryModel * model= new QSqlQueryModel();

         model->setQuery("select * from Benevoles where id_benevole LIKE '"+rech+"%'");
     return model;
 }






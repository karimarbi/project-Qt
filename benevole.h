#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>


class Benevole
{
public:
    Benevole();
    Benevole(int,QString,QString,QString,QString);
    int getid();
    QString getnom();
    QString getprenom();
    QString gettel();
    QString getadresse();
    void setid(int);
     void setnom(QString);
      void setprenom(QString);

       void settel(QString);
       void setadresse(QString);
       bool ajouter();
       bool supprimer(int id);
       QSqlQueryModel* afficher();
        bool modifier(int id,QString nom,QString prenom,QString tel,QString adresse);
        QSqlQueryModel*  tester();

        QSqlQueryModel * rechercher(QString);



private:
    int id_benevole;
    QString nom;
    QString prenom;
    QString tel,adresse;



};

#endif // CLIENT_H

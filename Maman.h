#ifndef Maman_H
#define Maman_H
#include <QString>
#include <QSqlQueryModel>
#include <QDate>
#include <QTableWidget>
class Maman
{
public:
    Maman();
    Maman(QString,QString,int,int,int,QString);

    QString getnom();
    QString getprenom();
    int getIDD ();
    int getage ();
    int getenfant();
    QString gettel();


    void setnom (QString);
    void setprenom (QString);
    void setIDD(int);
    void setage(int);
    void setenfant(int);
    void settel(QString);


    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer (int);
     bool modifier(int);
     bool chercher(int);
     void notifications_ajouter();
     void notifications_supprimer();
     void notifications_modifier();
     void notifications_trouver();
     void notifications_donetri();
     QSqlQueryModel * trie();
     void statistique(QVector<double>* ticks,QVector<QString> *labels);
private:
    QString nom , prenom ,tel;
 int IDD ,age, enfant;

};



#endif // Maman_H

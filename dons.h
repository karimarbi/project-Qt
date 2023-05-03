#ifndef DONS_H
#define DONS_H

#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>

class Dons
{
public:
    Dons();
    Dons(int,QString,int,int);
    bool ajouter();
    QSqlQueryModel *afficher();
    bool supprimer(int);
    bool modifier(int);
    void set_ID(int id){ID_DONS=id;};
    void set_nom(QString nom){NOM=nom;};
    void set_quantite(int quantite){QUANTITE=quantite;};
    void set_montant(int montant){MONTANT=montant;};
    int get_ID(){return ID_DONS;};
    QString get_nom(){return NOM;};
    int get_quantite(){return QUANTITE;};
    int get_montant(){return MONTANT;};

private:
    int ID_DONS;
    QString NOM;
    int QUANTITE;
    int MONTANT;
};

#endif // DONS_H

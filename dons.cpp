#include "dons.h"

Dons::Dons()
{

}
Dons::Dons(int a,QString b,int c,int d)
{
    ID_DONS=a;
    NOM=b;
    QUANTITE=c;
    MONTANT=d;
}


bool Dons::ajouter()
{
    QSqlQuery query;

    QString res = QString::number(ID_DONS);

    query.prepare("insert into DONS (ID,NOM,QUANTITE,MONTANT)"
                  "values(:ID,:NOM,:QUANTITE,:MONTANT)");
    query.bindValue(":ID", res);
    query.bindValue(":NOM", NOM);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":MONTANT", MONTANT);
    return query.exec();
}
QSqlQueryModel *Dons::afficher()
{
    QSqlQueryModel *model = new QSqlQueryModel();

    model->setQuery("select * from DONS");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("QUANTITE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("MONTANT"));

    return model;
}
bool Dons::supprimer(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Delete from DONS where ID= :ID");
    query.bindValue(":ID", res);

    return query.exec();
}

bool Dons::modifier(int id)
{
    QSqlQuery query;
    QString res = QString::number(id);

    query.prepare("Update DONS SET NOM=:NOM ,QUANTITE=:QUANTITE,MONTANT=:MONTANT where ID= :ID");
    query.bindValue(":ID", res);
    query.bindValue(":NOM", NOM);
    query.bindValue(":QUANTITE", QUANTITE);
    query.bindValue(":MONTANT", MONTANT);

    return query.exec();
}


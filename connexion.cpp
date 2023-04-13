#include "connexion.h"

Connexion::Connexion()
{
}
bool Connexion::createconnect()
{
    bool test=false;
    QSqlDatabase db=QSqlDatabase::addDatabase ("QODBC");
        db.setDatabaseName("projet");
        db.setUserName("system");
        db.setPassword("karim");

        if( db.open())
            test=true;
        return test;


}

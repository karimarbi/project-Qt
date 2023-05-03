#include "login.h"
#include "ui_login.h"
#include <QSqlQuery>
#include <QDebug>
#include <QTextLength>
#include "menu.h"
#include "benevole.h"
#include "ui_menu.h"
#include <QMessageBox>
Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    //int ret=A.connect_arduino(); // lancer la connexion à arduino
    int ret = -1;
    switch(ret){
    case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
        break;
    case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
       break;
    case(-1):qDebug() << "arduino is not available";
    }
     QObject::connect(A.getserial(),SIGNAL(readyRead()),this,SLOT(update_label())); // permet de lancer
     //le slot update_label suite à la reception du signal readyRead (reception des données).





}
void Login::update_label()
{
data="";


data=A.read_from_arduino();


qDebug()<<data;
if(data!="")
{
   if(A.chercherid(data)!=-1)
   {QString nom=A.chercher(data);
       qDebug() << nom ;
       QByteArray x=nom.toUtf8();
       qDebug() << x ;
       A.write_to_arduino(x);
       qDebug()<<"valide";

        }
   else
   { A.write_to_arduino("0"); qDebug()<<"invalide"; }


}
}
Login::~Login()
{
    delete ui;
}


void Login::on_login_clicked()
{
    QString username = ui->lineEdit->text();
    QString password = ui->lineEdit_2->text();
    QString user ;
    QString pswd ;
    QSqlQuery test ;
    test.prepare("SELECT COUNT(*) from LOGIN where USERNAME= :username");
    test.bindValue(":username",username);
    test.exec();
    if (test.next())
    {
    if (test.value(0).toInt() == 1)
    {
    QSqlQuery query ;
    query.prepare("SELECT USERNAME,PASSWORD FROM LOGIN WHERE USERNAME= :username");
    query.bindValue(":username",username);
    query.exec();
    if (query.next())
    {
    user = query.value(0).toString();
    pswd = query.value(1).toString();
    if (username == user && password == pswd)
    {
        QStringList myOptions;
        myOptions << "feryel" << "admin";
        switch(myOptions.indexOf(user))
        {
          case 0:
            hide();

                    m.show();
                   // m.ui->gestionBenevole->setEnabled(false);

                     ui->login->hide();

            break;


        case  1:
            m.show();
            ui->login->hide();
            break ;
    }
    }


    else
    {
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                                        QObject::tr("INCORRECT USERNAME OR PASSWORD.\nCLICK CANCEL TO RETURN."), QMessageBox::Ok);


    }
}

    }
    }
}


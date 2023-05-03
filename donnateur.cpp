#include "donnateur.h"
#include<QSqlQuery>
#include<QtDebug>
#include <iostream>
#include<QObject>
#include <QSqlRecord>
#include <QPdfWriter>
#include <QPainter>

#include <QtNetwork/QSslSocket>
#include <QtNetwork/QSslError>
#include <QtNetwork/QNetworkConfigurationManager>
#include <QtNetwork/QNetworkSession>
#include <QtNetwork/QHostAddress>
#include <QtNetwork/QNetworkInterface>
#include <QtNetwork/QNetworkReply>
#include <QtCore/QSettings>
#include <QtCore/QDebug>
 using namespace std;

Donnateur::Donnateur()
{
    id=0;
    nom=" ";
    prenom="";
    adresse="";
    num_telephone="";


}
Donnateur::Donnateur(int x ,QString y,QString z,QString t,QString w)
{

    id=x;
    nom=y;
    prenom=z;
    adresse=t;
    num_telephone=w;


}
int Donnateur::getid()
{
    return id;

}
QString Donnateur::getnom()
{
    return nom;

}
QString Donnateur::getprenom()
{
    return prenom;

}
QString Donnateur::getemail()
{
    return adresse;

}
QString Donnateur::gettel()
{
    return num_telephone;

}
void Donnateur::setid(int id)
{
    this->id=id;

}
void Donnateur::setnom(QString nom)
{
    this->nom=nom;
}
void Donnateur::setprenom(QString prenom)
{
    this->prenom=prenom;
}
void Donnateur::settel(QString tel)
{
    this->num_telephone=tel;
}
void Donnateur::setemail(QString e_mail)
{
    this->adresse=e_mail;
}
bool Donnateur::ajouter()
{

   QSqlQuery query;
   QString res=QString::number(id);
        query.prepare("INSERT INTO donnateur (ID, NOM, PRENOM, ADRESSE, NUM_TELEPHONE)" "values (:id, :forname, :surname, :toname, :monname)");
        query.bindValue(":id", res);
        query.bindValue(":forname", nom);
        query.bindValue(":surname", prenom);
        query.bindValue(":toname", adresse);
        query.bindValue(":monname", num_telephone);

        return query.exec();




}
 QSqlQueryModel*Donnateur:: afficher()
 {
     QSqlQueryModel* model=new QSqlQueryModel();


     model->setQuery("SELECT* FROM donnateur ");
     model->setHeaderData(0, Qt::Horizontal, QObject::tr("Identifiant"));
     model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
     model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
     model->setHeaderData(3, Qt::Horizontal, QObject::tr("Adresse"));
     model->setHeaderData(4, Qt::Horizontal, QObject::tr("telephone"));
     return model;

 }



 bool Donnateur::supprimer(int id)
 {
     QSqlQuery query;
     QString res=QString::number(id);
     query.prepare("Delete From donnateur where Id= :id");
     query.bindValue(0, res);
     return query.exec();


 }
 bool Donnateur::modifier(int id,QString nom,QString prenom,QString adresse,QString num_telephone)
 {
      QSqlQuery query;
     query.prepare("update donnateur set id=:id,nom=:nom,prenom=:prenom,adresse=:adresse,num_telephone=:num_telephone where id=:id");
     query.bindValue(":id",id);
     query.bindValue(":nom",nom);
     query.bindValue(":prenom",prenom);
     query.bindValue(":adresse",adresse);
     query.bindValue(":num_telephone",num_telephone);
     return query.exec();

 }
 QSqlQueryModel* Donnateur:: tester()
 {
     QSqlQueryModel* model=new QSqlQueryModel();// declaration d'un modele
    model->setQuery("SELECT id FROM donnateur");// ce modele contient les id des donateur seulement
    //model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
    return model;
 }

 QSqlQueryModel* Donnateur::findbyid(QString CODEACTIVITE){
     QSqlQueryModel *modal=new QSqlQueryModel();
     QSqlQuery query;
     query.prepare("select * from donnateur where id like :code");
     query.bindValue(":code", CODEACTIVITE);
     if (query.exec()){
         modal->setQuery(query);
     } else {
      }
     return modal;
 };
 QSqlQueryModel* Donnateur::trie(QString croissance, QString critere)
 {
     QSqlQueryModel* modal = new QSqlQueryModel();
     QString query = "SELECT * FROM donnateur ORDER BY " + critere + " " + croissance;

     modal->setQuery(query);
     return modal;
 }
 QChartView* Donnateur::stat_capacite()
 {
     int a1 = 0;
     int a2 = 0;

     QSqlQuery query;
     query.prepare("SELECT * FROM donnateur WHERE (NOM LIKE 'A%')");
     query.exec();

     while(query.next())
         a1++;

     query.prepare("SELECT * FROM donnateur WHERE (NOM NOT LIKE 'A%')");
     query.exec();

     while(query.next())
         a2++;

     qDebug() << a1 << a2;

     QPieSeries *series = new QPieSeries();
     series->append("Noms commençant par A", a1);
     series->append("Noms ne commençant pas par A", a2);

     QPieSlice *slice = series->slices().at(0);
     slice->setExploded(true);
     slice->setColor("#f37b78");

     QPieSlice *slice2 = series->slices().at(1);
     slice2->setColor("#663333");

     QChart *chart = new QChart();
     chart->addSeries(series);
     chart->setTitle("Statistique du Capacite (basé sur NOM)");

     series->setLabelsVisible();

     QChartView *chartView = new QChartView(chart);
     chartView->setRenderHint(QPainter::Antialiasing);
     chartView->chart()->setAnimationOptions(QChart::AllAnimations);
     chartView->chart()->legend()->hide();
     chartView->resize(1000, 500);
     return chartView;
 }

 void Donnateur::imprimer(QString id)
 {
     QSqlQueryModel *model = findbyid(id);
     Donnateur d;
     if (model->rowCount() > 0) {
         QSqlRecord record = model->record(0);
         d.setid(record.value("id").toInt());
         d.setnom(record.value("nom").toString());
         d.setprenom(record.value("prenom").toString());
         d.setemail(record.value("adresse").toString());
         d.settel(record.value("num_telephone").toString());

         QPdfWriter writer("donor_info.pdf"); // create PDF writer
         QPainter painter(&writer); // create painter
         painter.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing); // set painter options
         painter.setFont(QFont("Helvetica", 12)); // set font

         int x = 100;
         int y = 100;
         painter.drawText(x, y, "Donor Information:"); // draw text
         y += 500;

         painter.drawText(x, y, "ID: " + id);
          y += 500;

         painter.drawText(x, y, "Name: " + d.nom);
           y += 500;

         painter.drawText(x, y, "First Name: " + d.prenom);
           y += 500;

         painter.drawText(x, y, "Address: " + d.adresse);
           y += 500;

         painter.drawText(x, y, "Phone Number: " + d.num_telephone);

         painter.end(); // end painting
     }
     else {
         QMessageBox::critical(nullptr, QObject::tr("Erreur"),
                               QObject::tr("id n'existe pas !\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);
     }
 }
 void Donnateur::sendEmail()
 {
     // Create email message
     QString from = "ala.mazouz@esprit.tn";
     QString to = "alolota21@☺gmail.com";
     QString subject = "Test Email";
     QString body = "This is a test email sent from Qt!";

     QString login = "ala.mazouz@esprit.tn";
     QString password = "alolota2121";

     // Create socket
     QSslSocket socket;
     socket.connectToHostEncrypted("smtp.gmail.com", 465);

     if (socket.waitForConnected()) {
         // Read greeting from server
         if (!socket.waitForReadyRead()) {
             qDebug() << socket.errorString();
             return;
         }
         QString response = QString::fromUtf8(socket.readAll());
         if (!response.startsWith("220")) {
             qDebug() << "Error: " << response;
             return;
         }

         // Send EHLO command
         QString helo = "EHLO localhost\r\n";
         socket.write(helo.toUtf8());
         if (!socket.waitForBytesWritten()) {
             qDebug() << socket.errorString();
             return;
         }
         if (!socket.waitForReadyRead()) {
             qDebug() << socket.errorString();
             return;
         }
         response = QString::fromUtf8(socket.readAll());
         if (!response.startsWith("250")) {
             qDebug() << "Error: " << response;
             return;
         }

         // Send STARTTLS command
         QString starttls = "STARTTLS\r\n";
         socket.write(starttls.toUtf8());
         if (!socket.waitForBytesWritten()) {
             qDebug() << socket.errorString();
             return;
         }
         if (!socket.waitForReadyRead()) {
             qDebug() << socket.errorString();
             return;
         }
         response = QString::fromUtf8(socket.readAll());
         if (!response.startsWith("220")) {
             qDebug() << "Error: " << response;
             return;
         }

         // Start SSL encryption
         socket.setProtocol(QSsl::TlsV1_2);
         socket.startClientEncryption();
         if (!socket.waitForEncrypted()) {
             qDebug() << socket.errorString();
             return;
         }

         // Send EHLO command again
         socket.write(helo.toUtf8());
         if (!socket.waitForBytesWritten()) {
             qDebug() << socket.errorString();
             return;
         }
         if (!socket.waitForReadyRead()) {
             qDebug() << socket.errorString();
             return;
         }
         response = QString::fromUtf8(socket.readAll());
         if (!response.startsWith("250")) {
             qDebug() << "Error: " << response;
             return;
         }

         // Send login command
         QString auth = QString("AUTH LOGIN\r\n");
         socket.write(auth.toUtf8());
         if (!socket.waitForBytesWritten()) {
             qDebug() << socket.errorString();
             return;
         }
         if (!socket.waitForReadyRead()) {
             qDebug() << socket.errorString();
             return;
         }
         response = QString::fromUtf8(socket.readAll());
         if (!response.startsWith("334")) {
             qDebug() << "Error: " << response;
             return;
         }

         // Send email and password
         QByteArray user = QByteArray().append(login).toBase64();
         QByteArray pass = QByteArray().append(password).toBase64();
         socket.write(user + "\r\n");
         if (!socket.waitForBytesWritten()) {
             qDebug() << socket.errorString();
             return;
         }
         if (!socket.waitForReadyRead()) {
             qDebug() << socket.errorString();
             response = QString::fromUtf8(socket.readAll());
             if (!response.startsWith("334")) {
                 qDebug() << "Error: " << response;
                 return;
             }
             socket.write(pass + "\r\n");
             if (!socket.waitForBytesWritten()) {
                 qDebug() << socket.errorString();
                 return;
             }
             if (!socket.waitForReadyRead()) {
                 qDebug() << socket.errorString();
                 return;
             }
             response = QString::fromUtf8(socket.readAll());
             if (!response.startsWith("235")) {
                 qDebug() << "Error: " << response;
                 return;
             }

             // Send mail command
             QString mail = QString("MAIL FROM: <%1>\r\n").arg(from);
             socket.write(mail.toUtf8());
             if (!socket.waitForBytesWritten()) {
                 qDebug() << socket.errorString();
                 return;
             }
             if (!socket.waitForReadyRead()) {
                 qDebug() << socket.errorString();
                 return;
             }
             response = QString::fromUtf8(socket.readAll());
             if (!response.startsWith("250")) {
                 qDebug() << "Error: " << response;
                 return;
             }

             // Send rcpt command
             QString rcpt = QString("RCPT TO: <%1>\r\n").arg(to);
             socket.write(rcpt.toUtf8());
             if (!socket.waitForBytesWritten()) {
                 qDebug() << socket.errorString();
                 return;
             }
             if (!socket.waitForReadyRead()) {
                 qDebug() << socket.errorString();
                 return;
             }
             response = QString::fromUtf8(socket.readAll());
             if (!response.startsWith("250")) {
                 qDebug() << "Error: " << response;
                 return;
             }

             // Send data command
             QString data = "DATA\r\n";
             socket.write(data.toUtf8());
             if (!socket.waitForBytesWritten()) {
                 qDebug() << socket.errorString();
                 return;
             }
             if (!socket.waitForReadyRead()) {
                 qDebug() << socket.errorString();
                 return;
             }
             response = QString::fromUtf8(socket.readAll());
             if (!response.startsWith("354")) {
                 qDebug() << "Error: " << response;
                 return;

                 QString emailContent = "From: " + from + "\r\n" +
                                         "To: " + to + "\r\n" +
                                         "Subject: " + subject + "\r\n" +
                                         "Date: " + QDateTime::currentDateTime().toString(Qt::RFC2822Date) + "\r\n\r\n" +
                                         body + "\r\n.\r\n";
                 socket.write(emailContent.toUtf8());
}}}}










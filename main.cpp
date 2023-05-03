#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "login.h"
#include "qdebug.h"
#include "emailsender.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Login l;
    EmailSender sender;

    QObject::connect(&sender, &EmailSender::emailSent, []() {
        qDebug() << "Email sent successfully";
    });

    QObject::connect(&sender, &EmailSender::emailFailed, [](QString error) {
        qDebug() << "Failed to send email: " << error;
    });

    sender.sendEmail("rania.touihri@esprit.tn", "Test email", "Hello world!", "");



    Connection c;
     //MainWindow w;
    bool test=c.createconnect();
    // MainWindow w;
    if(test)
        // MainWindow w;
    {
        l.show();

          qDebug()<<"database open";
}
    else
      qDebug()<<"database not open";

    return a.exec();
}

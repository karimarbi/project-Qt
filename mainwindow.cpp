#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "Maman.h"
#include <QString>
#include <QTableView>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QMainWindow>
#include <QFileDialog>
#include <QtWidgets/qdialog.h>
#include <QPrinter>
#include <QPrintDialog>
#include <QFileDialog>
#include <QTextDocument>
#include <QFileDialog>
#include <QErrorMessage>
#include <QMessageBox>
#include <QFile>
#include <QDataStream>
#include "qcustomplot.h"
#include <QString>
#include <QComboBox>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include <QCalendarWidget>
#include <QFile>
#include <QFileDialog>
#include <QDebug>
#include <QPrinter>
#include <QPainter>
#include <QKeyEvent>
#include <QCompleter>
#include <QKeyEvent>
#include "exportexcelobject.h"
#include "qrcodegen.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    ui->affichage->setModel(Etmp.afficher());
    ui->affichage_sup->setModel(Etmp.afficher());


}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_ajouter_2_clicked()
{

    QString nom=ui->nom->text();
    QString prenom=ui->prenom->text();
       int IDD=ui->IDD->text().toInt();
       int age=ui->age->text().toInt();
        int enfant=ui->enfant->text().toInt();
        QString tel=ui->tel->text();

        if(nom == ""){
            QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                                QObject::tr("Verifier le nom.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
        } else if(prenom == ""){
            QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                                QObject::tr("Verifier le prenom.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
        } else if(ui->IDD->text() == ""){
            QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                                QObject::tr("Verifier l'ID.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
        } else if(ui->age->text() == ""){
            QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                                QObject::tr("Verifier l'age.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
        }  else if(ui->enfant->text() == ""){
            QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                                QObject::tr("Verifier les enfants.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
        } else if(tel == "" || tel.length() != 8){
            QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                                QObject::tr("Verifier le tel.\n"
                                                            "Click Cancel to exit."), QMessageBox::Cancel);
        } else {
            Maman d (nom,prenom,IDD,age,enfant,tel);

             {
                     bool test=d.ajouter();
                ui->affichage->setModel(d.afficher());
                ui->affichage_sup->setModel(d.afficher());
                     if(test)
                     {  QMessageBox::information(nullptr, QObject::tr("Ajouter un compte"),
                                                 QObject::tr("compte ajoute\n"
                                                             "Cliquez sur cancel Pour Quitter."), QMessageBox::Cancel);
                     ui->statusbar->showMessage("compte ajouté");
                     d.notifications_ajouter();}
                     else
                     {  QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                             QObject::tr("Echec de l'ajout.\n"
                                                         "Click Cancel to exit."), QMessageBox::Cancel);}

                 }
        }



}

void MainWindow::on_pb_stat_2_clicked()
{
    QString nom=ui->nom_2->text();
    QString prenom=ui->prenom_2->text();
    int IDD=ui->IDD_2->text().toInt();
    int age=ui->age_2->text().toInt();
    int enfant=ui->enfant_2->text().toInt();
    QString tel=ui->tel_2->text();
       IDD=ui->IDD_2->text().toInt();
       enfant=ui->enfant_2->text().toInt();
       age=ui->age_2->text().toInt();


    Maman e (nom,prenom,IDD,age,enfant,tel);


    QLinearGradient gradient(0, 0, 0, 400);
                          gradient.setColorAt(0, QColor(90, 90, 90));
                          gradient.setColorAt(0.38, QColor(105, 105, 105));
                          gradient.setColorAt(1, QColor(70, 70, 70));
                          ui->plot->setBackground(QBrush(gradient));

                          QCPBars *amande = new QCPBars(ui->plot->xAxis, ui->plot->yAxis);
                          amande->setAntialiased(false);
                          amande->setStackingGap(1);
                           //couleurs
                          amande->setName("ENFANT");
                          amande->setPen(QPen(QColor(0, 18, 110).lighter(130)));
                          amande->setBrush(QColor(0, 18, 110));

                           //axe des abscisses
                          QVector<double> ticks;
                          QVector<QString> labels;
                          e.statistique(&ticks,&labels);

                          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
                          textTicker->addTicks(ticks, labels);
                          ui->plot->xAxis->setTicker(textTicker);
                          ui->plot->xAxis->setTickLabelRotation(60);
                          ui->plot->xAxis->setSubTicks(false);
                          ui->plot->xAxis->setTickLength(0, 4);
                          ui->plot->xAxis->setRange(0, 8);
                          ui->plot->xAxis->setBasePen(QPen(Qt::white));
                          ui->plot->xAxis->setTickPen(QPen(Qt::white));
                          ui->plot->xAxis->grid()->setVisible(true);
                          ui->plot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
                          ui->plot->xAxis->setTickLabelColor(Qt::white);
                          ui->plot->xAxis->setLabelColor(Qt::white);

                          // axe des ordonnées
                          ui->plot->yAxis->setRange(0,50);
                          ui->plot->yAxis->setPadding(5);
                          ui->plot->yAxis->setLabel("Statistiques");
                          ui->plot->yAxis->setBasePen(QPen(Qt::white));
                          ui->plot->yAxis->setTickPen(QPen(Qt::white));
                          ui->plot->yAxis->setSubTickPen(QPen(Qt::white));
                          ui->plot->yAxis->grid()->setSubGridVisible(true);
                          ui->plot->yAxis->setTickLabelColor(Qt::white);
                          ui->plot->yAxis->setLabelColor(Qt::white);
                          ui->plot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
                          ui->plot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

                          // ajout des données  (statistiques de la quantité)//

                          QVector<double> PlaceData;
                          QSqlQuery q1("select ENFANT from maman");
                          while (q1.next()) {
                                        int  nbr_fautee = q1.value(0).toInt();
                                        PlaceData<< nbr_fautee;
                                          }
                          amande->setData(ticks, PlaceData);

                          ui->plot->legend->setVisible(true);
                          ui->plot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
                          ui->plot->legend->setBrush(QColor(255, 255, 255, 100));
                          ui->plot->legend->setBorderPen(Qt::NoPen);
                          QFont legendFont = font();
                          legendFont.setPointSize(5);
                          ui->plot->legend->setFont(legendFont);
                          ui->plot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);

}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString nom=ui->nom_2->text();
    QString prenom=ui->prenom_2->text();
    int IDD=ui->IDD_2->text().toInt();
    int age=ui->age_2->text().toInt();
    int enfant=ui->enfant_2->text().toInt();
    QString tel=ui->tel_2->text();
       IDD=ui->IDD_2->text().toInt();
       enfant=ui->enfant_2->text().toInt();
       age=ui->age_2->text().toInt();
//controle de saisie
       if(nom == ""){
           QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                               QObject::tr("Verifier le nom.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
       } else if(prenom == ""){
           QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                               QObject::tr("Verifier le prenom.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
       } else if(ui->IDD_2->text() == ""){
           QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                               QObject::tr("Verifier l'ID.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
       } else if(ui->age_2->text() == ""){
           QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                               QObject::tr("Verifier l'age.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
       }  else if(ui->enfant_2->text() == ""){
           QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                               QObject::tr("Verifier les enfants.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
       } else if(tel == "" || tel.length() != 8){
           QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                               QObject::tr("Verifier le tel.\n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);
       } else {
           Maman d (nom,prenom,IDD,age,enfant,tel);



             {
                bool test=d.modifier(IDD);
                if(test){

                    ui->affichage->setModel(d.afficher());
                    QMessageBox::information(nullptr, QObject::tr("modifier "),
                               QObject::tr("Modification effectuée.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->statusbar->showMessage("compte modifié");
                    d.notifications_modifier();
                 } else {
                    QMessageBox::critical(nullptr, QObject::tr("modifier "),
                                   QObject::tr("Echec de la modification  \n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);
                    ui->statusbar->showMessage("compte non modifié");
                }
            }
       }



}



void MainWindow::on_pb_supprimer_2_clicked()
{

    int IDD=ui->id_supp->text().toInt();

   Maman d ;
    bool test=d.supprimer(IDD);

      ui->affichage_sup->setModel(d.afficher());
      ui->affichage->setModel(d.afficher());
    if(test)
    {

        QMessageBox::information(nullptr,QObject::tr("ok"),QObject ::tr("suppression effectuée\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);
    ui->statusbar->showMessage("suppression effectuée");
    d.notifications_supprimer();}
    else
    {
        QMessageBox::critical(nullptr,QObject::tr("not ok"),QObject ::tr("suppression non effectue\n"
                                                                        "Click Cancel to exit"),QMessageBox::Cancel);
    }


}



void MainWindow::on_pb_rechercher_clicked()
{
   Maman d ;

       int IDD=ui->id_supp->text().toInt();


            bool test=d.chercher(IDD);

            if(test)
            {
                QMessageBox::information(nullptr, QObject::tr("Recherche"),
                                        QObject::tr("compte a chercher existe\n"
                                                    "Cliquez sur cancel Pour Quitter."), QMessageBox::Cancel);
            ui->statusbar->showMessage("recherche terminée");
            d.notifications_trouver();}
            else
            {  QMessageBox::warning(nullptr, QObject::tr("erreur"),
                                    QObject::tr("Echec de la recherche.\n"
                                                "Click Cancel to exit."), QMessageBox::Cancel);}

    }

void MainWindow::on_pb_trier_clicked()
{
    Maman F;
    ui->affichage->setModel(F.trie());
     ui->affichage_sup->setModel(F.trie());
    ui->affichage->setModel(F.afficher());
      ui->affichage_sup->setModel(F.afficher());
    bool test=F.trie();
    QMessageBox msgBox ;

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("tri"),
                                QObject::tr("comptes triés \n"
                                            "Cliquez sur cancel Pour Quitter."), QMessageBox::Cancel);
     ui->affichage->setModel(F.trie());
       ui->statusbar->showMessage("comptes triés");
         F.notifications_donetri();
    }
    else
    {  QMessageBox::warning(nullptr, QObject::tr("erreur"),
                            QObject::tr("Echec de la tri.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}


}


////////////////////// PDF/PRINT + EXCEL




void MainWindow::on_pb_excel_clicked()

     //export excel
    {



            QString fileName = QFileDialog::getSaveFileName(this, tr("Excel file"), qApp->applicationDirPath (),
                                                                    tr("Excel Files (*.xls)"));
                    if (fileName.isEmpty())
                        return;

                    ExportExcelObject obj(fileName, "mydata", ui->affichage);

                    obj.addField(0, "nom", "char(20)");
                    obj.addField(1, "prenom", "char(20)");
                    obj.addField(2, "IDD", "char(20)");
                    obj.addField(3, "age", "char(20)");
                    obj.addField(4, "enfant", "char(20)");
                    obj.addField(5, "tel", "char(20)");



                    int retVal = obj.export2Excel();

                    if( retVal > 0)
                    {
                        QMessageBox::information(this, tr("Done"),
                                                 QString(tr("%1 records exported!")).arg(retVal)
                                                 );
                    }

}


void MainWindow::on_pb_print_clicked()
{   QString strStream;

    QTextStream out(&strStream);



QString fileName = QFileDialog::getOpenFileName((QWidget* )0, "ouvrir en PDF", QString(), "*.pdf");
        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }
        QPrinter *printer=new  QPrinter(QPrinter::PrinterResolution);
        printer->setOutputFormat(QPrinter::PdfFormat);
        printer->setPaperSize(QPrinter::A4);
        printer->setOutputFileName(fileName);

        QTextDocument doc;
        doc.setHtml(strStream);
        doc.setPageSize(printer->pageRect().size());
        doc.print(printer);

        QPrinter *p=new QPrinter();
        QPrintDialog dialog(p,this);
        if(dialog.exec()== QDialog::Rejected)
        {
            return;
        }
}



//////////QRCODE


void MainWindow::on_affichage_clicked(const QModelIndex &index)
{
    int tabeq=ui->affichage->currentIndex().row();
      QVariant idd=ui->affichage->model()->data(ui->affichage->model()->index(tabeq,0));
      QString idf=idd.toString();
     // QString code=idd.toSTring();
      QSqlQuery qry;
      qry.prepare("select * from maman where ID=:ID");
      qry.bindValue(":ID",idf);
      qry.exec();

       QString nom,prenom,age,enfant, tel;//attributs
       //int idf;


     while(qry.next()){

          idf=qry.value(0).toString();
          nom=qry.value(1).toString();
          prenom=qry.value(2).toString();
          age=qry.value(3).toInt();
          enfant=qry.value(4).toInt();
          tel=qry.value(5).toString();





      }
      idf=QString(idf);
     //QString text = idf ;
             idf="IDD:\t" +idf+ " Nom\t:" +nom+ " Prenom:\t" +prenom+ + " age:\t" +age+ " enfant:\t" +enfant+ " tel:\t" +tel;
      qrcodegen::QrCode qr = qrcodegen::QrCode::encodeText(idf.toUtf8().constData(), qrcodegen::QrCode::Ecc::HIGH);

      // Read the black & white pixels
      QImage im(qr.getSize(),qr.getSize(), QImage::Format_RGB888);
      for (int y = 0; y < qr.getSize(); y++) {
          for (int x = 0; x < qr.getSize(); x++) {
              int color = qr.getModule(x, y);  // 0 for white, 1 for black

              // You need to modify this part
              if(color==0)
                  im.setPixel(x, y,qRgb(254, 254, 254));
              else
                  im.setPixel(x, y,qRgb(0, 0, 0));
          }
      }
      im=im.scaled(200,200);
                ui->QrCode->setPixmap(QPixmap::fromImage(im));

}

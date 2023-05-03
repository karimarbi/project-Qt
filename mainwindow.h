#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"benevole.h"
#include "donnateur.h"
#include <QMainWindow>
#include "maman.h"
#include <QMainWindow>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include "exportexcelobject.h"
#include "arduino.h"
#include "smtp.h"
#include "widget.h"
#include "video.h"
#include "dons.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setCurrentIndex(int);
    ~MainWindow();

private slots:
 ////////////FERYEL//////////


    void on_pushButton_2_clicked();
    void on_bouton_supp_clicked();
    void on_pushButton_clicked();
    //void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_comboBox_2_currentIndexChanged(const QString &arg1);
    void on_rechercher_button_clicked();
    void on_pdf_clicked();
    void on_statsmed_clicked();
    void on_pushButton_trier_ingr_clicked();
    void on_retour_client_ajout_clicked();
    void on_retour_client_affiche_clicked();
    void on_retour_client_supp_clicked();
    void on_retour_client_modif_clicked();
    void on_ajout_client_clicked();
    void on_modif_client_clicked();
    void on_rech_client_clicked();
    void on_supp_client_clicked();
   void on_retour_client_clicked();
    /////////////KARIM//////////////
    void on_pb_ajouter_2_clicked();
        void on_pb_supprimer_2_clicked();
        void on_pb_modifier_2_clicked();
        void on_pb_rechercher_clicked();
        void on_pb_trier_clicked();
        void on_pb_stat_2_clicked();
        void on_pb_excel_clicked();
        void on_pb_print_clicked();
        void on_affichage_k_clicked(const QModelIndex &index);
        void on_ajout_maman_clicked();
         void on_supp_maman_clicked();
            void on_modif_maman_clicked();
            void on_rech_maman_clicked();
            void on_retour_maman_clicked();
            void on_retour_maman_ajout_clicked();
            void on_retour_maman_affiche_clicked();
            void on_retour_maman_supp_clicked();
            void on_retour_maman_modif_clicked();
            void on_pb_arduino_clicked();
   //////////////ROUA/////////////////

    void on_ajouter_r_clicked();
    void on_retour_donnateur_clicked();
    void on_retour_donnateur_ajout_clicked();
    void on_retour_donnateur_affiche_clicked();
    void on_retour_donnateur_supp_clicked();
    void on_retour_donnateur_modif_clicked();
    void on_retour_donnateur_mailing_clicked();
    void on_ajout_donnateur_clicked();
    void on_supp_donnateur_clicked();
    void on_rech_donnateur_clicked();
    void on_modif_donnateur_clicked();
    void on_mailing_donnateur_clicked();
    void on_supp_r_2_clicked();
    void on_modif_r_2_clicked();
    void on_comboBox_r_2_currentIndexChanged(const QString &arg1);
    void on_pb_meilleur_r_clicked();
    void on_radioButton_a_2_clicked();
    void on_radioButton_d_2_clicked();
    void on_pb_meilleur_r_2_clicked();
    void on_afficher_r_clicked();
    void on_chat_r_clicked();
    void  on_browseBtn();
    void on_sendBtn();
   void  mailSent(QString status);
   void on_arduino_r_clicked();
////////////////SADOK///////////////

   void on_bouton_supp_s_clicked();

   void on_pushButton_modif_s_clicked();

   void on_ajout_s_2_clicked();

   void on_button_video_clicked();

   void on_qrcode_clicked();

   void update_label();   // slot permettant la mise à jour du label état de la lampe 1,
           // ce slot est lancé à chaque réception d'un message de Arduino

   void on_arduino_s_clicked();

   void on_retour_don_clicked();
   void on_retour_don_ajout_clicked();
   void on_retour_don_affiche_clicked();
   void on_retour_don_supp_clicked();
   void on_retour_don_modif_clicked();

   void on_ajouter_don_clicked();
   void on_supp_don_clicked();
   void on_rech_don_clicked();
   void on_modifier_don_clicked();

private:
    Ui::MainWindow *ui;
    Benevole c;
   Maman Etmp ;
   QStringList files;
    QByteArray data;
    Donnateur D;
    Dons Dtmp;
     Arduino a;
};

#endif // MAINWINDOW_H

#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "benevole.h"
#include "mainwindow.h"
#include "maman.h"
namespace Ui {
class Menu;
}

class Menu : public QDialog
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private slots:
    void on_gestionDon_clicked();
    void on_gestionDonnateur_clicked();
    void on_gestionBene_clicked();
    void on_gestionMaman_clicked();
    void on_logout_clicked();



public:
    Ui::Menu *ui;

private:
    MainWindow feryel;

};

#endif // MENU_H

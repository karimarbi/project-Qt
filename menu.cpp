#include "menu.h"
#include "ui_menu.h"
#include "login.h"
#include "benevole.h"
#include "maman.h"
#include "ui_login.h"

Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_gestionDon_clicked()
{
    feryel.show();
    feryel.setCurrentIndex(16);

}


//{ui->menu->setCurrentIndex(1);}

void Menu::on_gestionMaman_clicked()
{
    feryel.show();
    feryel.setCurrentIndex(5);

}

void Menu::on_gestionBene_clicked()
{
    feryel.show();
    feryel.setCurrentIndex(0);


}

void Menu::on_gestionDonnateur_clicked()
{
    feryel.show();
    feryel.setCurrentIndex(10);


}

void Menu::on_logout_clicked(){ close();}



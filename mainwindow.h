#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Maman.h"
#include <QMainWindow>
#include <QPainter>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include "exportexcelobject.h"
#include "qrcodegen.hpp"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT


public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_ajouter_2_clicked();
    void on_pb_supprimer_2_clicked();
    void on_pb_modifier_2_clicked();
    void on_pb_rechercher_clicked();
    void on_pb_trier_clicked();
    void on_pb_stat_2_clicked();
    void on_pb_excel_clicked();
    void on_pb_print_clicked();
    void on_affichage_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Maman Etmp ;
};
#endif // MAINWINDOW_H

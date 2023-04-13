/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_nom;
    QLineEdit *lineEdit_prenom;
    QLineEdit *lineEdit_datedemaman;
    QLineEdit *lineEdit_recordmedical;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 50, 711, 471));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 50, 56, 16));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 130, 56, 16));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 220, 101, 16));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 320, 101, 16));
        lineEdit_nom = new QLineEdit(groupBox);
        lineEdit_nom->setObjectName(QStringLiteral("lineEdit_nom"));
        lineEdit_nom->setGeometry(QRect(140, 50, 113, 22));
        lineEdit_prenom = new QLineEdit(groupBox);
        lineEdit_prenom->setObjectName(QStringLiteral("lineEdit_prenom"));
        lineEdit_prenom->setGeometry(QRect(140, 130, 113, 22));
        lineEdit_datedemaman = new QLineEdit(groupBox);
        lineEdit_datedemaman->setObjectName(QStringLiteral("lineEdit_datedemaman"));
        lineEdit_datedemaman->setGeometry(QRect(150, 220, 113, 22));
        lineEdit_recordmedical = new QLineEdit(groupBox);
        lineEdit_recordmedical->setObjectName(QStringLiteral("lineEdit_recordmedical"));
        lineEdit_recordmedical->setGeometry(QRect(150, 320, 113, 22));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(480, 50, 93, 28));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(480, 240, 93, 28));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "gestion des mamans", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "maman", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "nom", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "prenom", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "date de maman", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "Record medical", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "valider", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "quitter", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

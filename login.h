#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include "menu.h"
#include"arduino.h"
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT

public:
    explicit Login(QWidget *parent = nullptr);
    ~Login();

private slots:
    void on_login_clicked();
    void update_label();


private:
    Ui::Login *ui;
    Menu m ;
    Arduino A;
    QByteArray data;

};

#endif // LOGIN_H

#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "admindelete.h"
#include "adminadd.h"
#include "adminstartend.h"
#include "admincheckuser.h"

adminmainwindow::adminmainwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminmainwindow)
{
    ui->setupUi(this);
}

adminmainwindow::~adminmainwindow()
{
    delete ui;
}

void adminmainwindow::on_pushButton_clicked()
{
    admindelete a_del;
    a_del.exec();
}

void adminmainwindow::on_pushButton_2_clicked()
{
    adminadd a_add;
    a_add.exec();
}

void adminmainwindow::on_pushButton_3_clicked()
{
    adminstartend a_sta;
    a_sta.exec();
}

void adminmainwindow::on_pushButton_5_clicked()
{
    admincheckuser a_che;
    a_che.exec();
}

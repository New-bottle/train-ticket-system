#include "adminstartend.h"
#include "ui_adminstartend.h"

adminstartend::adminstartend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminstartend)
{
    ui->setupUi(this);
}

adminstartend::~adminstartend()
{
    delete ui;
}

void adminstartend::on_confirm_start_clicked()
{

}

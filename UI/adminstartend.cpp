#include "adminstartend.h"
#include "ui_adminstartend.h"
#include"../tts_server/header/query.h"
#include"../tts_server/header/server.h"
#include<QMessageBox>

extern sjtu::TTS tts;


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
    bool success = tts.start_selling(sjtu::start_selling_data(ui->start_train->text(), sjtu::transfer_date(ui->dateEdit->text())));
    if(success)
    {
        QMessageBox::Information(this, tr("开始售票成功"),tr("开始售票成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::Warning(this, tr("开始售票失败"),tr("开始售票失败"),QMessageBox::Yes);
    }
}



void adminstartend::on_confirm_end_clicked()
{
    bool success = tts.end_selling(sjtu::end_selling_data(ui->end_train->text(), sjtu::transfer_date(ui->dateEdit_2->text())));
    if(success)
    {
        QMessageBox::Information(this, tr("终止售票成功"),tr("终止售票成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::Warning(this, tr("终止售票失败"),tr("终止售票失败"),QMessageBox::Yes);
    }
}

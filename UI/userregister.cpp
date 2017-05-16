#include "userregister.h"
#include "ui_userregister.h"
#include "userlogin.h"
#include "../tts_server/header/server.h"
#include <QLabel>
#include <QMessageBox>
//#include <>

extern sjtu::TTS tts;

userregister::userregister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userregister)
{
    ui->setupUi(this);
}

userregister::~userregister()
{
    delete ui;
}

void userregister::on_confirm_clicked()
{
    int id = tts.register_user(sjtu::register_user_data(ui->userLineEdit->text(), ui->pwdLineEdit->text()));
//    QMessageBox::information(this, tr("id号"),tr("你的id号是" + QString::number(id)),QMessageBox::Yes);
    QLabel *label = new QLabel("你的id号是" + QString::number(id));
    label->show();
    userlogin u_log;
    u_log.exec();
    this->hide();
}

void userregister::on_cancel_clicked()
{
    this->hide();
}

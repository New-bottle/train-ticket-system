#include "adminregister.h"
#include "ui_adminregister.h"
#include "../tts_server/header/server.h"
#include <QLabel>
#include "adminlogin.h"
#include "../tts_server/header/query.h"
#include <QMessageBox>

extern sjtu::TTS tts;

Adminregister::Adminregister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminregister)
{
    ui->setupUi(this);
}

Adminregister::~Adminregister()
{
    delete ui;
}

void Adminregister::on_confirm_clicked()
{
    if(ui->register_num->text() != "FBI_WARNING")
    {
        QMessageBox::warning(this, tr("邀请码错误！"),tr("邀请码错误，你不是合格司机"),QMessageBox::Yes);
        return;
    }
    int id = tts.register_admin(sjtu::register_admin_data(ui->userLineEdit->text(), ui->pwdLineEdit->text()));
    QLabel * label = new QLabel("你的id号是" + QString::number(id));
    label->show();
    adminlogin a_log;
    a_log.exec();
//    this->close();
}

void Adminregister::on_cancel_clicked()
{
    this->hide();
}

#include "userchangepwd.h"
#include "ui_userchangepwd.h"
#include "usermainwindow.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QMessageBox>

extern sjtu::TTS tts;
extern int ID;

userchangepwd::userchangepwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userchangepwd)
{
    ui->setupUi(this);
}

userchangepwd::~userchangepwd()
{
    delete ui;
}

void userchangepwd::on_pushButton_clicked()
{
    usermainwindow u_main;
    u_main.exec();
}

void userchangepwd::on_pushButton_2_clicked()
{
    if(ui->new_pwd->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Warning"), tr("new password is empty!"), QMessageBox::Yes);
    }
    else
    {
        bool success = tts.change_password(sjtu::change_password_data(ID, ui->new_pwd->text()));
        if(success)
        {
            QMessageBox::information(this, tr("Success"), tr("new password has been accepted"), QMessageBox::Yes);
        }
        else
        {
            QMessageBox::warning(this, tr("Warning"), tr("fail to change password"), QMessageBox::Yes);
        }
        this->hide();
    }
}

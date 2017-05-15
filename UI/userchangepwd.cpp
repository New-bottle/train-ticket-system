#include "userchangepwd.h"
#include "ui_userchangepwd.h"
#include "usermainwindow.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"

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

    }
}

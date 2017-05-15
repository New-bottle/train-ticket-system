#include "searchbyline.h"
#include "ui_searchbyline.h"
#include "usermainwindow.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"

searchbyline::searchbyline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchbyline)
{
    ui->setupUi(this);
}

searchbyline::~searchbyline()
{
    delete ui;
}

void searchbyline::on_pushButton_2_clicked()
{
    usermainwindow u_main;
    u_main.exec();
}


void searchbyline::on_pushButton_clicked()
{

}

#include "searchbyline.h"
#include "ui_searchbyline.h"
#include "usermainwindow.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QTableWidget>
#include <QTableWidgetItem>

extern sjtu::TTS tts;

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
    ui->tableWidget->clear();
    sjtu::check_line_ans ans = tts.check_line(ui->train_name->text());
    QTableWidgetItem one = new QTableWidgetItem("站名");
    QTableWidgetItem two = new QTableWidgetItem("日期");
    QTableWidgetItem three = new QTableWidgetItem("到达时间");
    QTableWidgetItem one = new QTableWidgetItem("停车时间");
    QTableWidgetItem one = new QTableWidgetItem("里程");
    QTableWidgetItem one = new QTableWidgetItem("站名");
    QTableWidgetItem one = new QTableWidgetItem("站名");
    QTableWidgetItem one = new QTableWidgetItem("站名");
    ui->tableWidget->setHorizontalHeaderItem();
}

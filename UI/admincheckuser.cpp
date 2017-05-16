#include "admincheckuser.h"
#include "ui_admincheckuser.h"
#include "adminmainwindow.h"
#include <QModelIndex>
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"

extern sjtu::TTS tts;
extern int ID;

admincheckuser::admincheckuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admincheckuser)
{
    ui->setupUi(this);
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSortingEnabled(true);
}

admincheckuser::~admincheckuser()
{
    delete ui;
}

void admincheckuser::on_pushButton_clicked()
{
    adminmainwindow a_main;
    a_main.exec();
}

void admincheckuser::on_pushButton_2_clicked()
{
    ui->tableWidget->clear();
    sjtu::vector<sjtu::query_my_order_ans> vec = tts.query_my_order(sjtu::query_my_order_data(ui->id->text().toInt()));
    for(int i = 0; i < vec.size(); ++i)
    {
        ui->tableWidget->clear();
        QTableWidgetItem * one = new QTableWidgetItem(vec[i].train_name);
        QTableWidgetItem * two = new QTableWidgetItem(vec[i].start_date);
        QTableWidgetItem * three = new QTableWidgetItem(vec[i].start_station);
        QTableWidgetItem * four = new QTableWidgetItem(vec[i].start_time);
        QTableWidgetItem * five = new QTableWidgetItem(vec[i].end_station);
        QTableWidgetItem * six = new QTableWidgetItem(vec[i].end_time);
        QTableWidgetItem * seven = new QTableWidgetItem(vec[i].seat_kind);
        QTableWidgetItem * eight = new QTableWidgetItem(vec[i].ticket_number);
        ui->tableWidget->setItem(i + 1, 2, one);
        ui->tableWidget->setItem(i + 1, 3, two);
        ui->tableWidget->setItem(i + 1, 4, three);
        ui->tableWidget->setItem(i + 1, 5, four);
        ui->tableWidget->setItem(i + 1, 6, five);
        ui->tableWidget->setItem(i + 1, 7, six);
        ui->tableWidget->setItem(i + 1, 8, seven);
        ui->tableWidget->setItem(i + 1, 9, eight);
    }
}
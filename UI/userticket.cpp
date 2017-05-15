#include "userticket.h"
#include "ui_userticket.h"
#include "userbuy.h"
#include "userreturn.h"
#include "userhistory.h"
#include "usermainwindow.h"
#include "../tts_server/header/server.h"
#include "../tts_server/header/query.h"
#include <QString>
#include "vector.hpp"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>

extern sjtu::TTS tts;
extern int ID;

userticket::userticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userticket)
{
    ui->setupUi(this);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSortingEnabled(true);
    ui->tableWidget_2->setModel(model);
}

userticket::~userticket()
{
    delete ui;
}

void userticket::on_pushButton_clicked()
{
    userbuy u_buy;
    u_buy.exec();
}

void userticket::on_pushButton_2_clicked()
{
    userreturn u_ret;
    u_ret.exec();
}

void userticket::on_pushButton_5_clicked()
{
    userhistory u_his;
    u_his.exec();
}

void userticket::on_pushButton_3_clicked()
{
    usermainwindow u_main;
    u_main.exec();
}

void userticket::on_pushButton_6_clicked()
{
    ui->tableWidget_2->clear();
    sjtu::vector<sjtu::query_my_order_ans> vec = tts.query_my_order(sjtu::query_my_order_data(ID));
    for(int i = 0; i < vec.size(); ++i)
    {
        ui->tableWidget_2->clear();
        QTableWidgetItem * one = new QTableWidgetItem(vec[i].train_name);
        QTableWidgetItem * two = new QTableWidgetItem(vec[i].start_date);
        QTableWidgetItem * three = new QTableWidgetItem(vec[i].start_station);
        QTableWidgetItem * four = new QTableWidgetItem(vec[i].start_time);
        QTableWidgetItem * five = new QTableWidgetItem(vec[i].end_station);
        QTableWidgetItem * six = new QTableWidgetItem(vec[i].end_time);
        QTableWidgetItem * seven = new QTableWidgetItem(vec[i].seat_kind);
        QTableWidgetItem * eight = new QTableWidgetItem(vec[i].ticket_number);
        ui->tableWidget_2->setItem(i + 1, 2, one);
        ui->tableWidget_2->setItem(i + 1, 3, two);
        ui->tableWidget_2->setItem(i + 1, 4, three);
        ui->tableWidget_2->setItem(i + 1, 5, four);
        ui->tableWidget_2->setItem(i + 1, 6, five);
        ui->tableWidget_2->setItem(i + 1, 7, six);
        ui->tableWidget_2->setItem(i + 1, 8, seven);
        ui->tableWidget_2->setItem(i + 1, 9, eight);
    }
}

void userticket::on_tableWidget_2_itemClicked(QTableWidgetItem *item){}

#include "userreturn.h"
#include "ui_userreturn.h"
#include "usermainwindow.h"
#include "userbuy.h"
#include "userticket.h"
#include "userhistory.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>


extern sjtu::TTS tts;
extern int ID;

userreturn::userreturn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userreturn)
{
    ui->setupUi(this);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSortingEnabled(true);
    ui->tableWidget_2->setModel(model);
}

userreturn::~userreturn()
{
    delete ui;
}

void userreturn::on_pushButton_clicked()
{
    usermainwindow u_main;
    u_main.exec();
}

void userreturn::on_pushButton_2_clicked()
{
    userbuy u_buy;
    u_buy.exec();
}

void userreturn::on_pushButton_4_clicked()
{
    userticket u_tic;
    u_tic.exec();
}

void userreturn::on_pushButton_3_clicked()
{
    userhistory u_his;
    u_his.exec();
}

void userreturn::on_tableWidget_clicked(const QModelIndex &index)
{
    Ind = index;
}

void userreturn::on_show_order_clicked()
{
    sjtu::vector<sjtu::query_my_order_ans> vec = tts.query_my_order(sjtu::query_my_order_data(ID));
    for(int i = 0; i < vec.size(); ++i)
    {
        ui->tableWidget->clear();
        ui->tableWidget_2->clear();
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


void userreturn::on_pushButton_5_clicked()
{
    sjtu::return_tickets_data data;
    data.ID = ID;
    data.train_name = ui->tableWidget->itemAt(Ind.row(), 2);
    data.start_date = ui->tableWidget->itemAt(Ind.row(), 3);
    data.start_station = ui->tableWidget->itemAt(Ind.row(), 4);
    data.end_station = ui->tableWidget->itemAt(Int.row(), 6);
    data.seat_kind = ui->tableWidget->itemAt(Ind.row(), 8);
    data.ticket_number = ui->ticket_number;
    bool success = tts.return_tickets(data);
    if(success)
    {
        QMessageBox::information(this, tr("退票成功"),tr("您可在我的订单中查看已购买的票"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this, tr("退票失败"),tr("您可尝试重新退票"),QMessageBox::Yes);
    }

}

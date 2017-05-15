#include "userreturn.h"
#include "ui_userreturn.h"
#include "usermainwIndow.h"
#include "userbuy.h"
#include "userticket.h"
#include "userhistory.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QMessageBox>

extern sjtu::TTS tts;
extern int ID;
QModelIndex Ind_userreturn;

userreturn::userreturn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userreturn)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSortingEnabled(true);
//    ui->tableWidget->setModel(model);
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

void userreturn::on_tableWidget_clicked(const QModelIndex &Index)
{
    Ind_userreturn = Index;
}

void userreturn::on_show_order_clicked()
{
    sjtu::vector<sjtu::query_my_order_ans> vec = tts.query_my_order(sjtu::query_my_order_data(ID));
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


void userreturn::on_pushButton_5_clicked()
{
    sjtu::return_tickets_data data;
    data.ID = ID;
    data.train_name = ui->tableWidget->itemAt(Ind_userreturn.row(), 2)->text();
    data.start_date = sjtu::transfer_date(ui->tableWidget->itemAt(Ind_userreturn.row(), 3)->text());//need to be done
    data.start_station = ui->tableWidget->itemAt(Ind_userreturn.row(), 4)->text();
    data.end_station = ui->tableWidget->itemAt(Ind_userreturn.row(), 6)->text();
    data.seat_kind = ui->tableWidget->itemAt(Ind_userreturn.row(), 8)->text();
    data.ticket_number = ui->ticket_number->value();
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

void userreturn::on_pushButton_6_clicked()
{
    this->hide();
}

#include "userbuy.h"
#include "ui_userbuy.h"
#include "usermainwindow.h"
#include "userticket.h"
#include "../tts_server/header/server.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "vector.hpp"
#include <QString>
#include "chooseseat.h"
#include "../tts_server/header/query.h"
#include <QModelIndex>
#include <QAbstractItemView>
#include <QMessageBox>
#include <QTableWidget>
#include <QTableWidgetItem>

extern sjtu::TTS tts;
extern int ID;
QModelIndex Ind_userbuy;

userbuy::userbuy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userbuy)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSortingEnabled(true);
//    ui->tableWidget->setModel(model);
}

userbuy::~userbuy()
{
    delete ui;
}


void userbuy::on_pushButton_clicked()
{
    usermainwindow u_main;
    u_main.show();
}

void userbuy::on_pushButton_2_clicked()
{
    userticket u_tic;
    u_tic.show();
}

void userbuy::on_comboBox_activated(const QString &arg1){}

void userbuy::on_pushButton_6_clicked(){}

void userbuy::on_search_by_station_clicked()
{
    ui->tableWidget->clear();
    QTableWidgetItem * oone = new QTableWidgetItem("车次号");
    QTableWidgetItem * ttwo = new QTableWidgetItem("出发日期");
    QTableWidgetItem * tthr = new QTableWidgetItem("始发站");
    QTableWidgetItem * ffou = new QTableWidgetItem("出发时间");
    QTableWidgetItem * ffiv = new QTableWidgetItem("终点站");
    QTableWidgetItem * ssix = new QTableWidgetItem("到达时间");
    QTableWidgetItem * ssev = new QTableWidgetItem("座位种类");
    QTableWidgetItem * eeig = new QTableWidgetItem("车次号");
    ui->tableWidget->setHorizontalHeaderItem(2, oone);
    ui->tableWidget->setHorizontalHeaderItem(3, ttwo);
    ui->tableWidget->setHorizontalHeaderItem(4, tthr);
    ui->tableWidget->setHorizontalHeaderItem(5, ffou);
    ui->tableWidget->setHorizontalHeaderItem(6, ffiv);
    ui->tableWidget->setHorizontalHeaderItem(7, ssix);
    ui->tableWidget->setHorizontalHeaderItem(8, ssev);
    ui->tableWidget->setHorizontalHeaderItem(9, eeig);
    sjtu::vector<sjtu::query_ticket_ans> vec =
            tts.query_station_station(sjtu::query_ticket_ss_data(ui->start_station->text(),
                                                                 ui->end_station->text(),
                                                                 sjtu::transfer_date(ui->dateEdit_station->text())));//need to be done
    for(int i = 0; i < vec.size(); ++i)
    {
        QTableWidgetItem * one = new QTableWidgetItem(vec[i].train_name);
        QTableWidgetItem * two = new QTableWidgetItem(vec[i].start_date);
        QTableWidgetItem * three = new QTableWidgetItem(vec[i].start_station);
        QTableWidgetItem * four = new QTableWidgetItem(vec[i].start_time);
        QTableWidgetItem * five = new QTableWidgetItem(vec[i].end_station);
        QTableWidgetItem * six = new QTableWidgetItem(vec[i].end_time);
        QTableWidgetItem * seven = new QTableWidgetItem(vec[i].seat_kind);
        QTableWidgetItem * eight = new QTableWidgetItem(vec[i].ticket_left);
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

void userbuy::on_search_by_city_clicked()
{
    ui->tableWidget->clear();
    QTableWidgetItem * oone = new QTableWidgetItem("车次号");
    QTableWidgetItem * ttwo = new QTableWidgetItem("出发日期");
    QTableWidgetItem * tthr = new QTableWidgetItem("始发站");
    QTableWidgetItem * ffou = new QTableWidgetItem("出发时间");
    QTableWidgetItem * ffiv = new QTableWidgetItem("终点站");
    QTableWidgetItem * ssix = new QTableWidgetItem("到达时间");
    QTableWidgetItem * ssev = new QTableWidgetItem("座位种类");
    QTableWidgetItem * eeig = new QTableWidgetItem("车次号");
    ui->tableWidget->setHorizontalHeaderItem(2, oone);
    ui->tableWidget->setHorizontalHeaderItem(3, ttwo);
    ui->tableWidget->setHorizontalHeaderItem(4, tthr);
    ui->tableWidget->setHorizontalHeaderItem(5, ffou);
    ui->tableWidget->setHorizontalHeaderItem(6, ffiv);
    ui->tableWidget->setHorizontalHeaderItem(7, ssix);
    ui->tableWidget->setHorizontalHeaderItem(8, ssev);
    ui->tableWidget->setHorizontalHeaderItem(9, eeig);
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_city_city(sjtu::query_ticket_cc_data(ui->start_city->text(), ui->end_city->text(), sjtu::transfer_date(ui->dateEdit_city->text())));//need to be done
    for(int i = 0; i < vec.size(); ++i)
    {
        QTableWidgetItem * one = new QTableWidgetItem(vec[i].train_name);
        QTableWidgetItem * two = new QTableWidgetItem(vec[i].start_date);
        QTableWidgetItem * three = new QTableWidgetItem(vec[i].start_station);
        QTableWidgetItem * four = new QTableWidgetItem(vec[i].start_time);
        QTableWidgetItem * five = new QTableWidgetItem(vec[i].end_station);
        QTableWidgetItem * six = new QTableWidgetItem(vec[i].end_time);
        QTableWidgetItem * seven = new QTableWidgetItem(vec[i].seat_kind);
        QTableWidgetItem * eight = new QTableWidgetItem(vec[i].ticket_left);
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

void userbuy::on_listWidget_itemDoubleClicked(QListWidgetItem *item){}

void userbuy::on_tableWidget_clicked(const QModelIndex &index)
{
    Ind_userbuy = index;
}
void userbuy::on_pushButton_3_clicked()
{
    sjtu::buy_tickets_data data;
    data.ID = ID;
    data.train_name = ui->tableWidget->itemAt(Ind_userbuy.row(), 2)->text();
    data.start_date = ui->tableWidget->itemAt(Ind_userbuy.row(), 3)->text().toInt();//need to be done
    data.start_station = ui->tableWidget->itemAt(Ind_userbuy.row(), 4)->text();
    data.end_station = ui->tableWidget->itemAt(Ind_userbuy.row(), 6)->text();
    data.seat_kind = ui->tableWidget->itemAt(Ind_userbuy.row(), 8)->text();
    data.ticket_num = ui->ticket_number->value();
    bool success = tts.buy_tickets(data);
    if(success)
    {
        QMessageBox::information(this, tr("购买成功"),tr("您可在我的订单中查看已购买的票"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this, tr("购买失败"),tr("您可尝试重新购买"),QMessageBox::Yes);
    }
}



void userbuy::on_pushButton_4_clicked()
{
    this->hide();
}

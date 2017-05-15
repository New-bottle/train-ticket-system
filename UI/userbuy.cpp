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

extern sjtu::TTS tts;
extern int ID;
QModelIndex Ind;

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
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_station_station(sjtu::query_ticket_ss_data(ui->start_by_station->currentText(), ui->end_by_station->currentText(), ui->time_by_station->currentText()));
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
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_city_city(sjtu::query_ticket_cc_data(ui->start_by_city->currentText(), ui->end_by_city->currentText(), ui->time_by_city->currentText().toInt()));//need to be done
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
    Ind = index;
}
void userbuy::on_pushButton_3_clicked()
{
    sjtu::buy_tickets_data data;
    data.ID = ID;
    data.train_name = ui->tableWidget->itemAt(Ind.row(), 2)->text();
    data.start_date = ui->tableWidget->itemAt(Ind.row(), 3)->text().toInt();//need to be done
    data.start_station = ui->tableWidget->itemAt(Ind.row(), 4)->text();
    data.end_station = ui->tableWidget->itemAt(Ind.row(), 6)->text();
    data.seat_kind = ui->tableWidget->itemAt(Ind.row(), 8)->text();
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



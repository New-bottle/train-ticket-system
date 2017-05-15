#include "adminsearch.h"
#include "ui_adminsearch.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QAbstractItemView>

extern sjtu::TTS tts;

adminsearch::adminsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminsearch)
{
    ui->setupUi(this);
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setSortingEnabled(true);
//    ui->tableWidget->setModel(model);
}

adminsearch::~adminsearch()
{
    delete ui;
}

void adminsearch::on_search_by_station_clicked()
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
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_station_station(sjtu::query_ticket_ss_data(ui->start_station_2->text(), ui->end_station_2->text(), sjtu::transfer_date(ui->dateEdit_station->text())));
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

void adminsearch::on_search_by_city_clicked()
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
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_city_city(sjtu::query_ticket_cc_data(ui->start_city->text(), ui->end_city->text(), sjtu::transfer_date(ui->dateEdit_city->text())));
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

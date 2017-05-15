#include "search.h"
#include "ui_search.h"
#include "userlogin.h"
#include "userregister.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QAbstractItemView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QProgressBar>

extern sjtu::TTS tts;

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSortingEnabled(true);
    ui->progressBar->setMaximum(100);
    ui->progressBar->setMinimum(0);
    ui->progressBar->setValue(0);
//    ui->tableWidget_2->setModel(model);
}



search::~search()
{
    delete ui;
}

void search::on_pushButton_2_clicked()
{
    userregister u_reg;
    u_reg.exec();
}

void search::on_query_by_city_clicked()
{
    ui->tableWidget_2->clear();
    int nownum = 0;
    ui->progressBar->setValue(nownum);
    QTableWidgetItem * oone = new QTableWidgetItem("车次号");
    QTableWidgetItem * ttwo = new QTableWidgetItem("出发日期");
    QTableWidgetItem * tthr = new QTableWidgetItem("始发站");
    QTableWidgetItem * ffou = new QTableWidgetItem("出发时间");
    QTableWidgetItem * ffiv = new QTableWidgetItem("终点站");
    QTableWidgetItem * ssix = new QTableWidgetItem("到达时间");
    QTableWidgetItem * ssev = new QTableWidgetItem("座位种类");
    QTableWidgetItem * eeig = new QTableWidgetItem("车次号");
    ui->tableWidget_2->setHorizontalHeaderItem(2, oone);
    ui->tableWidget_2->setHorizontalHeaderItem(3, ttwo);
    ui->tableWidget_2->setHorizontalHeaderItem(4, tthr);
    ui->tableWidget_2->setHorizontalHeaderItem(5, ffou);
    ui->tableWidget_2->setHorizontalHeaderItem(6, ffiv);
    ui->tableWidget_2->setHorizontalHeaderItem(7, ssix);
    ui->tableWidget_2->setHorizontalHeaderItem(8, ssev);
    ui->tableWidget_2->setHorizontalHeaderItem(9, eeig);
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
        ui->tableWidget_2->setItem(i + 1, 2, one);
        ui->tableWidget_2->setItem(i + 1, 3, two);
        ui->tableWidget_2->setItem(i + 1, 4, three);
        ui->tableWidget_2->setItem(i + 1, 5, four);
        ui->tableWidget_2->setItem(i + 1, 6, five);
        ui->tableWidget_2->setItem(i + 1, 7, six);
        ui->tableWidget_2->setItem(i + 1, 8, seven);
        ui->tableWidget_2->setItem(i + 1, 9, eight);
        nownum += 100 / vec.size();
        ui->progressBar->setValue(nownum);
    }
}

void search::on_query_by_station_clicked()
{
    ui->tableWidget_2->clear();
    int nownum = 0;
    ui->progressBar->setValue(nownum);
    QTableWidgetItem * oone = new QTableWidgetItem("车次号");
    QTableWidgetItem * ttwo = new QTableWidgetItem("出发日期");
    QTableWidgetItem * tthr = new QTableWidgetItem("始发站");
    QTableWidgetItem * ffou = new QTableWidgetItem("出发时间");
    QTableWidgetItem * ffiv = new QTableWidgetItem("终点站");
    QTableWidgetItem * ssix = new QTableWidgetItem("到达时间");
    QTableWidgetItem * ssev = new QTableWidgetItem("座位种类");
    QTableWidgetItem * eeig = new QTableWidgetItem("车次号");
    ui->tableWidget_2->setHorizontalHeaderItem(2, oone);
    ui->tableWidget_2->setHorizontalHeaderItem(3, ttwo);
    ui->tableWidget_2->setHorizontalHeaderItem(4, tthr);
    ui->tableWidget_2->setHorizontalHeaderItem(5, ffou);
    ui->tableWidget_2->setHorizontalHeaderItem(6, ffiv);
    ui->tableWidget_2->setHorizontalHeaderItem(7, ssix);
    ui->tableWidget_2->setHorizontalHeaderItem(8, ssev);
    ui->tableWidget_2->setHorizontalHeaderItem(9, eeig);
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_station_station(sjtu::query_ticket_ss_data(ui->start_station->text(), ui->end_station->text(), sjtu::transfer_date(ui->dateEdit_station->text())));
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
        ui->tableWidget_2->setItem(i + 1, 2, one);
        ui->tableWidget_2->setItem(i + 1, 3, two);
        ui->tableWidget_2->setItem(i + 1, 4, three);
        ui->tableWidget_2->setItem(i + 1, 5, four);
        ui->tableWidget_2->setItem(i + 1, 6, five);
        ui->tableWidget_2->setItem(i + 1, 7, six);
        ui->tableWidget_2->setItem(i + 1, 8, seven);
        ui->tableWidget_2->setItem(i + 1, 9, eight);
        nownum += 100 / vec.size();
        ui->progressBar->setValue(nownum);
    }
}

#include "search.h"
#include "ui_search.h"
#include "userlogin.h"
#include "userregister.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"
#include <QAbstractItemView>
#include <QTableWidget>
#include <QTableWidgetItem>

extern sjtu::TTS tts;

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
    ui->setupUi(this);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSortingEnabled(true);
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
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_city_city(sjtu::query_ticket_cc_data(ui->start_city->currentText(), ui->end_city->currentText(), ui->time_city->currentText().toInt()));//need to be done
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
        QTableWidgetItem * eight = new QTableWidgetItem(vec[i].ticket_left);
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

void search::on_query_by_station_clicked()
{
    ui->tableWidget_2->clear();
    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_station_station(sjtu::query_ticket_ss_data(ui->start_station->currentText(), ui->end_station->currentText(), ui->time_station->currentText().toInt()));//need to be done
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
    }
}

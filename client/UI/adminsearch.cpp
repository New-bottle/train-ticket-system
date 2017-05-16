#include "adminsearch.h"
#include "ui_adminsearch.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QAbstractItemView>
#include <QtNetwork>
#include "query.h"
#include "vector.hpp"

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

adminsearch::adminsearch(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminsearch)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
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

void adminsearch::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
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
	/*
	sjtu::vector<sjtu::query_ticket_ans> vec =
	tts.query_station_station(
	 sjtu::query_ticket_ss_data(ui->start_station_2->text(),
	 ui->end_station_2->text(), sjtu::transfer_date(ui->dateEdit_station->text())));
	 */
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::query_ticket_ss_data(ui->start_station_2->text(),
	 ui->end_station_2->text(), sjtu::transfer_date(ui->dateEdit_station->text()));
	transmit(package);
}

void adminsearch::search_bystation_show(QString package) {
	sjtu::vector<sjtu::query_ticket_ans> vec;
	QTextStream sin(&package);
	sin >> vec;
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
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::query_ticket_cc_data(ui->start_station_2->text(),
	 ui->end_station_2->text(), sjtu::transfer_date(ui->dateEdit_station->text()));
	transmit(package);
//    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_city_city(sjtu::query_ticket_cc_data(ui->start_city->text(), ui->end_city->text(), sjtu::transfer_date(ui->dateEdit_city->text())));
}

void adminsearch::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		search_bystation_show(datagram);
		sender->abort(); receiver->abort();
	}
}

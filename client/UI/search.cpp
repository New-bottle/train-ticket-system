#include "search.h"
#include "ui_search.h"
#include "userlogin.h"
#include "userregister.h"
#include <QAbstractItemView>
#include <QTableWidget>
#include <QTableWidgetItem>
#include "query.h"
#include <QtNetwork>

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

search::search(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::search)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
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

void search::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void search::on_query_by_city_clicked()
{
    ui->tableWidget_2->clear();
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
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::query_ticket_cc_data(ui->start_station->text(),
	 ui->end_station->text(), sjtu::transfer_date(ui->dateEdit_station->text()));
	transmit(package);
//    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_city_city(sjtu::query_ticket_cc_data(ui->start_city->text(), ui->end_city->text(), sjtu::transfer_date(ui->dateEdit_city->text())));
}

void search::search_show(QString package)
{
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
//    sjtu::vector<sjtu::query_ticket_ans> vec = tts.query_station_station(sjtu::query_ticket_ss_data(ui->start_station->text(), ui->end_station->text(), sjtu::transfer_date(ui->dateEdit_station->text())));
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::query_ticket_ss_data(ui->start_station->text(),
	 ui->end_station->text(), sjtu::transfer_date(ui->dateEdit_station->text()));
	transmit(package);
}


void search::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		search_show(datagram);
		sender->abort(); receiver->abort();
	}
}

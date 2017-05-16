#include "userticket.h"
#include "ui_userticket.h"
#include "userbuy.h"
#include "userreturn.h"
#include "userhistory.h"
#include "usermainwindow.h"
#include <QString>
#include "vector.hpp"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>
#include "userreturn.h"
#include "query.h"
#include <QtNetwork>

extern int ID;
extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

userticket::userticket(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userticket)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
    ui->tableWidget_2->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setSortingEnabled(true);
//    ui->tableWidget_2->setModel(model);
}

userticket::~userticket()
{
    delete ui;
}

void userticket::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
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
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::query_my_order_data(ID);
	transmit(package);
}
void userticket::query_show(QString package) {
	QTextStream sin(&package);
	sjtu::vector<sjtu::query_my_order_ans> vec;
	sin >> vec;
//	= tts.query_my_order(sjtu::query_my_order_data(ID));
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

void userticket::on_return_ticket_button_clicked()
{
    userreturn u_ret;
	u_ret.exec();
}


void userticket::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		query_show(datagram);
		sender->abort(); receiver->abort();
	}
}

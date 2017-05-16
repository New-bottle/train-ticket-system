#include "userreturn.h"
#include "ui_userreturn.h"
#include "usermainwindow.h"
#include "userbuy.h"
#include "userticket.h"
#include "userhistory.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QModelIndex>
#include <QMessageBox>
#include "query.h"
#include <QtNetwork>

extern int ID;
QModelIndex Ind_userreturn;
extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

userreturn::userreturn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userreturn)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
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

void userreturn::transmit(QByteArray package, int type) {
	sender->abort(); receiver->abort();
	this_type = type;
	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
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
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::query_my_order_data(ID);
	transmit(package, 1);
//    sjtu::vector<sjtu::query_my_order_ans> vec = tts.query_my_order(sjtu::query_my_order_data(ID));
}
void userreturn::query_show(QString package) {
	QTextStream sin(&package);
	sjtu::vector<sjtu::query_my_order_ans> vec;
	sin >> vec;
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
	QByteArray package;
	QTextStream sout(&package);
	sout << data;
	transmit(package, 2);
}

void userreturn::return_show(QString package) {
	QTextStream sin(&package);
	int success;
	sin >> success;
//    bool success = tts.return_tickets(data);
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


void userreturn::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		if (this_type == 1) query_show(datagram);
		else return_show(datagram);
		sender->abort(); receiver->abort();
	}
}

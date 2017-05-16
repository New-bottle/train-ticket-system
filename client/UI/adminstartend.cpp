#include "adminstartend.h"
#include "ui_adminstartend.h"
#include<QMessageBox>
#include "query.h"
#include <QtNetwork>

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086
adminstartend::adminstartend(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminstartend)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
    ui->setupUi(this);
}

adminstartend::~adminstartend()
{
    delete ui;
}

void adminstartend::on_confirm_start_clicked()
{
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::start_selling_data(ui->start_train->text(), sjtu::transfer_date(ui->dateEdit->text()));
	transmit(package, 1);
}
//    bool success = tts.start_selling(sjtu::start_selling_data(ui->start_train->text(), sjtu::transfer_date(ui->dateEdit->text())));

void adminstartend::confirm_show(QByteArray package) {
	QTextStream sin(&package);
	int success;
	sin >> success;
    if(success)
    {
        QMessageBox::information(this, tr("开始售票成功"),tr("开始售票成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this, tr("开始售票失败"),tr("开始售票失败"),QMessageBox::Yes);
    }
}

void adminstartend::transmit(QByteArray package, int type) {
	sender->abort(); receiver->abort();
	this_type = type;
	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}


void adminstartend::on_confirm_end_clicked()
{
  //  bool success = tts.end_selling(sjtu::end_selling_data(ui->end_train->text(), sjtu::transfer_date(ui->dateEdit_2->text())));
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::end_selling_data(ui->end_train->text(), sjtu::transfer_date(ui->dateEdit_2->text()));
	transmit(package, 2);
}

void adminstartend::confirm_end_show(QByteArray package) {
	QTextStream sin(&package);
	int success;
	sin >> success;
    if(success)
    {
        QMessageBox::information(this, tr("终止售票成功"),tr("终止售票成功"),QMessageBox::Yes);
    }
    else
    {
        QMessageBox::warning(this, tr("终止售票失败"),tr("终止售票失败"),QMessageBox::Yes);
    }
}
void adminstartend::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		confirm_show(datagram);
		sender->abort(); receiver->abort();
		//数据接收在datagram里
		/* readDatagram 函数原型
		qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
		*/
	}
}

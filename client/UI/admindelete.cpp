#include "admindelete.h"
#include "ui_admindelete.h"
#include "adminmainwindow.h"
#include <QMessageBox>
#include <QtNetwork>

extern QHostAddress serverAddress;
#define send_port 10010
#define receieve_port 10086

admindelete::admindelete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admindelete)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

admindelete::~admindelete()
{
    delete ui;
}

void admindelete::on_pushButton_2_clicked()
{
    adminmainwindow a_main;
    a_main.exec();
}

void admindelete::transmit(QString str) {
	sender->abort(); receiver->abort();

	QByteArray package;
	package.append(str);
	sender->writeDatagram(package, serverAddress, send_port);
	receiver->bind(QHostAddress::LocalHost, receieve_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void admindelete::on_pushButton_6_clicked()
{
	QString package;
	QTextStream sout(&package);
	sout << ui->delete_train->text();
	transmit(package);
}

void admindelete::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		pushButton_6_show(datagram);
		sender->abort(); receiver->abort();
		//数据接收在datagram里
		/* readDatagram 函数原型
		qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
		*/
	}
}
void admindelete::pushButton_6_show(QString package)
{
	QTextStream sin(&package);
	int yes = 0;
	sin >> yes;
	if(yes)
	{
		QMessageBox::information(this, tr("删除成功"), tr("线路已被移除"), QMessageBox::Yes);
	}
	else
	{
		QMessageBox::warning(this, tr("删除失败"), tr("你可尝试重新删除"), QMessageBox::Yes);
	}
}

void admindelete::on_pushButton_clicked()
{
    this->hide();
}

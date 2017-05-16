#include "adminadd.h"
#include "ui_adminadd.h"
#include "adminmainwindow.h"
#include <QMessageBox>
#include <QtNetwork>
#include <QByteArray>
#include <QTextStream>
#include "../query.h"
#include "mainwindow.h"
//#include "../tts_server/header/query.h"
//#include "../tts_server/header/server.h"

//extern sjtu::TTS tts;
extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

adminadd::adminadd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminadd)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

adminadd::~adminadd()
{
    delete ui;
}

void adminadd::on_pushButton_clicked()
{
    adminmainwindow a_main;
    a_main.exec();
}

void adminadd::transmit(QString str) {
	sender->abort(); receiver->abort();

	QByteArray package;
	package.append(str);
	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void adminadd::on_pushButton_2_clicked()
{
	QString package;
	QTextStream sout(&package);
	sout << sjtu::add_line_data(ui->train_name->text(), ui->add_line_info->toPlainText());
	transmit(package);
}

//	if(tts.add_line(sjtu::add_line_data(ui->train_name->text(), ui->add_line_info->toPlainText()).toQString()))
void adminadd::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		pushButton_2_show(datagram);
		sender->abort(); receiver->abort();
		//数据接收在datagram里
		/* readDatagram 函数原型
		qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
		*/
	}
}
void adminadd::pushButton_2_show(QString package)
{
	QTextStream sin(&package);
	int yes = 0;
	sin >> yes;
	if (yes)
	{
		QMessageBox::information(this, tr("添加成功"),tr("新的线路已被载入"),QMessageBox::Yes);
	}
	else
	{
		QMessageBox::warning(this, tr("添加失败"),tr("您可尝试重新添加"),QMessageBox::Yes);
	}

}

void adminadd::on_pushButton_3_clicked()
{
    this->hide();
}

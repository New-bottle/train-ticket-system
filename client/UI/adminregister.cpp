#include "adminregister.h"
#include "ui_adminregister.h"
#include <QLabel>
#include "adminlogin.h"
#include <QMessageBox>
#include <QtNetwork>
#include "query.h"

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

Adminregister::Adminregister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Adminregister)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

Adminregister::~Adminregister()
{
    delete ui;
}

void Adminregister::transmit(QString str) {
	sender->abort(); receiver->abort();

	QByteArray package;
	package.append(str);
	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void Adminregister::on_confirm_clicked()
{
    if(ui->register_num->text() != "FBI_WARNING")
    {
        QMessageBox::warning(this, tr("邀请码错误！"),tr("邀请码错误，你不是合格司机"),QMessageBox::Yes);
    }
	QString package;
	QTextStream sout(&package);
	sout << sjtu::register_admin_data(ui->userLineEdit->text(), ui->pwdLineEdit->text());
	transmit(package);
//    int id = tts.register_admin(ui->userLineEdit->text(), ui->pwdLineEdit->text());
//    this->close();
}

void Adminregister::confirm_show(QString package) {
	int id;
	QTextStream sin(&package);
	sin >> id;
	QLabel * label = new QLabel("你的id号是" + QString::number(id));
	label->show();
	adminlogin a_log;
	a_log.exec();
}

void Adminregister::readPendingDatagrams()
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

void Adminregister::on_cancel_clicked()
{
    this->hide();
}

#include "adminlogin.h"
#include "ui_adminlogin.h"
#include "adminregister.h"
#include "adminmainwindow.h"
#include <QMessageBox>
#include "query.h"
extern int ID;

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

adminlogin::adminlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminlogin)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

adminlogin::~adminlogin()
{
    delete ui;
}

void adminlogin::transmit(QString str) {
	sender->abort(); receiver->abort();

	QByteArray package;
	package.append(str);
	sender->writeDatagram(package, serverAddress, send_port);
	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}
void adminlogin::on_register_2_clicked()
{
}

void adminlogin::on_pushButton_3_clicked()
{
    Adminregister a_reg;
    a_reg.exec();
}

void adminlogin::on_loginBtn_clicked()
{
	QString package;
	QTextStream sout(&package);
	sout << sjtu::login_admin_data(ui->userLineEdit->text().toInt(), ui->pwdLineEdit->text());
	transmit(package);
	/*
	if(tts.login_admin(sjtu::login_admin_data(ui->userLineEdit->text().toInt(), ui->pwdLineEdit->text())))
	{
		ID = ui->userLineEdit->text().toInt();
		adminmainwindow a_main;
		a_main.exec();
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr("user name or password error!"), QMessageBox::Yes);
		ui->userLineEdit->clear();
		ui->pwdLineEdit->clear();
		ui->userLineEdit->setFocus();
	}
	*/
}

void adminlogin::loginBtn_show(QString package) {
	QTextStream sin(&package);
	int yes = 0;
	sin >> yes;
	if (yes)
	{
		ID = ui->userLineEdit->text().toInt();
		adminmainwindow a_main;
		a_main.exec();
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr("user name or password error!"), QMessageBox::Yes);
		ui->userLineEdit->clear();
		ui->pwdLineEdit->clear();
		ui->userLineEdit->setFocus();
	}
}

void adminlogin::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		loginBtn_show(datagram);
		sender->abort(); receiver->abort();
		//数据接收在datagram里
		/* readDatagram 函数原型
		qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
		*/
	}
}

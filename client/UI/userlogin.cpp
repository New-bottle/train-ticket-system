#include "userlogin.h"
#include "ui_userlogin.h"
#include "userregister.h"
#include "usermainwindow.h"
#include <QMessageBox>
#include "query.h"
#include <QtNetwork>

extern int ID;
extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

userlogin::userlogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userlogin)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

userlogin::~userlogin()
{
    delete ui;
}

void userlogin::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}
void userlogin::on_pushButton_3_clicked()
{
    userregister u_reg;
    u_reg.exec();
}

void userlogin::on_loginBtn_clicked()
{
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::login_user_data(ui->userLineEdit->text().toInt(), ui->pwdLineEdit->text());
	transmit(package);
//	tts.login_user(sjtu::login_user_data(ui->userLineEdit->text().toInt(), ui->pwdLineEdit->text()))
}
void userlogin::login_show(QString str) {
	int tmp;
	QTextStream sin(&str);
	sin >> tmp;
	if(tmp)
    {
        ID = ui->userLineEdit->text().toInt();
        usermainwindow u_main;
        u_main.exec();
    }
    else
    {
        QMessageBox::warning(this, tr("Warning"), tr("user name or password error!"), QMessageBox::Yes);
        ui->userLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->userLineEdit->setFocus();
    }
}

void userlogin::on_exitBtn_clicked()
{
    this->hide();
}


void userlogin::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		login_show(datagram);
		sender->abort(); receiver->abort();
	}
}

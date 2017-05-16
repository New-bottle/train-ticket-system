#include "userregister.h"
#include "ui_userregister.h"
#include "userlogin.h"
#include <QLabel>
#include <QMessageBox>
#include "query.h"
#include <QtNetwork>

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

userregister::userregister(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userregister)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

userregister::~userregister()
{
    delete ui;
}

void userregister::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void userregister::on_confirm_clicked()
{
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::register_user_data(ui->userLineEdit->text(), ui->pwdLineEdit->text());
	transmit(package);
//    int id = tts.register_user(ui->userLineEdit->text(), ui->pwdLineEdit->text());
//    QMessageBox::information(this, tr("id号"),tr("你的id号是" + QString::number(id)),QMessageBox::Yes);

}
void userregister::confirm_show(QString package) {
	QTextStream sin(&package);
	int id;
	sin >> id;
    QLabel *label = new QLabel("你的id号是" + QString::number(id));
    label->show();
    userlogin u_log;
    u_log.exec();
    this->hide();
}

void userregister::on_cancel_clicked()
{
    this->hide();
}


void userregister::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		sender->abort(); receiver->abort();
		confirm_show(datagram);
	}
}

#include "userchangepwd.h"
#include "ui_userchangepwd.h"
#include "usermainwindow.h"
#include <QMessageBox>
#include "query.h"

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086
extern int ID;

userchangepwd::userchangepwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userchangepwd)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
    ui->setupUi(this);
}

userchangepwd::~userchangepwd()
{
    delete ui;
}
void userchangepwd::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}
void userchangepwd::on_pushButton_clicked()
{
    usermainwindow u_main;
    u_main.exec();
}

void userchangepwd::on_pushButton_2_clicked()
{
    if(ui->new_pwd->text().isEmpty())
    {
        QMessageBox::warning(this, tr("Warning"), tr("new password is empty!"), QMessageBox::Yes);
    }
    else
    {
//       change_password(sjtu::change_password_data(ID, ui->new_pwd->text()));
		QByteArray package;
		QTextStream sout(&package);
		sout << sjtu::change_password_data(ID, ui->new_pwd->text()) << flush;
		transmit(package);
    }
}

void userchangepwd::pushButton_2_show(QByteArray package) {
	QTextStream sin(&package);
	int success;
	sin >> success;
	if(success)
	{
		QMessageBox::information(this, tr("Success"), tr("new password has been accepted"), QMessageBox::Yes);
	}
	else
	{
		QMessageBox::warning(this, tr("Warning"), tr("fail to change password"), QMessageBox::Yes);
	}
	this->hide();
}
void userchangepwd::readPendingDatagrams()
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

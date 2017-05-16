#include "searchbyline.h"
#include "ui_searchbyline.h"
#include "usermainwindow.h"
#include <QTableWidget>
#include <QTableWidgetItem>
#include "query.h"

extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

searchbyline::searchbyline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchbyline)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
    ui->setupUi(this);
}

searchbyline::~searchbyline()
{
    delete ui;
}
void searchbyline::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void searchbyline::on_pushButton_2_clicked()
{
    usermainwindow u_main;
    u_main.exec();
}

void searchbyline::on_pushButton_clicked()
{
    ui->tableWidget->clear();
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::check_line_data(ui->train_name->text()) << flush;
	transmit(package);
}
//    sjtu::check_line_ans ans = tts.check_line(ui->train_name->text());

void searchbyline::pushButton_2_show(QByteArray package) {
	QTextStream sin(&package);
	sjtu::check_line_ans ans;
	sin >> ans;
    /*QTableWidgetItem one = new QTableWidgetItem("站名");
    QTableWidgetItem two = new QTableWidgetItem("日期");
    QTableWidgetItem three = new QTableWidgetItem("到达时间");
    QTableWidgetItem one = new QTableWidgetItem("停车时间");
    QTableWidgetItem one = new QTableWidgetItem("站名");
    QTableWidgetItem one = new QTableWidgetItem("站名");
    QTableWidgetItem one = new QTableWidgetItem("站名");
    ui->tableWidget->setHorizontalHeaderItem();*/
}

void searchbyline::readPendingDatagrams()
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

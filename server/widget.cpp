#include "widget.h"
#include "ui_widget.h"
#include "tts_server/header/server.h"
#include "tts_server/header/query.h"
#include <QtNetwork>

#define sender_port 10086
#define receive_port 10010
Widget::Widget(QWidget *parent) :
	QWidget(parent),
	ui(new Ui::Widget)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
	ui->setupUi(this);
}

extern sjtu::TTS tts;

void Widget::solve(QByteArray datagram) {
	QTextStream sin(&datagram);
	QString opt;
	sin >> opt;
	QByteArray package;
	QTextStream sout(&package);

	using namespace sjtu;
	using sjtu::TTS;
	QTextStream cout(stdout);
	cout << datagram << endl;
	cout << " opt = " << opt << endl;
	if (opt == "login_user") {
		login_user_data tmp;
		sin >> tmp;
		sout << tts.login_user(tmp) << flush;
	}
	if (opt == "login_admin") {
		login_admin_data tmp;
		sin >> tmp;
		sout << tts.login_admin(tmp) << flush;
	}
	if (opt == "query_city_city") {
		query_ticket_cc_data tmp;
		sin >> tmp;
		sout << tts.query_city_city(tmp) << flush;
	}
	if (opt == "query_station_station") {
		query_ticket_ss_data tmp;
		sin >> tmp;
		sout << tts.query_station_station(tmp) << flush;
	}
	if (opt == "query_my_order") {
		query_my_order_data tmp;
		sin >> tmp;
		sout << tts.query_my_order(tmp) << flush;
	}
	if (opt == "return_tickets") {
		return_tickets_data tmp;
		sin >> tmp;
		sout << tts.return_tickets(tmp) << flush;
	}
	if (opt == "buy_tickets") {
		buy_tickets_data tmp;
		sin >> tmp;
		sout << tts.buy_tickets(tmp) << flush;
	}
	if (opt == "register_user") {
		register_user_data tmp;
		sin >> tmp;
		sout << tts.register_user(tmp) << flush;
	}
	if (opt == "register_admin") {
		register_admin_data tmp;
		sin >> tmp;
		sout << tts.register_admin(tmp) << flush;
	}
	if (opt == "add_line") {
		add_line_data tmp;
		sin >> tmp;
		sout << tts.add_line(tmp) << flush;
	}
	if (opt == "add_train") {
		add_train_data tmp;
		sin >> tmp;
		sout << tts.add_train(tmp) << flush;
	}
	if (opt == "change_password") {
		change_password_data tmp;
		sin >> tmp;
		sout << tts.change_password(tmp) << flush;
	}
	if (opt == "start_selling") {
		start_selling_data tmp;
		sin >> tmp;
		sout << tts.start_selling(tmp) << flush;
	}
	if (opt == "end_selling") {
		end_selling_data tmp;
		sin >> tmp;
		sout << tts.end_selling(tmp) << flush;
	}
	if (opt == "check_user") {
		check_user_data tmp;
		sin >> tmp;
		sout << tts.check_user(tmp) << flush;
	}
	if (opt == "check_line") {
		check_line_data tmp;
		sin >> tmp;
		sout << tts.check_line(tmp) << flush;
	}
	cout << "package = " << package << endl;
	sender->writeDatagram(package, client_address, send_port);
}

void Widget::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size(), &client_address);
		solve(datagram);
//		sender->abort(); receiver->abort();
		//数据接收在datagram里
		/* readDatagram 函数原型
		qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
		*/
	}
}
Widget::~Widget()
{
	delete ui;
}

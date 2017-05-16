#include "adminaddtrain.h"
#include "ui_adminaddtrain.h"
#include <QtNetwork>
#include <QMessageBox>
#include "query.h"


//extern sjtu::TTS tts;
extern QHostAddress serverAddress;
#define send_port 10010
#define receive_port 10086

adminaddtrain::adminaddtrain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminaddtrain)
{
	sender = new QUdpSocket(this);
	receiver = new QUdpSocket(this);
	ui->setupUi(this);
}

adminaddtrain::~adminaddtrain()
{
    delete ui;
}
void adminaddtrain::transmit(QByteArray package) {
	sender->abort(); receiver->abort();

	sender->writeDatagram(package, serverAddress, send_port);

	receiver->bind(QHostAddress::LocalHost, receive_port);
	connect(receiver, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
}

void adminaddtrain::on_pushButton_2_clicked()
{
    this->hide();
}

void adminaddtrain::on_pushButton_clicked()
{
	QByteArray package;
	QTextStream sout(&package);
	sout << sjtu::add_train_data(ui->train_name->text(),
								  ui->from->text().toInt(),
								  ui->to->text().toInt()) << flush;
/*    bool success = tts.add_train(sjtu::add_train_data(ui->train_name->text(),
                                                      ui->from->text().toInt(),
                                                      ui->to->text().toInt()));
													  */
	transmit(package);
}
void adminaddtrain::push_show(QByteArray package) {
	QTextStream sin(&package);
	int success;
	sin >> success;
    if(success)
    {
        QMessageBox::information(this, tr("添加成功"),tr("新的车次已被载入"),QMessageBox::Yes);

    }
    else
    {
		QMessageBox::warning(this, tr("添加失败"),tr("您可尝试重新添加"),QMessageBox::Yes);
    }

}
void adminaddtrain::readPendingDatagrams()
{
	while (receiver->hasPendingDatagrams()) {
		QByteArray datagram;
		datagram.resize(receiver->pendingDatagramSize());
		receiver->readDatagram(datagram.data(), datagram.size());
		push_show(datagram);
		sender->abort(); receiver->abort();
		//数据接收在datagram里
		/* readDatagram 函数原型
		qint64 readDatagram(char *data,qint64 maxSize,QHostAddress *address=0,quint16 *port=0)
		*/
	}
}

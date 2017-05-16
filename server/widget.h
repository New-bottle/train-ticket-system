#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QtNetwork>
#include "tts_server/header/query.h"

#define send_port 10086
#define receive_port 10010
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
	Q_OBJECT
	QUdpSocket *sender, *receiver;
	QHostAddress client_address;

public:
	explicit Widget(QWidget *parent = 0);
	~Widget();

private:
	Ui::Widget *ui;
	void solve(QByteArray);
private slots:
	void readPendingDatagrams();
};

#endif // WIDGET_H

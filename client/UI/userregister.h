#ifndef USERREGISTER_H
#define USERREGISTER_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class userregister;
}

class userregister : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	const int this_type = 9;
	void transmit(QByteArray package);
	void confirm_show(QString package);

public:
    explicit userregister(QWidget *parent = 0);
    ~userregister();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

	void readPendingDatagrams();
private:
    Ui::userregister *ui;
};

#endif // USERREGISTER_H

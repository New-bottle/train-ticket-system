#ifndef ADMINSTARTEND_H
#define ADMINSTARTEND_H

#include <QDialog>
#include <QtNetwork>
namespace Ui {
class adminstartend;
}

class adminstartend : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;

public:
    explicit adminstartend(QWidget *parent = 0);
    ~adminstartend();

private slots:
    void on_confirm_start_clicked();

    void on_confirm_end_clicked();

	void readPendingDatagrams();
private:
	int this_type;
	void confirm_show(QByteArray);
	void confirm_end_show(QByteArray);
	void transmit(QByteArray, int type);
    Ui::adminstartend *ui;
};

#endif // ADMINSTARTEND_H

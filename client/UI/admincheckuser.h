#ifndef ADMINCHECKUSER_H
#define ADMINCHECKUSER_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class admincheckuser;
}

class admincheckuser : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;

public:
    explicit admincheckuser(QWidget *parent = 0);
    ~admincheckuser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

	void readPendingDatagrams();
private:
	void transmit(QByteArray);
	void pushButton_2_show(QByteArray);
    Ui::admincheckuser *ui;
};

#endif // ADMINCHECKUSER_H

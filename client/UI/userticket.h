#ifndef USERTICKET_H
#define USERTICKET_H

#include <QDialog>
#include <QTableWidgetItem>
#include <QtNetwork>

namespace Ui {
class userticket;
}

class userticket : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QByteArray package);
	void query_show(QString package);

public:
    explicit userticket(QWidget *parent = 0);
    ~userticket();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_tableWidget_2_itemClicked(QTableWidgetItem *item);

    void on_return_ticket_button_clicked();

	void readPendingDatagrams();
private:
    Ui::userticket *ui;
};

#endif // USERTICKET_H

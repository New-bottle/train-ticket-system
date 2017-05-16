#ifndef USERRETURN_H
#define USERRETURN_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class userreturn;
}

class userreturn : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QByteArray package, int type);
	int this_type;
	void query_show(QString package);
	void return_show(QString package);

public:
    explicit userreturn(QWidget *parent = 0);
    ~userreturn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_show_order_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

	void readPendingDatagrams();
private:
    Ui::userreturn *ui;
};

#endif // USERRETURN_H

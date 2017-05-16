#ifndef USERBUY_H
#define USERBUY_H

#include <QDialog>
#include <QListWidgetItem>
#include <QtNetwork>

namespace Ui {
class userbuy;
}

class userbuy : public QDialog
{
    Q_OBJECT
public:
	QUdpSocket *sender, *receiver;
	int this_type;
	void transmit(QByteArray package, int type);
	void search_show(QString package);
	void buy_show(QString package);

public:
    explicit userbuy(QWidget *parent = 0);
    ~userbuy();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pushButton_6_clicked();

    void on_search_by_station_clicked();

    void on_search_by_city_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_4_clicked();

	void readPendingDatagrams();
private:
    Ui::userbuy *ui;
};

#endif // USERBUY_H

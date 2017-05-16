#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	const int this_type = 6;
	void transmit(QByteArray package);
	void search_show(QString package);

public:
    explicit search(QWidget *parent = 0);
    ~search();

private slots:
    void on_pushButton_2_clicked();

    void on_query_by_city_clicked();

    void on_query_by_station_clicked();

	void readPendingDatagrams();
private:
    Ui::search *ui;
};

#endif // SEARCH_H

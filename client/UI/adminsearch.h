#ifndef ADMINSEARCH_H
#define ADMINSEARCH_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class adminsearch;
}

class adminsearch : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QByteArray package);
	void search_bystation_show(QString);

public:
    explicit adminsearch(QWidget *parent = 0);
    ~adminsearch();

private slots:
    void on_search_by_station_clicked();

    void on_search_by_city_clicked();

	void readPendingDatagrams();
private:
    Ui::adminsearch *ui;
};

#endif // ADMINSEARCH_H

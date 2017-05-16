#ifndef ADMINADD_H
#define ADMINADD_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class adminadd;
}

class adminadd : public QDialog
{
    Q_OBJECT
public:
	QUdpSocket *sender, *receiver;
	void transmit(QString package);
	void pushButton_2_show(QString package);

public:
    explicit adminadd(QWidget *parent = 0);
    ~adminadd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
	void readPendingDatagrams();
private:
    Ui::adminadd *ui;
};

#endif // ADMINADD_H

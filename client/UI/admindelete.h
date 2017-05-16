#ifndef ADMINDELETE_H
#define ADMINDELETE_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class admindelete;
}

class admindelete : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QString package);
	void pushButton_6_show(QString package);

public:
    explicit admindelete(QWidget *parent = 0);
    ~admindelete();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_clicked();

	void readPendingDatagrams();

private:
    Ui::admindelete *ui;
};

#endif // ADMINDELETE_H

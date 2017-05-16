#ifndef ADMINADDTRAIN_H
#define ADMINADDTRAIN_H

#include <QDialog>
#include <QtNetwork>
namespace Ui {
class adminaddtrain;
}

class adminaddtrain : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QByteArray package);
	void search_bystation_show(QString);
	void push_show(QByteArray);
public:
    explicit adminaddtrain(QWidget *parent = 0);
    ~adminaddtrain();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

	void readPendingDatagrams();
private:
    Ui::adminaddtrain *ui;
};

#endif // ADMINADDTRAIN_H

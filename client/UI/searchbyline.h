#ifndef SEARCHBYLINE_H
#define SEARCHBYLINE_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class searchbyline;
}

class searchbyline : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;

public:
    explicit searchbyline(QWidget *parent = 0);
    ~searchbyline();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

	void readPendingDatagrams();

private:
	void pushButton_2_show(QByteArray);
	void transmit(QByteArray);
    Ui::searchbyline *ui;
};

#endif // SEARCHBYLINE_H

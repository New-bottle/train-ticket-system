#ifndef USERCHANGEPWD_H
#define USERCHANGEPWD_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class userchangepwd;
}

class userchangepwd : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;

public:
    explicit userchangepwd(QWidget *parent = 0);
    ~userchangepwd();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

	void readPendingDatagrams();
private:
	void pushButton_2_show(QByteArray);
	void transmit(QByteArray);
    Ui::userchangepwd *ui;
};

#endif // USERCHANGEPWD_H

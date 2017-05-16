#ifndef USERLOGIN_H
#define USERLOGIN_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class userlogin;
}

class userlogin : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QByteArray package);
	void login_show(QString str);

public:
    explicit userlogin(QWidget *parent = 0);
    ~userlogin();

private slots:
    void on_pushButton_3_clicked();

    void on_loginBtn_clicked();

    void on_exitBtn_clicked();

	void readPendingDatagrams();
private:
    Ui::userlogin *ui;
};

#endif // USERLOGIN_H

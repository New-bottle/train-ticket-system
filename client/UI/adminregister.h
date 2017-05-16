#ifndef ADMINREGISTER_H
#define ADMINREGISTER_H

#include <QDialog>
#include <QtNetwork>

namespace Ui {
class Adminregister;
}

class Adminregister : public QDialog
{
    Q_OBJECT
	QUdpSocket *sender, *receiver;
	void transmit(QString package);
	void confirm_show(QString);

public:
    explicit Adminregister(QWidget *parent = 0);
    ~Adminregister();

private slots:
    void on_confirm_clicked();

    void on_cancel_clicked();

	void readPendingDatagrams();

private:
    Ui::Adminregister *ui;
};

#endif // ADMINREGISTER_H

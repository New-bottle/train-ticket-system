#ifndef USERRETURN_H
#define USERRETURN_H

#include <QDialog>

namespace Ui {
class userreturn;
}

class userreturn : public QDialog
{
    Q_OBJECT

public:
    explicit userreturn(QWidget *parent = 0);
    ~userreturn();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

    void on_show_order_clicked();

    void on_tableWidget_clicked(const QModelIndex &index);

    void on_pushButton_5_clicked();

private:
    Ui::userreturn *ui;
};

#endif // USERRETURN_H

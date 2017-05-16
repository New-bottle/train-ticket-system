#ifndef ADMINADDTRAIN_H
#define ADMINADDTRAIN_H

#include <QDialog>

namespace Ui {
class adminaddtrain;
}

class adminaddtrain : public QDialog
{
    Q_OBJECT

public:
    explicit adminaddtrain(QWidget *parent = 0);
    ~adminaddtrain();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::adminaddtrain *ui;
};

#endif // ADMINADDTRAIN_H

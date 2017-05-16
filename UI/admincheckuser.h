#ifndef ADMINCHECKUSER_H
#define ADMINCHECKUSER_H

#include <QDialog>

namespace Ui {
class admincheckuser;
}

class admincheckuser : public QDialog
{
    Q_OBJECT

public:
    explicit admincheckuser(QWidget *parent = 0);
    ~admincheckuser();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::admincheckuser *ui;
};

#endif // ADMINCHECKUSER_H

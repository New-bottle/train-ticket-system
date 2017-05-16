#ifndef ADMINSTARTEND_H
#define ADMINSTARTEND_H

#include <QDialog>

namespace Ui {
class adminstartend;
}

class adminstartend : public QDialog
{
    Q_OBJECT

public:
    explicit adminstartend(QWidget *parent = 0);
    ~adminstartend();

private slots:
    void on_confirm_start_clicked();

    void on_confirm_end_clicked();

private:
    Ui::adminstartend *ui;
};

#endif // ADMINSTARTEND_H

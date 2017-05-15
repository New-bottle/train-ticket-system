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

private:
    Ui::adminstartend *ui;
};

#endif // ADMINSTARTEND_H

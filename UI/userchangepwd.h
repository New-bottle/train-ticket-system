#ifndef USERCHANGEPWD_H
#define USERCHANGEPWD_H

#include <QDialog>

namespace Ui {
class userchangepwd;
}

class userchangepwd : public QDialog
{
    Q_OBJECT

public:
    explicit userchangepwd(QWidget *parent = 0);
    ~userchangepwd();

private:
    Ui::userchangepwd *ui;
};

#endif // USERCHANGEPWD_H

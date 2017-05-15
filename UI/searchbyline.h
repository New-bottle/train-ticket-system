#ifndef SEARCHBYLINE_H
#define SEARCHBYLINE_H

#include <QDialog>

namespace Ui {
class searchbyline;
}

class searchbyline : public QDialog
{
    Q_OBJECT

public:
    explicit searchbyline(QWidget *parent = 0);
    ~searchbyline();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::searchbyline *ui;
};

#endif // SEARCHBYLINE_H

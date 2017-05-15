#ifndef ADMINSEARCH_H
#define ADMINSEARCH_H

#include <QDialog>

namespace Ui {
class adminsearch;
}

class adminsearch : public QDialog
{
    Q_OBJECT

public:
    explicit adminsearch(QWidget *parent = 0);
    ~adminsearch();

private slots:
    void on_search_by_station_clicked();

    void on_search_by_city_clicked();

private:
    Ui::adminsearch *ui;
};

#endif // ADMINSEARCH_H

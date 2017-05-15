#ifndef SEARCH_H
#define SEARCH_H

#include <QDialog>

namespace Ui {
class search;
}

class search : public QDialog
{
    Q_OBJECT

public:
    explicit search(QWidget *parent = 0);
    ~search();

private slots:
    void on_pushButton_2_clicked();

    void on_query_by_city_clicked();

    void on_query_by_station_clicked();

private:
    Ui::search *ui;
};

#endif // SEARCH_H

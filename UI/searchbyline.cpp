#include "searchbyline.h"
#include "ui_searchbyline.h"

searchbyline::searchbyline(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchbyline)
{
    ui->setupUi(this);
}

searchbyline::~searchbyline()
{
    delete ui;
}

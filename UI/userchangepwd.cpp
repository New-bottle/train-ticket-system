#include "userchangepwd.h"
#include "ui_userchangepwd.h"

userchangepwd::userchangepwd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::userchangepwd)
{
    ui->setupUi(this);
}

userchangepwd::~userchangepwd()
{
    delete ui;
}

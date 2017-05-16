#include "adminaddtrain.h"
#include "ui_adminaddtrain.h"
#include "../tts_server/header/query.h"
#include "../tts_server/header/server.h"

extern sjtu::TTS tts;

adminaddtrain::adminaddtrain(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminaddtrain)
{
    ui->setupUi(this);
}

adminaddtrain::~adminaddtrain()
{
    delete ui;
}

void adminaddtrain::on_pushButton_2_clicked()
{
    this->hide();
}

void adminaddtrain::on_pushButton_clicked()
{
    bool success = tts.add_train(sjtu::add_train_data(ui->train_name->text(),
                                                      ui->from->text().toInt(),
                                                      ui->to->text().toInt()));
    if(success)
    {
        QMessageBox::information(this, tr("添加成功"),tr("新的车次已被载入"),QMessageBox::Yes);
    }
    else
    {
        MessageBox::warning(this, tr("添加失败"),tr("您可尝试重新添加"),QMessageBox::Yes);
    }

}

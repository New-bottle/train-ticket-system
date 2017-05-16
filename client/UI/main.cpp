#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QtNetwork>

int ID;
QHostAddress serverAddress("127.0.0.1");

int main(int argc, char *argv[])
{

//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();



    return a.exec();
}

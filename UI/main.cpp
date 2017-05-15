#include "mainwindow.h"
#include <QApplication>
#include "../tts_server/header/account_manager.h"
#include "../tts_server/header/train_manager.h"
#include "../tts_server/header/forward_declaration.h"
#include "../tts_server/header/server.h"
#include "../memory.hpp"
#include <QTextCodec>

sjtu::TTS tts;
int ID;

int main(int argc, char *argv[])
{

//    QTextCodec::setCodecForLocale(QTextCodec::codecForName("gbk"));
//    QTextCodec::setCodecForTr(QTextCodec::codecForName("gbk"));
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    sjtu::memory_pool<sjtu::Train>::term = 0;
    sjtu::memory_pool<sjtu::Line>::term = 0;
    sjtu::memory_pool<sjtu::Station>::term = 0;
    sjtu::memory_pool<sjtu::City>::term = 0;
    sjtu::memory_pool<sjtu::User>::term = 0;
    sjtu::memory_pool<sjtu::Account>::term = 0;
    sjtu::memory_pool<sjtu::Admin>::term = 0;
    sjtu::memory_pool<sjtu::Ticket>::term = 0;
    using namespace sjtu;
    memory_pool<Train>::end_counting();
    memory_pool<Line>::end_counting();
    memory_pool<Station>::end_counting();
    memory_pool<City>::end_counting();
    memory_pool<User>::end_counting();
    memory_pool<Account>::end_counting();
    memory_pool<Admin>::end_counting();
    memory_pool<Ticket>::end_counting();



    return a.exec();
}

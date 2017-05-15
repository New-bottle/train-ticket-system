#include "mainwindow.h"
#include <QApplication>
#include "../tts_server/header/account_manager.h"
#include "../tts_server/header/train_manager.h"
#include "../tts_server/header/forward_declaration.h"
#include "../tts_server/header/server.h"
#include "../memory.hpp"

sjtu::TTS tts;
int ID;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    sjtu::memory_pool<sjtu::Train>::term = 0;
    sjtu::memory_pool<sjtu::Line>::term = 0;
    sjtu::memory_pool<sjtu::Station>::term = 0;
    sjtu::memory_pool<sjtu::City>::term = 0;
    sjtu::memory_pool<sjtu::User>::term = 0;
    sjtu::memory_pool<sjtu::Account>::term = 0;
    sjtu::memory_pool<sjtu::Ticket>::term = 0;

    return a.exec();
}

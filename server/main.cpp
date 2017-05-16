#include "widget.h"
#include <QApplication>
#include "tts_server/header/server.h"

sjtu::TTS tts;
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Widget w;
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

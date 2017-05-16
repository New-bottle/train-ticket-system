//
// Created by Aaron Ren on 11/05/2017.
//

#include "../header/train_manager.h"
#include <QString>

int sjtu::Date::days_per_month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

QString sjtu::Train::get_name() {
	return line->name;
}

int sjtu::Train::station_pos_in_line(const QString &station_name) {
	return line->find_pos(station_name);
}

double sjtu::Train::calulate_price(const QString &dep, const QString &arr, const QString & seat_type) {
	int l = line->find_pos(dep), r = line->find_pos(arr),
		k = line->seat_type(seat_type);
	return line->price[k][r] - line->price[k][l];
}

int sjtu::Train::min_avail(const QString &dep, const QString &arr, const QString &seat_type) {
	int l = line->find_pos(dep), r = line->find_pos(arr),
		k = line->seat_type(seat_type), ans = 1e9;
    for (int i = l; i < r; ++i) {
		ans = std::min(ans, station_available_tickets[k][i]);
        if (line->price[k][i] == -1)
            return -1;
    }
	return ans;
}

QString sjtu::Train::get_station_name(const QString &city_name) {
	int sz = line->stations.size();
	for (int i = 0; i < sz; ++i)
		if (line->stations[i]->location->name == city_name)
			return line->stations[i]->name;
	return "No_such_station_in_this_line";
}

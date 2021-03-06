//
// Created by Aaron Ren on 11/05/2017.
//

#ifndef TTS_TRAIN_MANAGER_H
#define TTS_TRAIN_MANAGER_H

#include "forward_declaration.h"

#include "../../map.hpp"
#include "../../vector.hpp"
#include "../../deque.hpp"
#include "../../memory.hpp"

#include <string>

/// Stations, etc.
namespace sjtu {

struct Date {
    int year, month, day;
    int hour, min, sec;


    Date(int y = 0, int m = 0, int d = 0, int h = 0, int min = 0, int sec = 0) :
            year(y), month(m), day(d), hour(h), min(min), sec(sec) {}

    friend bool operator<(const Date &lhs, const Date &rhs) {
        if (lhs.year != rhs.year) return lhs.year < rhs.year;
        else if (lhs.month != rhs.month) return lhs.month < rhs.month;
        else if (lhs.day != rhs.day) return lhs.day < rhs.day;
        else if (lhs.hour != rhs.hour) return lhs.hour < rhs.hour;
        else if (lhs.min != rhs.min) return lhs.min < rhs.min;
        else return lhs.sec < rhs.sec;
    }

    bool same_day(const Date &rhs) const {
        return year == rhs.year && month == rhs.month && day == rhs.day;
    }

    friend bool same_day(const Date &lhs, const Date &rhs) {
        return lhs.day == rhs.day && lhs.month == rhs.month && lhs.year == rhs.year;
    }

    bool operator==(const Date &rhs) {
        return year == rhs.year && month == rhs.month && day == rhs.day
               && hour == rhs.hour && min == rhs.min && sec == rhs.sec;
    }

    class cmp_date {
    public:
        bool operator()(const Date &a, const Date &b) const {
            return a.same_day(b);
        }
    };
	friend QDataStream& operator >> (QDataStream &in, Date& rhs) {
		in >> rhs.year >> rhs.month >> rhs.day >> rhs.hour >> rhs.min >> rhs.sec;
		return in;
	}
	friend QDataStream& operator << (QDataStream &out, const Date& rhs) {
		out << rhs.year << rhs.month << rhs.day << rhs.hour << rhs.min << rhs.sec;
		return out;
	}
/*
	void load(QDataStream& in)
	{
		in >> year >> month >> day >> hour >> min >> sec;
	}
	void save(QDataStream& out)
	{
		out << year << month << day << hour << min << sec;
	}
	*/
};

struct Station {
    static const int Type = 0;

	QString name;
    // 车站所处城市
    city_ptr location;
    // 经过这个车站的线路
    vector<line_ptr> lines;

    Station(){}
	friend QDataStream& operator >> (QDataStream &in, Station &rhs) {
		in >> rhs.name >> rhs.location >> rhs.lines;
		return in;
	}
	friend QDataStream& operator << (QDataStream &out, const Station &rhs) {
		out << rhs.name << rhs.location << rhs.lines;
		return out;
	}
};

struct City {
    static const int Type = 1;

	QString name;
    // 城市中的车站
    vector<station_ptr> stations;
	friend QDataStream& operator >> (QDataStream& in, City &rhs) {
		in >> rhs.name >> rhs.stations;
		return in;
	}
	friend QDataStream& operator << (QDataStream& out, const City &rhs) {
		out << rhs.name << rhs.stations;
		return out;
	}
	/*
	void load(QDataStream& in)
	{
		in >> name;
		stations.load(in);
	}
	void save(QDataStream& out)
	{
		out << name;
		stations.save(out);
	}
	*/
};

struct Line {
    static const int Type = 2;

    QString name;                     // K1234, G27 etc
    vector<QString> seat_kind_names; // 座位种类名
    vector<station_ptr> stations;  // 经过的车站，0为起点站
    vector<Date> arr_time;               // 到站时间
    vector<Date> dep_time;               // 离站时间
    vector<int> miles;                   // 距离始发站的里程
    vector<vector<double>> price;            // 从第i到第i+1站的第j种票票价

    // 给定日期的train
    map<Date, train_ptr, Date::cmp_date> trains;

    bool check_date(const Date & date) const {
        return trains.find(date) != trains.cend();
    }
	friend QDataStream& operator >> (QDataStream &in, Line& rhs) {
		in >> rhs.name >> rhs.seat_kind_names >> rhs.stations >> rhs.arr_time
		   >> rhs.dep_time >> rhs.miles >> rhs.price;
		return in;
	}
	friend QDataStream& operator << (QDataStream &out, const Line &rhs) {
		out << rhs.name << rhs.seat_kind_names << rhs.stations << rhs.arr_time
			<< rhs.dep_time << rhs.miles << rhs.price;
		return out;
	}
};

/**Same line share one line object
 * Only Date is different
 */
struct Train {
    static const int Type = 3;

    line_ptr line;
    Date date;
    bool selling = 0;
    vector<vector<int>> station_available_tickets;
    /* saves the number of remaining tickets for each station
     * e.g. station 0--1--2--3--4 with capacity 200 seats, then
     * station_available_ticket[] = {200, 200, 200, 200} //Only four interval
     * if a customer bought a ticket from 1 to 3, then
     * station_available_ticket[] = {200, 199, 199, 200}
     */
	friend QDataStream& operator >> (QDataStream &in, Train& rhs) {
		in >> rhs.line >> rhs.date >> rhs.selling >> rhs.station_available_tickets;
		return in;
	}
	friend QDataStream& operator << (QDataStream &out, const Train& rhs) {
		out << rhs.line << rhs.date << rhs.selling << rhs.station_available_tickets;
		return out;
	}
};

struct Ticket {
    static const int Type = 4;

    train_ptr train;    // 所属的train
    int from, to;              // 起点站终点站在line中的位置
    int kind;                  // 这张票的种类
    double price;                 // 票价 = Sigma price[i][kind]
    int num;                   // user拥有的张数

    bool equal_ex_num(const Ticket & rhs) {
        return train == rhs.train && from == rhs.from && to == rhs.to
               && kind == rhs.kind;
    }
	friend QDataStream& operator >> (QDataStream &in, Ticket &rhs) {
		in >> rhs.train >> rhs.from >> rhs.to >> rhs.kind >> rhs.price >> rhs.num;
		return in;
	}
	friend QDataStream& operator << (QDataStream &out, const Ticket &rhs) {
		out << rhs.train << rhs.from << rhs.to << rhs.kind << rhs.price << rhs.num;
		return out;
	}
};
}


#endif //TTS_TRAIN_MANAGER_H

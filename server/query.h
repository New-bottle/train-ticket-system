#ifndef QUERY_H
#define QUERY_H

#include <QString>
#include <QByteArray>
#include <string>
#include <QTextStream>
#include "vector.hpp"
namespace sjtu {

// add_line completed
typedef QTextStream QTS;
struct login_user_data {
    int ID;
    QString password;
    login_user_data(int _ID, QString _p)
        : ID(_ID), password(_p){}
	friend QTS& operator << (QTS &out, const login_user_data & rhs) {
		out << rhs.ID << endl << rhs.password << endl;
		return out;
	}
	friend QTS& operator >> (QTS& in, login_user_data & rhs) {
		in >> rhs.ID >> rhs.password;
		return in;
	}
};
typedef bool login_user_ans;

struct login_admin_data {
    int ID;
    QString password;

    login_admin_data(int _ID, QString _p)
        : ID(_ID), password(_p) {}
	friend QTS& operator << (QTS &out, const login_admin_data & rhs) {
		out << rhs.ID << endl << rhs.password << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, login_admin_data & rhs) {
		in >> rhs.ID >> rhs.password;
		return in;
	}
};
typedef bool login_admin_ans;

struct query_ticket_cc_data {
    QString dep_city;
    QString arr_city;
    int date;
    query_ticket_cc_data(QString a, QString b, int c) :
        dep_city(a), arr_city(b), date(c){}
	friend QTS& operator << (QTS &out, const query_ticket_cc_data & rhs) {
		out << rhs.dep_city << endl << rhs.arr_city << endl << rhs.date << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, query_ticket_cc_data & rhs) {
		in >> rhs.dep_city >> rhs.arr_city >> rhs.date;
		return in;
	}
};

struct query_ticket_ss_data {
    QString dep_satation;
    QString arr_station;
    int date;
    query_ticket_ss_data(QString a, QString b, int c) :
        dep_satation(a), arr_station(b), date(c){}
	friend QTS& operator << (QTS &out, const query_ticket_ss_data & rhs) {
		out << rhs.dep_satation << endl << rhs.arr_station << endl << rhs.date << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, query_ticket_ss_data & rhs) {
		in >> rhs.dep_satation >> rhs.arr_station >> rhs.date;
		return in;
	}
};

struct query_ticket_ans {
    // 返回vector
    QString train_name;
    int start_date;
    QString start_station;
    QString start_time;
    QString end_station;
    QString end_time;
    QString seat_kind;
    int ticket_left;
	friend QTS& operator << (QTS &out, query_ticket_ans& r) {
		out << r.train_name << endl << r.start_date << endl << r.start_station << endl
			<< r.start_time << endl << r.end_station << endl << r.end_time << endl
			<< r.seat_kind << endl << r.ticket_left << endl;
		return out;
	}
	friend QTS& operator >> (QTS& in, query_ticket_ans &r) {
		in >> r.train_name >> r.start_date >> r.start_station >> r.start_time >> r.end_station
		   >> r.end_time >> r.seat_kind >> r.ticket_left;
		return in;
	}
};

struct query_my_order_data {
    int ID;
    query_my_order_data(int _id) : ID(_id) {}
	friend QTS& operator << (QTS& out, const query_my_order_data & r) {
		out << r.ID << endl;
		return out;
	}
	friend QTS& operator >> (QTS& in, query_my_order_data & r) {
		in >> r.ID;
		return in;
	}
};
struct query_my_order_ans
{
    // 返回vector
    QString train_name;
    QString start_date;
    QString start_station;
    QString start_time;
    QString end_station;
    QString end_time;
    QString seat_kind;
    int ticket_number;
	friend QTS& operator << (QTS &out, const query_my_order_ans & r) {
		out << r.train_name << endl << r.start_date << endl << r.start_station << endl
			<< r.start_time << endl << r.end_station << endl << r.end_time << endl
			<< r.seat_kind << endl << r.ticket_number << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, query_my_order_ans & r) {
		in >> r.train_name >> r.start_date >> r.start_station >> r.start_station
		   >> r.start_time >> r.end_station >> r.end_time >> r.seat_kind >> r.ticket_number;
		return in;
	}
};

struct return_tickets_data {
    int ID;
    QString train_name;
    QString start_date;
    QString start_station;
    QString end_station;
    QString seat_kind;
    int ticket_number;
	friend QTS& operator << (QTS &out, const return_tickets_data & r) {
		out << r.ID << endl << r.train_name << endl << r.start_date << endl
			<< r.start_station << endl << r.end_station << endl << r.seat_kind << endl
			<< r.ticket_number << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, return_tickets_data & r) {
		in >> r.ID >> r.train_name >> r.start_date >> r.start_station >> r.end_station
		   >> r.seat_kind >> r.ticket_number >> r.ticket_number;
		return in;
	}
};
typedef bool return_tickets_ans;

struct buy_tickets_data {
    int ID;
    QString train_name;
    int start_date;
    QString start_station;
    QString end_station;
    QString seat_kind;
    int ticket_num;
    buy_tickets_data(){}
    buy_tickets_data(int id ,QString a, int b, QString c, QString d, QString e, int f):
        ID(id), train_name(a), start_date(b), start_station(c), end_station(d), seat_kind(e), ticket_num(f){}
	friend QTS& operator << (QTS &out, const buy_tickets_data & r) {
		out << r.ID << endl << r.train_name << endl << r.start_date << endl << r.start_station << endl
			<< r.end_station << endl << r.seat_kind << endl << r.ticket_num << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, buy_tickets_data & r) {
		in >> r.ID >> r.train_name >> r.start_date >> r.start_station >> r.end_station >> r.seat_kind
		   >> r.ticket_num;
		return in;
	}
	// 数据成员太多了，构造函数太长了，
    // 你到时候声明一个变量逐步赋值好了。
    // 活在梦里，构造函数和变量逐步赋值哪个长
};
typedef bool buy_tickets_ans;

typedef QString delete_line_data; // line_name
typedef bool delete_line_ans;

struct register_user_data {
    QString name;
    QString password;
    register_user_data(QString _name, QString _p)
        : name(_name), password(_p) {}
	friend QTS& operator << (QTS &out, const register_user_data & r) {
		out << r.name << endl << r.password << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, register_user_data & r) {
		in >> r.name >> r.password;
		return in;
	}
};
typedef int register_user_ans; // ID

struct register_admin_data {
    QString name;
    QString password;
    register_admin_data(QString _name, QString _p)
        : name(_name), password(_p) {}
	friend QTS& operator << (QTS &out, const register_admin_data & r) {
		out << r.name << endl << r.password << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, register_admin_data & r) {
		in >> r.name >> r.password;
		return in;
	}
};
typedef int register_admin_ans; // ID

struct add_line_data
{
    QString train_name;
    QString more_info;
    add_line_data(QString a, QString b):
        train_name(a), more_info(b){}
	friend QTS& operator << (QTS &out, const add_line_data & r) {
		out << "add_line_data" << endl << r.train_name << endl << r.more_info << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, add_line_data & r) {
		in >> r.train_name >> r.more_info;
		return in;
	}
};

struct add_train_data {
    QString line_name;
    int ldata, rdata;
	friend QTS& operator << (QTS &out, const add_train_data & r) {
		out << "add_train_data" << endl << r.line_name << endl << r.ldata << endl << r.rdata << endl;
		return out;
	}
	friend QTS& operator >> (QTS &in, add_train_data & r) {
		in >> r.line_name >> r.ldata >> r.rdata;
		return in;
	}
};
struct change_password_data {
	int ID;
	QString new_password;
	change_password_data(int a, QString b):
		ID(a), new_password(b){}
};
typedef bool change_password_ans;

struct start_selling_data {
	QString line_name;
	int date;
	start_selling_data(QString a, int b):
		line_name(a), date(b){}
};
typedef bool start_selling_ans;

struct end_selling_data {
	QString line_name;
	int date;
};
typedef bool end_selling_ans;

struct check_user_data {
	// admin
	int ID;
};
struct check_user_ans {
	QString name;
	vector<query_my_order_ans> tickets;
};

struct check_line_data {
	QString line_name;
};
struct check_line_ans {
	QString line_name;
	vector<QString> seat_kind_names;
	vector<QString> station_names;
	vector<int> arr_time;
	vector<int> dep_time;
	vector<vector<double>> price;

};

int transfer_date(const QString & str);

typedef bool add_train_ans;

/*函数接口名
 *
 * query_city_city
 * query_station_station
 * add_line
 * delete_line
 * */

}

#endif // QUERY_H

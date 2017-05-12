//
// Created by Aaron Ren on 12/05/2017.
//

#include "../header/memory_pool.h"

sjtu::pool_ptr<sjtu::Station> sjtu::memory_pool::get_station() {
    return sjtu::get_T(&stations);
}

sjtu::pool_ptr<sjtu::City> sjtu::memory_pool::get_city() {
    return sjtu::get_T(&cities);
}

sjtu::pool_ptr<sjtu::Line> sjtu::memory_pool::get_line() {
    return sjtu::get_T(&lines);
}

sjtu::pool_ptr<sjtu::Train> sjtu::memory_pool::get_train() {
    return sjtu::get_T(&trains);
}

sjtu::pool_ptr<sjtu::Ticket>
sjtu::memory_pool::get_ticket(int from, int to, int kind, double price, int num) {
    return sjtu::get_T(&tickets);
}

sjtu::vector<sjtu::Station> sjtu::memory_pool::stations;
sjtu::vector<sjtu::City>    sjtu::memory_pool::cities;
sjtu::vector<sjtu::Line>    sjtu::memory_pool::lines;
sjtu::vector<sjtu::Train>   sjtu::memory_pool::trains;
sjtu::vector<sjtu::Ticket>  sjtu::memory_pool::tickets;

sjtu::vector<sjtu::User>    sjtu::memory_pool::users;
sjtu::vector<sjtu::Admin>   sjtu::memory_pool::admins;
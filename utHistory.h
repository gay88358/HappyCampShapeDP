#ifndef UTHISTORY_H
#define UTHISTORY_H

#include "./include/history.h"
#include "./include/order.h"

Order* createOrder() {
    Order *order = new Order(new Customer("ZZZZ", "123"));
    order->addLineItem(new Clothes("hat", "a hat", 1123.1), 2);
    order->addLineItem(new Clothes("pants", "a pants", 1123.1), 2);
    return order;
}


TEST(History, create_history) {
    History *history = new History();
    history->record(createOrder());
    history->record(createOrder());
    history->record(createOrder());
    history->record(createOrder());
    ASSERT_EQ(4, history->orderSize());
}

TEST(History, history_information) {

    History *history = new History();
    history->record(createOrder());

    string information = history->getAllRecordInformation();
    ASSERT_EQ("hat\t2\t2246.200000\npants\t2\t2246.200000\n", information);
}
#endif
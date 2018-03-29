#ifndef ORDERLINEITEM_H
#define ORDERLINEITEM_H

#include "./order.h"
class OrderLineItem {
public:
    OrderLineItem();
    void addOrder(Order *order);
    Order* orders(int index);
    int orderLength() const;
    vector<Order*> orderVector();
    void addDrinkToCurrentOrder(Drink *d);
    Order* currentOrder();
    string getReceipt();
private:
    vector<Order*> _orders;
};

#endif
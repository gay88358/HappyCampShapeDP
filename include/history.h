#ifndef HISTORY_H
#define HISTORY_H

#include "./order.h"
#include "./customer.h"

class History {
public:
    History();
    History(Customer *customer);
    void record(Order*);
    int orderSize();
    Customer* getCustomer();
    string getAllRecordInformation();
private:
    Customer* _customer;
    vector<Order*> _orders;
};

#endif
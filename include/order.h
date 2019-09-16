#ifndef ORDER_H
#define ORDER_H

#include "./clothes.h"
#include "./lineItem.h"
#include <vector>

using std::vector;
#include "./customer.h"
#include "./customerTracker.h"

class Order {
public:
    Order(Customer *customer);
    void addLineItem(Clothes* clothes, int qty);
    double getTotalPrice();
    void endOrder(CustomerTracker* tracker);
    string getOrderInformation();
private:
    string getDisplayPrice();
    void adjustDiscountOrder(double);

    bool _isComplete;

    double _priceToDeduction;
    bool _isDiscountOrder;
    Customer *_customer;
    vector<LineItem*> _lineItems;
};

#endif

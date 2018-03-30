#ifndef ORDER_H
#define ORDER_H

#include "./drinkLineItem.h"
#include "./observer.h"

#include "./regularCustomer.h"
#include "./vipCustomer.h"

class Order {
public:
    Order();
    Order(Observer *ob);
    void addOrder(Drink *d);
    int total() const;
    string receipt() const;
    bool isEmpty() const;
    void setBonusDrink();
    // template method
    virtual void finishOrder();
protected:
    Observer *_observerCustomer = nullptr;
    DrinkLineItem* _drinkLineItem = nullptr;
};


#endif
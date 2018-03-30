#ifndef VIPORDER_H
#define VIPORDER_H

#include "./order.h"

class VipOrder : public Order {
public:
    VipOrder(Observer *ob);
    virtual void finishOrder();
};


#endif
#ifndef REGULARORDER_H
#define REGULARORDER_H

#include "./order.h"

class RegularOrder : public Order {
public:
    RegularOrder(Observer *ob);
};


#endif
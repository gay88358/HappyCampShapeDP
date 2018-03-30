#ifndef VIPDRINKSHOP_H
#define VIPDRINKSHOP_H

#include "./drinkShop.h"
#include "./vipOrder.h"
class VipDrinkShop : public DrinkShop {
public:
    VipDrinkShop(string name);
    virtual void createNewOrder(Customer *c);
};

#endif
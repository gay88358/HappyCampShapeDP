#ifndef REGULARDRINKSHOP_H
#define REGULARDRINKSHOP_H
#include "./drinkShop.h"
#include "./regularOrder.h"

class RegularDrinkShop : public DrinkShop {
public:
    RegularDrinkShop(string name);
    virtual void createNewOrder(Customer *c);
};

#endif
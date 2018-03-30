#ifndef SHOPFACTORY_H
#define SHOPFACTORY_H

#include "./vipDrinkShop.h"
#include "./regularDrinkShop.h"
#include "./vipCustomer.h"
#include "./regularCustomer.h"

class ShopFactory {
public:
    DrinkShop* createVipDrinkShop(string name);
    DrinkShop* createRegularShop(string name);
};


#endif
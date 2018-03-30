#include "../include/shopFactory.h"


DrinkShop* ShopFactory::createVipDrinkShop(string name) {
    DrinkShop *vipShop = new VipDrinkShop(name);
    Customer *vipCustomer = new VipCustomer(name);
    vipShop->createNewOrder(vipCustomer);
    return vipShop;
}

DrinkShop* ShopFactory::createRegularShop(string name) {
    DrinkShop *rShop = new RegularDrinkShop(name);
    Customer *rCustomer = new RegularCustomer(name);
    rShop->createNewOrder(rCustomer);
    return rShop;
}


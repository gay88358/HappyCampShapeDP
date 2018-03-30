#include "../include/vipDrinkShop.h"

#include <iostream>

using std::endl;
using std::cout;

VipDrinkShop::VipDrinkShop(string name): DrinkShop(name) {

}

void VipDrinkShop::createNewOrder(Customer *c) {
    _customer = c;
    cout << "VIP" << endl;
    this->_orderLineItem->addOrder(new VipOrder(c));
}
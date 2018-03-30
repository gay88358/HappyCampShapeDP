#include "../include/regularDrinkShop.h"

RegularDrinkShop::RegularDrinkShop(string name): DrinkShop(name) {

}


void RegularDrinkShop::createNewOrder(Customer *c) {
    _customer = c;
    this->_orderLineItem->addOrder(new RegularOrder(c));
}

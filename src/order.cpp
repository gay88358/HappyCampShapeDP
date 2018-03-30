#include "../include/order.h"
#include <iostream>

using std::cout;
using std::endl;

Order::Order(): _drinkLineItem(new DrinkLineItem()) {

}

Order::Order(Observer *ob): _drinkLineItem(new DrinkLineItem()), _observerCustomer(ob) {

}

void Order::finishOrder() {
    int orderTotal = total();
    this->_observerCustomer->notify(orderTotal);
}

void Order::addOrder(Drink *d) {
    this->_drinkLineItem->addDrink(d);
}

int Order::total() const {
    return this->_drinkLineItem->total();
}

string Order::receipt() const {
    return this->_drinkLineItem->assembleDrinkDataString();    
}

bool Order::isEmpty() const {
    return this->_drinkLineItem->drinkLength() == 0;
}

void Order::setBonusDrink() {
    // set the price of the most expensive drink to 0
    this->_drinkLineItem->setBonusDrink();
    this->_observerCustomer->useBonusPoint();
}
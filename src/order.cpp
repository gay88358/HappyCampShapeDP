#include "../include/order.h"

Order::Order(): _drinkLineItem(new DrinkLineItem()) {

}

Order::Order(Observer *ob): _drinkLineItem(new DrinkLineItem()), _observerCustomer(ob) {

}

void Order::finishOrder() {
    int orderTotal = total();
    this->_observerCustomer->notify(orderTotal);
    //delete this->_drinkLineItem;
    //this->_drinkLineItem = new DrinkLineItem();
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
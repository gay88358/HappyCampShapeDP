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
    RegularCustomer *rc = dynamic_cast<RegularCustomer*>(this->_observerCustomer);
    if (rc) {
        this->_observerCustomer->notify(orderTotal);
    } else {
        // vip
        vector<Drink*> v = this->_drinkLineItem->drinkVector();
        int price = 0;
        for (int i = 0; i < v.size(); i++) {
            string name = v[i]->name();
            if (name == "南非國寶茶" || name == "烏龍茶") {
                price += v[i]->price();
            }
        }
        int off = orderTotal - price;
        this->_observerCustomer->notify(off);
        this->_observerCustomer->notify(price * 2);
    }
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
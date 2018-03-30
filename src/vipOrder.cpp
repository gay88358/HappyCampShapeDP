#include "../include/vipOrder.h"
#include <iostream>

using std::endl;
using std::cout;
VipOrder::VipOrder(Observer *ob): Order(ob) {

}

void VipOrder::finishOrder() {
    std::cout << "VIP ORDER" << std::endl;
    int orderTotal = total();
    vector<Drink*> v = this->_drinkLineItem->drinkVector();
    int price = 0;
    for (int i = 0; i < v.size(); i++) {
        string name = v[i]->name();
        if (name == "南非國寶茶" || name == "烏龍茶") {
            price += v[i]->price();
        }
    }
    int off = orderTotal - price;
    cout << "OFF: " << off << endl;
    this->_observerCustomer->notify(off);
    this->_observerCustomer->notify(price * 2);
}

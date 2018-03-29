#include "../include/orderLineItem.h"

OrderLineItem::OrderLineItem() {

}

void OrderLineItem::addOrder(Order *order) {
    this->_orders.push_back(order);
}

Order* OrderLineItem::orders(int index) {
    return this->_orders[index];
}

int OrderLineItem::orderLength() const {
    return this->_orders.size();
}

vector<Order*> OrderLineItem::orderVector() {
    return this->_orders;
}

Order* OrderLineItem::currentOrder() {
    return this->_orders[this->_orders.size() - 1];
}

void OrderLineItem::addDrinkToCurrentOrder(Drink *d) {
    Order *order = currentOrder();
    order->addOrder(d);
}

string OrderLineItem::getReceipt() {
    string result = "";
    for (int i = 0; i < this->_orders.size(); i++) {
        string title = "購買收據 " + std::to_string(i + 1) + "\n";
        string subTitle = "NO.\t\t飲料名稱\t\t卡路里\t\t價格\n";
        string header = title + subTitle; 
        result = result + header + this->_orders[i]->receipt() + "\n";
    }
    return result;
}

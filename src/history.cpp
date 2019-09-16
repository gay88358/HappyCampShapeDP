#include "../include/history.h"


History::History() {
    
}

History::History(Customer *customer) {
    this->_customer = customer;
}

Customer* History::getCustomer() {
    return this->_customer;
}

void History::record(Order* orderToAdd) {
    this->_orders.push_back(orderToAdd);
}

int History::orderSize() {
    return this->_orders.size();
}


string History::getAllRecordInformation() {
    string result = "";
    for (int i = 0; i < this->_orders.size(); i++) {
        result += this->_orders[i]->getOrderInformation() + "\n\n";
    }
    return result;
}
#include "../include/customerTracker.h"
#include <iostream>

using std::cout;
using std::endl;
void CustomerTracker::logPurchaseOf(Customer *customer) {
    if (!hasCustomerPurchased(customer)) {
        _customerPurchasedTable[customer] = 1;
    } else {
        _customerPurchasedTable[customer]++;
    }
}

bool CustomerTracker::hasCustomerPurchased(Customer *customer) {
    map<Customer*, int>::iterator it = this->_customerPurchasedTable.find(customer);
    return it != _customerPurchasedTable.end();
}

double CustomerTracker::applyDiscountRule(Customer *customer, double totalPrice) {
    if (isRegularCustomer(customer))
        return totalPrice * DISCOUNT;
    return totalPrice;
}

bool CustomerTracker::isRegularCustomer(Customer *customer) {
    if (!hasCustomerPurchased(customer))
        return false;

    int purchased_times = this->_customerPurchasedTable[customer];

    return purchased_times >= PURCHASE_TIMES_HAS_DISCOUNT;
}

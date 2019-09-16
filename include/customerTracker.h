#ifndef CUSTOMERTRACKER_H
#define CUSTOMERTRACKER_H

#include "./customer.h"

#include <map>

using std::map;

class CustomerTracker {
public:
    void logPurchaseOf(Customer *customer);
    double applyDiscountRule(Customer *customer, double totalPrice);
    bool isRegularCustomer(Customer *cusotmer);
private:
    // method
    bool hasCustomerPurchased(Customer *customer);
    // field
    map<Customer*, int> _customerPurchasedTable;
    const double DISCOUNT = 0.9;
    const int PURCHASE_TIMES_HAS_DISCOUNT = 3;
};  


#endif
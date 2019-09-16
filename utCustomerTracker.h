#ifndef UTCUSTOMERTRACKER_H
#define UTCUSTOMERTRACKER_H


#include "./include/customerTracker.h"
#include "./include/customer.h"

// tem percent off of discount
TEST(CustomerTracker, track_customer_purchase_times) {
    CustomerTracker* tracker = new CustomerTracker();
    Customer *john = new Customer("John", "1010");

    double orderTotalPrice = 1000;
    tracker->logPurchaseOf(john);
    ASSERT_EQ(1000, tracker->applyDiscountRule(john, orderTotalPrice));
    
    tracker->logPurchaseOf(john);
    ASSERT_EQ(1000, tracker->applyDiscountRule(john, orderTotalPrice));

    tracker->logPurchaseOf(john);
    ASSERT_EQ(900, tracker->applyDiscountRule(john, orderTotalPrice));
}

#endif
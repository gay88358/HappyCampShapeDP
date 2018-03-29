#ifndef UTCUSTOMER_H
#define UTCUSTOMER_H

#include "./include/customer.h"
#include "./include/regularCustomer.h"
#include "./include/vipCustomer.h"

TEST(Customer, create_customer) {
    Customer c("Z-Xuan Hong");
    ASSERT_EQ("Z-Xuan Hong", c.name());
}

TEST(Customer, add_boundpoint) {
    Customer c("Z-Xuan Hong");
    c.addBonusPoint(123);
    ASSERT_EQ(123, c.getBonusPoint());
}

TEST(Customer, regularCustomer) {
    Customer *customer = new RegularCustomer("poor man");
    customer->notify(1000);
    ASSERT_EQ(33, customer->getBonusPoint());
    customer->useBonusPoint();
    ASSERT_EQ(23, customer->getBonusPoint());
}

TEST(Customer, vipCustomer) {
    Customer *customer = new VipCustomer("poor man");
    customer->notify(1000);
    ASSERT_EQ(33, customer->getBonusPoint());
    customer->useBonusPoint();
    ASSERT_EQ(23, customer->getBonusPoint());
}


#endif
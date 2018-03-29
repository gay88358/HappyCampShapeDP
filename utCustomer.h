#ifndef UTCUSTOMER_H
#define UTCUSTOMER_H

#include "./include/customer.h"

TEST(Customer, create_customer) {
    Customer c("Z-Xuan Hong");
    ASSERT_EQ("Z-Xuan Hong", c.name());
}

TEST(Customer, add_boundpoint) {
    Customer c("Z-Xuan Hong");
    c.addBonusPoint(123);
    ASSERT_EQ(123, c.getBonusPoint());
}

#endif
#ifndef UTCUSTOMER_H
#define UTCUSTOMER_H

#include "./include/customer.h"

TEST(Customer, new_customer_has_1000_digit_cash) {
    string name = "Z-Xuan Hong";
    string password = "0101";
    Customer *customer = new Customer(name, password);

    ASSERT_EQ(1000, customer->getCash());
    ASSERT_EQ(name, customer->getName());
}

TEST(Customer, check_whether_is_correct_password) {
    string name = "Z-Xuan Hong";
    string password = "0101";
    Customer *customer = new Customer(name, password);

    ASSERT_TRUE(customer->isCorrectPassword("0101"));
    ASSERT_FALSE(customer->isCorrectPassword("123123"));
}

TEST(Customer, deduction_from_customer) {
    string name = "Z-Xuan Hong";
    string password = "0101";
    Customer *customer = new Customer(name, password);

    customer->deduction(125);

    ASSERT_EQ(1000 - 125, customer->getCash());
}

#endif
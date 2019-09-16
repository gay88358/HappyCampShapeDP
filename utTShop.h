#ifndef UTTSHOP_H
#define UTTSHOP_H

#include "./include/tShop.h"
#include "./include/customer.h"
#include <iostream>
using std::cout;
using std::endl;

class TShopTest : public ::testing::Test {
protected:
    
    virtual void SetUp() {
        Clothes::resetCurrentId();
    }
    // You can define per-test tear-down logic as usual.
    virtual void TearDown() { 
        Clothes::resetCurrentId();
    }


    void purchaseClothes(TShop *tShop, Customer *customer) {
        tShop->makeNewOrder(customer);
        tShop->enterItem(1, 3);
        tShop->enterItem(2, 3);
        tShop->enterItem(3, 1);
        tShop->endOrder();
    }
};

TEST_F(TShopTest, customer_purchase_clothes_and_end_order) {
    TShop *tShop = new TShop();
    Customer *customer = new Customer("Z-Xuan Hong", "107598042");
    ASSERT_EQ(1000, customer->getCash());
    
    purchaseClothes(tShop, customer);

    double cash = customer->getCash();
    ASSERT_EQ(300, cash);
}

TEST_F(TShopTest, customer_has_no_money_to_purchase_clothes) {
    TShop *tShop = new TShop();
    Customer *customer = new Customer("Z-Xuan Hong", "107598042");
    customer->setCash(0);
    
    try {
        purchaseClothes(tShop, customer);
        FAIL();
    } catch(const std::invalid_argument& e) {
        string result = e.what();
        ASSERT_EQ("customer has no enough money to purchase", result);
    }
}

TEST_F(TShopTest, get_history_after_customer_purchased) {
    TShop *tShop = new TShop();
    Customer *customer = new Customer("Z-Xuan Hong", "107598042");

    purchaseClothes(tShop, customer);

    History *history = tShop->findPurchasedHistoryOf(customer);
    ASSERT_EQ(customer, history->getCustomer());
    ASSERT_EQ(1, history->orderSize());
}

TEST_F(TShopTest, two_customer_purchase_clothes_and_end_order) {
    TShop *tShop = new TShop();
    
    Customer *john = new Customer("John", "107598042");
    Customer *marry = new Customer("Marry", "123");

    purchaseClothes(tShop, john);
    purchaseClothes(tShop, marry);

    History *historyOfJohn = tShop->findPurchasedHistoryOf(john);
    ASSERT_EQ(john, historyOfJohn->getCustomer());
    
    History *historyOfMarry = tShop->findPurchasedHistoryOf(marry);
    ASSERT_EQ(marry, historyOfMarry->getCustomer());
}

TEST_F(TShopTest, add_item_which_is_not_in_catalog) {
    TShop *tShop = new TShop();
    Customer *john = new Customer("John", "107598042");
    int invalidId = 999;
    try {
        tShop->makeNewOrder(john);
        tShop->enterItem(invalidId, 111);
        FAIL();
    } catch (const std::invalid_argument &e) {
        string result = e.what();
        ASSERT_EQ("id of clothes: " + std::to_string(invalidId) + " is not in the catalog", result);
    }

}

TEST_F(TShopTest, enter_item_before_make_new_order_is_invalid) {
    TShop *tShop = new TShop();
    Customer *john = new Customer("John", "107598042");
    int invalidId = 999;
    try {
        tShop->enterItem(invalidId, 111);
        FAIL();
    } catch (const std::invalid_argument &e) {
        string result = e.what();
        ASSERT_EQ("請先建立新訂單，才能夠加入物品到訂單！", result);
    }
}

TEST_F(TShopTest, end_order_before_make_new_order_is_invalid) {
    TShop *tShop = new TShop();
    Customer *john = new Customer("John", "107598042");
    int invalidId = 999;
    try {
        tShop->endOrder();
        FAIL();
    } catch (const std::invalid_argument &e) {
        string result = e.what();
        ASSERT_EQ("請先建立新訂單，才能夠結束訂單！", result);
    }
}
// discount: 10% off
// customer becomes regular customer after purchase three times
TEST_F(TShopTest, regular_customer_has_ten_percent_off_discount_when_purchase) {
    TShop *tShop = new TShop();
    
    Customer *john = new Customer("John", "107598042");
    john->setCash(2730);
    ASSERT_EQ(2730, john->getCash());
    // ecah purchase deduction 700 from customer
    purchaseClothes(tShop, john);
    ASSERT_EQ(2030, john->getCash());
    ASSERT_FALSE(tShop->isRegularCustomer(john));

    purchaseClothes(tShop, john);
    ASSERT_EQ(1330, john->getCash());
    ASSERT_FALSE(tShop->isRegularCustomer(john));

    purchaseClothes(tShop, john);
    ASSERT_EQ(630, john->getCash());
    ASSERT_TRUE(tShop->isRegularCustomer(john));

    purchaseClothes(tShop, john);
    // regular customer has ten percent discount
    ASSERT_EQ(0, john->getCash());
    ASSERT_TRUE(tShop->isRegularCustomer(john));
}


#endif
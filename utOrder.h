#ifndef UTORDER_H
#define UTORDER_H

#include "./include/order.h"
#include "./include/clothes.h"

Clothes* createClothes() {
    string name = "t-shirt";
    string description = "this is a t-shirt";
    double price = 100;
    Clothes *clothes = new Clothes(name, description, price);
    return clothes;
}

TEST(LineItem, calculate_total_price_of_line_iten) {
    int qty = 5;
    LineItem *lineItem = new LineItem(createClothes(), qty);
    ASSERT_EQ(500, lineItem->getTotalPrice());
}

TEST(Order, calculate_total_price_of_order) {
    Order *order = new Order(nullptr);
    order->addLineItem(createClothes(), 2);
    order->addLineItem(createClothes(), 3);
    order->addLineItem(createClothes(), 5);
    double totalPrice = order->getTotalPrice();
    ASSERT_EQ(1000.0, totalPrice);    
}

TEST(Order, add_item_to_order_after_end_order_is_invalid) {
    Order *order = new Order(new Customer("Z-Xaun Hong", "1010"));
    order->addLineItem(createClothes(), 2);
    order->endOrder(new CustomerTracker());
    try {
        order->addLineItem(createClothes(), 3);
        FAIL();
    } catch(const std::invalid_argument &e) {     
        string result = e.what();   
        ASSERT_EQ("在結束訂單後，不能在加入物品到此訂單，請重新創建訂單", result);
    }
}

TEST(Order, end_order_after_end_order_is_invalid) {
    Order *order = new Order(new Customer("Z-Xaun Hong", "1010"));
    order->addLineItem(createClothes(), 2);
    order->endOrder(new CustomerTracker());
    try {
        order->endOrder(new CustomerTracker());
        FAIL();
    } catch(const std::invalid_argument &e) {     
        string result = e.what();   
        ASSERT_EQ("在結束訂單之後，不能在結束訂單，請重新建立新訂單！", result);
    }
}

#endif
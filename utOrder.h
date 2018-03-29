#ifndef UTORDER_H
#define UTORDER_H

#include "./include/order.h"
#include "./include/drink.h"
#include "./include/reader.h"
#include "./include/customer.h"
#include "./include/observer.h"
#include "./include/orderLineItem.h"

TEST(OrderLineItem, add_order) {
    OrderLineItem *oline = new OrderLineItem();
    Customer *c = new Customer("Z-Xuan Hong");
    oline->addOrder(new Order(c));
    oline->addOrder(new Order(c));
    oline->addOrder(new Order(c));
    ASSERT_EQ(3, oline->orderLength());
}

TEST(OrderLineItem, addNewOrder) {
    OrderLineItem *oline = new OrderLineItem;
    Customer *c = new Customer("Z-Xuan Hong");
    oline->addOrder(new Order(c));

    oline->addDrinkToCurrentOrder(new Drink("南非茶", 100, 25));
    oline->addDrinkToCurrentOrder(new Drink("南茶", 40, 35));
    oline->addDrinkToCurrentOrder(new Drink("非茶", 50, 15));

    Order *currentOrder = oline->currentOrder();

    ASSERT_EQ(75, currentOrder->total());
}


TEST(Reader, readFileByName) {
    Reader *r = new Reader("drinkMenu.txt");
    r->readFile();
    DrinkLineItem *d = r->getResultDrinkLineItem();
 
    ASSERT_EQ("南非國寶茶", d->drinks(0)->name());
    ASSERT_EQ(24, d->drinks(0)->calorie());
    ASSERT_EQ(25, d->drinks(0)->price());

    ASSERT_EQ("南茶", d->drinks(5)->name());
    ASSERT_EQ(24, d->drinks(5)->calorie());
    ASSERT_EQ(10, d->drinks(5)->price());
}


TEST(Order, order_drink) {
    Order *order = new Order();
    order->addOrder(new Drink("南非茶", 100, 25));
    order->addOrder(new Drink("非茶", 100, 25));
    ASSERT_EQ(50, order->total());
}

TEST(Order, order_receipt) {
    Order *order = new Order();
    order->addOrder(new Drink("南非茶", 100, 25));
    order->addOrder(new Drink("非茶", 100, 25));
    order->receipt();
}

TEST(Order, order_empty) {
    Order *order = new Order();
    ASSERT_TRUE(order->isEmpty());
    order->addOrder(new Drink("南非茶", 100, 25));
    ASSERT_FALSE(order->isEmpty());
}


TEST(Order, finishOrderWithCustomer) {
    Customer *customer = new Customer("Z-Xuan Hong");
    Order *order = new Order(customer);
    ASSERT_TRUE(order->isEmpty());
    order->addOrder(new Drink("南非茶", 100, 25));
    order->addOrder(new Drink("南非茶", 100, 25));
    order->addOrder(new Drink("南非茶", 100, 25));
    order->finishOrder();
    ASSERT_EQ(2, customer->getBonusPoint());
}

TEST(Order, setBonudDrink) {
    Customer *c = new Customer("Z-Xuan Hong");
    c->addBonusPoint(20);
    Order *order = new Order(c);
    order->addOrder(new Drink("南非茶", 100, 1000));
    order->addOrder(new Drink("南非茶", 100, 50));
    order->addOrder(new Drink("南非茶", 100, 250));
    order->setBonusDrink();
    order->total();
    ASSERT_EQ(300, order->total());
}

TEST(Order, CustomerUseBoundDrink) {
    Customer *c = new Customer("Z-Xuan Hong");
    Order *order = new Order(c);
    order->addOrder(new Drink("南非茶", 100, 1000));
    order->addOrder(new Drink("南非茶", 100, 50));
    order->addOrder(new Drink("南非茶", 100, 250));
    order->finishOrder();
    ASSERT_EQ(43, c->getBonusPoint());

    Order *order2 = new Order(c);
    order2->addOrder(new Drink("南非茶", 100, 1000));
    order2->addOrder(new Drink("南非茶", 100, 50));
    order2->addOrder(new Drink("南非茶", 100, 250));
    order2->setBonusDrink();
    order2->finishOrder();
    ASSERT_EQ(43, c->getBonusPoint());
}

#endif
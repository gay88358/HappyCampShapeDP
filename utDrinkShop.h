#ifndef UTDRINKSHOP_H
#define UTDRINKSHOP_H

#include "./include/drinkShop.h"
#include "./include/customer.h"
#include "./include/order.h"
#include <iostream>
#include <iomanip>


using std::cout;
using std::endl;
TEST(DrinkShop, create_drinkShop) {
    DrinkShop *drinkShop = new DrinkShop("711");
    ASSERT_EQ("711", drinkShop->name());
}

TEST(DrinkShop, add_drink) {
    DrinkShop *drinkShop = new DrinkShop("711");
    int previousMenuLegth = drinkShop->menuLength();
    drinkShop->addDrinkToMenu("伯爵紅茶", 50, 50);
    int menuLength = drinkShop->menuLength();
    ASSERT_EQ(1, menuLength - previousMenuLegth);
}

TEST(DrinkShop, get_drink_list) {
    DrinkShop *drinkShop = new DrinkShop("711");
    drinkShop->addDrinkToMenu("伯爵紅茶", 50, 50);
    vector<Drink*> v = drinkShop->getDrinks();
    ASSERT_EQ("伯爵紅茶", v[v.size() - 1]->name());
    ASSERT_EQ(50, v[v.size() - 1]->calorie());
    ASSERT_EQ(50, v[v.size() - 1]->price());
}

TEST(DrinkShop, initialize_drinkList) {
    DrinkShop *drinkShop = new DrinkShop("711");
    ASSERT_EQ(9, drinkShop->menuLength());
}


TEST(DrinkShop, order_drink) {
    DrinkShop *drinkShop = new DrinkShop("711");
    Customer *c = new Customer("Z-Xuan Hong");
    drinkShop->createNewOrder(c);
    drinkShop->addDrinkToOrder(new Drink("伯爵紅茶", 50, 50));
    drinkShop->addDrinkToOrder(new Drink("紅茶", 20, 30));
    drinkShop->addDrinkToOrder(new Drink("伯茶", 20, 60));
    Order *o = drinkShop->currentOrder();
    drinkShop->endOrder();
    ASSERT_EQ(140, o->total());
    ASSERT_EQ(4, c->getBonusPoint());
}

TEST(DrinkShop, multiple_order) {
    DrinkShop *drinkShop = new DrinkShop("711");
    Customer *c = new Customer("Z-Xuan Hong");
    drinkShop->createNewOrder(c);
    drinkShop->addDrinkToOrder(new Drink("伯爵紅茶", 50, 50));
    drinkShop->addDrinkToOrder(new Drink("紅茶", 20, 30));
    drinkShop->addDrinkToOrder(new Drink("伯茶", 20, 60));
    drinkShop->endOrder();
    ASSERT_EQ(4, c->getBonusPoint());

    drinkShop->createNewOrder(c);
    drinkShop->addDrinkToOrder(new Drink("伯爵紅茶", 50, 50));
    drinkShop->addDrinkToOrder(new Drink("紅茶", 20, 30));
    drinkShop->addDrinkToOrder(new Drink("伯茶", 20, 60));
    drinkShop->endOrder();
    ASSERT_EQ(8, c->getBonusPoint());
    cout << drinkShop->getReceipt() << endl;;
}

TEST(DrinkShop, isTheSameNameInDrinks) {
    DrinkShop *drinkShop = new DrinkShop("711");
    ASSERT_TRUE(drinkShop->isTheSameNameInDrinks("南非國寶茶"));
    ASSERT_FALSE(drinkShop->isTheSameNameInDrinks("我愛羅"));
}

TEST(DrinkShop, getMenuString) {
    DrinkShop *drinkShop = new DrinkShop("711");
    vector<string> menu = drinkShop->getMenu();
    for (int i = 0; i < menu.size(); i++) {
        cout << menu[i] << endl;
    }
}

TEST(DrinkShop, getOrderVector) {
    DrinkShop *drinkShop = new DrinkShop("711");
    Customer *c = new Customer("Son Goku");
    drinkShop->createNewOrder(c);
    drinkShop->addDrinkToOrder(new Drink("伯爵紅茶", 50, 50));
    drinkShop->addDrinkToOrder(new Drink("紅茶", 20, 30));
    drinkShop->addDrinkToOrder(new Drink("伯茶", 20, 60));
    drinkShop->endOrder();

    drinkShop->addDrinkToOrder(new Drink("伯爵紅茶", 50, 50));
    drinkShop->addDrinkToOrder(new Drink("紅茶", 20, 20));
    drinkShop->addDrinkToOrder(new Drink("伯茶", 20, 60));

    vector<Order*> orders = drinkShop->getOrderVector();
    ASSERT_EQ(2, orders.size());
    ASSERT_EQ(140, orders[0]->total());
    ASSERT_EQ(130, orders[1]->total());
}   
#endif
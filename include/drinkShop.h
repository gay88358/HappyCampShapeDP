#ifndef DRINKSHOP_H
#define DRINKSHOP_H

#include <string>
#include <vector>
#include "./drinkLineItem.h"
#include "./orderLineItem.h"
#include "./customer.h"
#include "./reader.h"
#include "./order.h"

using std::vector;
using std::string;

class DrinkShop {
public:
    DrinkShop(string name);
    Customer* customer();
    string customerName() const;
    string name() const;
    int menuLength() const;
    vector<Drink*> getDrinks();
    void addDrinkToMenu(string name, unsigned int calorie, unsigned int price);
    void createNewOrder(Customer *c);
    void addDrinkToOrder(Drink *d);
    Order* currentOrder();
    void endOrder();
    string getReceipt() const;
    bool isTheSameNameInDrinks(string name) const;
    vector<string> getMenu();
    vector<Order*> getOrderVector();
    bool isEnoughBonusPoint() const;
private:
    void initializeDrinkList();
    Customer * _customer = nullptr;
    string _name;
    Reader *_reader;
    DrinkLineItem *_drinkLineItem = nullptr;
    OrderLineItem *_orderLineItem = nullptr;
};

#endif
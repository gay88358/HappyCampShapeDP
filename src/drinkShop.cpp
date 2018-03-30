#include "../include/drinkShop.h"

DrinkShop::DrinkShop(string name): _name(name), _drinkLineItem(new DrinkLineItem), _orderLineItem(new OrderLineItem), _reader(new Reader("drinkMenu.txt")) {
    initializeDrinkList();
}

void DrinkShop::initializeDrinkList() {
    this->_reader->readFile();
    this->_drinkLineItem = this->_reader->getResultDrinkLineItem();
}

string DrinkShop::name() const {
    return this->_name;
}

Customer* DrinkShop::customer() {
    return this->_customer;
}

string DrinkShop::customerName() const {
    return this->_customer->name();
}

void DrinkShop::addDrinkToMenu(string name, unsigned int calorie, unsigned int price) {
    this->_drinkLineItem->addDrink(new Drink(name, calorie, price));
}

vector<Drink*> DrinkShop::getDrinks() {
    return this->_drinkLineItem->drinkVector();
}

int DrinkShop::menuLength() const {
    return this->_drinkLineItem->drinkLength();
}

void DrinkShop::createNewOrder(Customer *c) {
    _customer = c;
    this->_orderLineItem->addOrder(new Order(c));
}

void DrinkShop::addDrinkToOrder(Drink *d) {
    Drink *drink = new Drink(d->name(), d->calorie(), d->price());
    this->_orderLineItem->addDrinkToCurrentOrder(drink);
}

Order* DrinkShop::currentOrder() {
    return this->_orderLineItem->currentOrder();
}

void DrinkShop::endOrder() {
    Order *order = currentOrder();
    order->finishOrder();
    createNewOrder(this->_customer);
}

string DrinkShop::getReceipt() const {
    return this->_orderLineItem->getReceipt();
}

bool DrinkShop::isTheSameNameInDrinks(string name) const {
    return this->_drinkLineItem->isTheSameNameInDrinks(name);
}

vector<string> DrinkShop::getMenu() {
    vector<string> menu = {};
    int length = this->_drinkLineItem->drinkLength();
    for (int i = 0; i < length; i++) {
        Drink *drink = this->_drinkLineItem->drinks(i);
        menu.push_back(drink->getDrinkDataString());
    }
    return menu;
}

vector<Order*> DrinkShop::getOrderVector() {
    return this->_orderLineItem->orderVector();
}

bool DrinkShop::isEnoughBonusPoint() const {
    return this->_customer->isEnoughBonusPoint();
}






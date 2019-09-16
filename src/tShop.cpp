#include "../include/tShop.h"
#include <iostream>

using std::cout;
using std::endl;

TShop::TShop() {
    _clothesCatalog = new ClothesCatalog();
    _tracker = new CustomerTracker();
    _currentOrder = nullptr;
}


TShop::TShop(string name) {
    _name = name;
    _clothesCatalog = new ClothesCatalog();
    _tracker = new CustomerTracker();
    _currentOrder = nullptr;
}

void TShop::addNewClothes(string name, string description, double price) {
    this->_clothesCatalog->addNewClothes(name, price, description);
}

void TShop::makeNewOrder(Customer *customer) {
    _currentCustomer = customer;
    updateHistorys(customer);
    this->_currentOrder = new Order(customer);
}

void TShop::updateHistorys(Customer *customer) {
    if (this->_historys[customer] == nullptr) {
        this->_historys[customer] = new History(customer);
    }
}

bool TShop::isRegularCustomer(Customer *customer) {
    return this->_tracker->isRegularCustomer(customer);
}

void TShop::enterItem(int id, int qty) {
    if (_currentOrder == nullptr) {
        throw std::invalid_argument("請先建立新訂單，才能夠加入物品到訂單！");
    }

    Clothes* clothes = this->_clothesCatalog->findClothesBy(id);
    this->_currentOrder->addLineItem(clothes, qty);
}

string TShop::getCurrentOrderReceipt() {
    return this->_currentOrder->getOrderInformation();
}


void TShop::endOrder() {
    if (_currentOrder == nullptr) {
        throw std::invalid_argument("請先建立新訂單，才能夠結束訂單！");
    }

    this->_currentOrder->endOrder(this->_tracker);
    this->_historys[_currentCustomer]->record(this->_currentOrder);
    this->_tracker->logPurchaseOf(_currentCustomer);
}

void TShop::resetCurrentOrder() {
    this->_currentOrder = nullptr;
}

History* TShop::findPurchasedHistoryOf(Customer*customer) {
    return this->_historys[customer];
}

string TShop::getAllClothesInformation() {
    return _clothesCatalog->getAllClothesInformation();
}

string TShop::getName() {
    return this->_name;
}
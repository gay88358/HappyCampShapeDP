#include "../include/order.h"
#include <iostream>
#include "../include/utility.h"

using std::endl;
using std::cout;

Order::Order(Customer* customer) {
    this->_customer = customer;
    this->_isDiscountOrder = false;
    this->_priceToDeduction = 0;

    this->_isComplete = false;
}

void Order::addLineItem(Clothes* clothes, int qty) {
    if (this->_isComplete)
        throw std::invalid_argument("在結束訂單後，不能在加入物品到此訂單，請重新創建訂單");

    this->_lineItems.push_back(new LineItem(clothes, qty));
}


string Order::getOrderInformation() {
    string result = "";
    for (int i = 0;i < this->_lineItems.size(); i++)
        result += this->_lineItems[i]->getLineItemInformation();

    result += getDisplayPrice();
    return result;
}

string Order::getDisplayPrice() {
    if (this->_priceToDeduction > 0)
        return "\t\t總金額(折扣): " + Utility::convertStringWithPrecision(this->_priceToDeduction, 2);
    return "\t\t總金額: " + Utility::convertStringWithPrecision(getTotalPrice(), 2);
}


void Order::endOrder(CustomerTracker* tracker) {
    if (this->_isComplete)
        throw std::invalid_argument("在結束訂單之後，不能在結束訂單，請重新建立新訂單！");

    double totalPrice = getTotalPrice();
    // need to throw exception when no lineitems in the order
    double priceTodeduction = tracker->applyDiscountRule(this->_customer, totalPrice);
    this->_customer->deduction(priceTodeduction);

    adjustDiscountOrder(priceTodeduction);
    this->_isComplete = true;
}

void Order::adjustDiscountOrder(double priceTodeduction) {
    if (getTotalPrice() > priceTodeduction) {
        this->_isDiscountOrder = true;
        this->_priceToDeduction = priceTodeduction;
    }
}

double Order::getTotalPrice() {
    double totalPirce = 0;
    for (vector<LineItem*>::iterator it = _lineItems.begin(); it != _lineItems.end(); ++it)
        totalPirce += (*it)->getTotalPrice();
    return totalPirce;
}


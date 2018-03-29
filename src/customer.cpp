#include "../include/customer.h"
#include <iostream>

using std::cout;
using std::endl;

Customer::Customer(string name): _name(name), _bonusPoint(0) {

}

string Customer::name() const {
    return this->_name;
}

void Customer::addBonusPoint(unsigned int bonusPoint) {
    this->_bonusPoint = bonusPoint;
}

unsigned int Customer::getBonusPoint() {
    return this->_bonusPoint;
}

void Customer::notify(int total) {
    cout << "Calling" << endl;
    this->_bonusPoint += (total / 30);
}

void Customer::useBonusPoint() {
    cout << "Use Bonus Point" << endl;
    this->_bonusPoint -= 10;
    cout << "bonus point" << this->_bonusPoint << endl;
}

bool Customer::isEnoughBonusPoint() const {
    return this->_bonusPoint >= 10;
}


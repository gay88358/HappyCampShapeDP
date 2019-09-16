#include "../include/customer.h"


Customer::Customer(string name, string password):_name(name), _password(password) {
    this->_cash = 1000;
}

void Customer::deduction(int cashToDeduction) {
    if (this->_cash < cashToDeduction)
        throw std::invalid_argument("customer has no enough money to purchase");
    this->_cash -= cashToDeduction;
}

bool Customer::isCorrectPassword(string passwordToCheck) {
    return this->_password == passwordToCheck;
}

string Customer::getName() {
    return this->_name;
}

double Customer::getCash() {
    return this->_cash;    
}

void Customer::setCash(double cash) {
    this->_cash = cash;
}

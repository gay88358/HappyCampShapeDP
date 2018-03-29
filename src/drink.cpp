#include "../include/drink.h"
#include <iomanip>
#include <sstream>      // std::stringstream
#include <iostream>
using std::cout;

using std::endl;
Drink::Drink(string name, unsigned int calorie, unsigned int price): _name(name), _calorie(calorie), _price(price) {

}

string Drink::getDrinkDataString() const {    
    string calorie = std::to_string(this->_calorie);
    string price = std::to_string(this->_price);
    std::ostringstream oss;
    oss << this->_name << std::setw(20) << calorie << std::setw(20) << price;
    string result;
    result = oss.str();    
    
    return result;
}


string Drink::name() const {
    return this->_name;
}

unsigned int Drink::calorie() const {
    return this->_calorie;
}

unsigned int Drink::price() const {
    return this->_price;
}

bool Drink::isTheSameName(string name) const {
    return this->_name == name;
}

void Drink::setPrice(unsigned int price) {
    this->_price = price;
}

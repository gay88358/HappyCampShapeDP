#include "../include/clothes.h"
#include <sstream>
#include <iomanip>
#include "../include/utility.h"

int Clothes::currentId = 1;

void Clothes::resetCurrentId() {
    currentId = 1;
}

Clothes::Clothes() {
    
}

Clothes::Clothes(string name, string description, double price) {
    this->_name = name;
    this->_description = description;
    this->_price = price;
    this->_id = currentId++;
}

string Clothes::getName() {
    return this->_name;
}

string Clothes::getDescription() {
    return this->_description;
}

double Clothes::getPrice() {
    return this->_price;
}

int Clothes::getId() {
    return this->_id;
}

string Clothes::getInformation() {
    return std::to_string(this->_id) + "\t" + this->_name + "\t\t" + convertToPrecision(this->_price) + "\t" + this->_description + "\n";
}

string Clothes::convertToPrecision(double price) {
    return Utility::convertStringWithPrecision(price, 2);
}
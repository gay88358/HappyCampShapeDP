#include "../include/lineItem.h"
#include "../include/utility.h"

LineItem::LineItem(Clothes* clothes, int qty):_clothes(clothes), _qty(qty) {
}

double LineItem::getTotalPrice() {
    return this->_clothes->getPrice() * this->_qty;
}


string LineItem::getLineItemInformation() {
    return this->_clothes->getName() + "\t" + 
            std::to_string(this->_qty) + "\t" +
            convertToPrecision(this->_clothes->getPrice()) + "\t" + 
            convertToPrecision(getTotalPrice()) + "\n";
}


string LineItem::convertToPrecision(double price) {
    return Utility::convertStringWithPrecision(price, 2);
}
#include "../include/drinkLineItem.h"
#include <iostream>

using std::cout;
using std::endl;

DrinkLineItem::DrinkLineItem() {

}

void DrinkLineItem::addDrink(Drink *d) {
    this->_drinks.push_back(d);
}

Drink* DrinkLineItem::drinks(int index) {
    return this->_drinks[index];
}

int DrinkLineItem::drinkLength() const {
    return this->_drinks.size();
}


bool DrinkLineItem::isDrinkDuplicate(Drink *d) {
    return isTheSameNameInDrinks(d->name());
}

bool DrinkLineItem::isTheSameNameInDrinks(string name) const {
    int length = drinkLength();
    bool isDuplicate = false;
    for (int i = 0; i < length; i++) {
        if (this->_drinks[i]->isTheSameName(name)) {
            isDuplicate = true;
        }
    }
    return isDuplicate;
}

int DrinkLineItem::total() const {
    int length = drinkLength();
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += this->_drinks[i]->price();
    }
    return sum;
}

vector<Drink*> DrinkLineItem::drinkVector() {
    return this->_drinks;
}

string DrinkLineItem::assembleDrinkDataString() const {
    int length = drinkLength();
    string dataString;
    for (int i = 0; i < length; i++) {
        string str = this->_drinks[i]->getDrinkDataString();
        dataString = dataString + std::to_string(i+1) + "\t\t" + str + "\n";
    }
    dataString = dataString + "\t\t\t\t\t\t\t總金額= $" + std::to_string(total());
    return dataString;
}

void DrinkLineItem::setBonusDrink() {
    int length = drinkLength();
    int maxIndex = -999;
    int maxPrice = -999;
    for (int i = 0; i < length; i++) {
        int price = this->_drinks[i]->price();
        if (price > maxPrice) {
            maxPrice = price;
            maxIndex = i;
        }
    }
    cout << maxIndex << endl;
    this->_drinks[maxIndex]->setPrice(0);
}

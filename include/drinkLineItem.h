#ifndef DRINKLINEITEM_H
#define DRINKLINEITEM_H

#include "./drink.h"
#include <vector>

using std::vector;


class DrinkLineItem {
public:
    DrinkLineItem();
    void addDrink(Drink *d);
    Drink* drinks(int index);
    int drinkLength() const;
    bool isTheSameNameInDrinks(string name) const;
    vector<Drink*> drinkVector();
    int total() const;
    string assembleDrinkDataString() const;
    void setBonusDrink();
private:
    bool isDrinkDuplicate(Drink *d);
    vector<Drink*> _drinks;
};

#endif
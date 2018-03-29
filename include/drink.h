#ifndef DRINK_H
#define DRINK_H

#include <string>

using std::string;

class Drink {
public:
    Drink(string name, unsigned int calorie, unsigned int price);
    string getDrinkDataString() const;
    string name() const;
    unsigned int calorie() const;
    unsigned int price() const;
    void setPrice(unsigned int price);
    bool isTheSameName(string name) const;
private:
    string _name;
    unsigned int _calorie;
    unsigned int _price;
};

#endif
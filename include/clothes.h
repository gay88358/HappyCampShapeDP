#ifndef CLOTHES_H
#define CLOTHES_H

#include <string>

using std::string;

class Clothes {
public:
    static void resetCurrentId();
    static int currentId;
    Clothes();
    Clothes(string name, string description, double price);
    string getName();
    string getDescription();
    double getPrice();
    int getId();
    string getInformation();
private:
    string convertToPrecision(double);
    string _name;
    string _description;
    double _price;
    int _id;
};

#endif
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>

using std::string;

class Customer {
public:
    Customer(string name, string password);
    string getName();
    double getCash();
    void setCash(double cash);
    bool isCorrectPassword(string passwordToCheck);
    void deduction(int cashToDeduction);
private:
    string _name;
    string _password;
    double _cash;
};

#endif
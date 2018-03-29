#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "./observer.h"
using std::string;

class Customer : public Observer {
public:
    Customer(string name);
    string name() const;
    void addBonusPoint(unsigned int bonusPoint);
    unsigned int getBonusPoint();
    virtual void notify(int total);
    virtual void useBonusPoint();
    bool isEnoughBonusPoint() const;
private:
    unsigned int _id;
    string _name;
    unsigned int _bonusPoint;
};

#endif
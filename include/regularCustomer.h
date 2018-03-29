#ifndef REGULARCUSTOMER_H
#define REGULARCUSTOMER_H

#include "./customer.h"
#include <string>
using std::string;


class RegularCustomer : public Customer {
public:
    RegularCustomer(string name);
    // virtual void notify(int total);
    //virtual void useBonusPoint();
};

#endif
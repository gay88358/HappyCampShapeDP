#ifndef VIPCUSTOMER_H
#define VIPCUSTOMER_H

#include "./customer.h"
#include <string>
using std::string;

class VipCustomer : public Customer{
public:
    VipCustomer(string name);
};

#endif
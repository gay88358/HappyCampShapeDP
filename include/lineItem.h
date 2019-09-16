#ifndef LINEITEM_H
#define LINEITEM_H

#include "./clothes.h"

class LineItem {
public:
    LineItem(Clothes* clothes, int qty);
    double getTotalPrice();
    string getLineItemInformation();

private:
    string convertToPrecision(double price);
    Clothes* _clothes;
    int _qty;
};

#endif
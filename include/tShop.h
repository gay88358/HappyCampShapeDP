#ifndef TSHOP_H
#define TSHOP_H

#include "./customer.h"
#include "./order.h"
#include "./clothesCatalog.h"
#include "./history.h"
#include "./customerTracker.h"

class TShop {
public:
    TShop(string name);
    TShop();

    string getName();
    void makeNewOrder(Customer *customer);
    void enterItem(int id, int qty);
    void endOrder();
    History* findPurchasedHistoryOf(Customer*customer);
    bool isRegularCustomer(Customer *customer);
    void addNewClothes(string name, string description, double price);

    string getAllClothesInformation();
    string getCurrentOrderReceipt();
private:
    void resetCurrentOrder();
    void updateHistorys(Customer *customer);
    ClothesCatalog* _clothesCatalog;
    map<Customer*, History*> _historys;
    CustomerTracker* _tracker;

    string _name;
    Customer *_currentCustomer;
    Order* _currentOrder;
};

#endif
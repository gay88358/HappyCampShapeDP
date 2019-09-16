#ifndef CLOTHESCATALOG_H
#define CLOTHESCATALOG_H

#include "./clothes.h"
#include <map>

using std::map;

class ClothesCatalog {
public:
    ClothesCatalog();
    int getAmountOfClothes();
    Clothes* findClothesBy(int id);
    string getAllClothesInformation();
    void addNewClothes(string name, double price, string description);
    ~ClothesCatalog();

protected:
    void setClothes(map<int, Clothes*> clothes);
private:
    map<int, Clothes*> _clothes;
};

#endif
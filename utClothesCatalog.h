#ifndef UTCLOTHESCATALOG_H
#define UTCLOTHESCATALOG_H

#include "./include/clothesCatalog.h"
#include <iostream>

using std::cout;
using std::endl;

class ClothesCatalogTest : public ::testing::Test {
protected:
    
    virtual void SetUp() {
    }

    // You can define per-test tear-down logic as usual.
    virtual void TearDown() { 
        Clothes::resetCurrentId();
    }
};

class ClothesCatalogStub : public ClothesCatalog {
public:
    ClothesCatalogStub() {
        setClothes(createClothes());
    }

    map<int, Clothes*> createClothes() {
        Clothes::resetCurrentId();
        map<int, Clothes*> result;
        Clothes* c1 = new Clothes("hat", "a hat", 100);
        Clothes* c2 = new Clothes("t-shirt", "a t-shirt", 100);
        Clothes* c3 = new Clothes("pants", "a pants", 100);
        Clothes* c4 = new Clothes("socks", "a socks", 100);
        Clothes* c5 = new Clothes("hoodie", "a hoodie", 100);
        
        result[c1->getId()] = c1;
        result[c2->getId()] = c2;
        result[c3->getId()] = c3;
        result[c4->getId()] = c4;
        result[c5->getId()] = c5;

        return result;
    }

private:
};

TEST_F(ClothesCatalogTest, default_catalog_has_five_clothes) {
    ClothesCatalog *catalog = new ClothesCatalogStub();
    
    int number = 5;
    ASSERT_EQ(5, catalog->getAmountOfClothes());
}

TEST_F(ClothesCatalogTest, find_Clothes_by_id) {
    ClothesCatalog *catalog = new ClothesCatalogStub();

    Clothes* hat = catalog->findClothesBy(1); // hat
    Clothes* hoodie = catalog->findClothesBy(5); // hoodie
 
    ASSERT_EQ(1, hat->getId());
    ASSERT_EQ("hat", hat->getName());
    ASSERT_EQ("a hat", hat->getDescription());
    ASSERT_EQ(100, hat->getPrice());

    ASSERT_EQ(5, hoodie->getId());
    ASSERT_EQ("hoodie", hoodie->getName());
    ASSERT_EQ("a hoodie", hoodie->getDescription());
    ASSERT_EQ(100, hoodie->getPrice());
}

TEST_F(ClothesCatalogTest, add_new_clothes_to_catalog) {
    ClothesCatalog *catalog = new ClothesCatalogStub();

    string name = "";
    double price = 111.1;
    string description = "";
    catalog->addNewClothes(name, price, description);
    ASSERT_EQ(6, catalog->getAmountOfClothes());
}

#endif
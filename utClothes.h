#ifndef UTCLOTHES_H
#define UTCLOTHES_H

#include "./include/clothes.h"
#include <string>

using std::string;


class ClothesTest : public ::testing::Test {
protected:
    
    virtual void SetUp() {
    }

    Clothes* createClothes() {
        string name = "t-shirt";
        string description = "this is a t-shirt";
        double price = 133.3;
        Clothes *clothes = new Clothes(name, description, price);
        return clothes;
    }
    // You can define per-test tear-down logic as usual.
    virtual void TearDown() { 
        Clothes::resetCurrentId();
    }
};

TEST_F(ClothesTest, create_one_clothes) {
    // attribute: name, description, price
    Clothes *clothes = createClothes();
    ASSERT_EQ("t-shirt", clothes->getName());
    ASSERT_EQ("this is a t-shirt", clothes->getDescription());
    ASSERT_EQ(133.3, clothes->getPrice());
    ASSERT_EQ(1, clothes->getId());
}

TEST_F(ClothesTest, create_two_clothes_both_has_id_assigned) {
    Clothes *clothes1 = createClothes();
    Clothes *clothes2 = createClothes();

    ASSERT_EQ(1, clothes1->getId());
    ASSERT_EQ(2, clothes2->getId());
}

#endif
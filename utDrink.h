#ifndef UTDRINK_H
#define UTDRINK_H
#include <iostream>

using std::endl;
using std::cout;

#include "./include/drink.h"
#include "./include/drinkLineItem.h"

TEST(Drink, drink_constructor) {
    Drink *d = new Drink("南非國寶茶", 100, 25);
    ASSERT_EQ("南非國寶茶", d->name());
    ASSERT_EQ(100, d->calorie());
    ASSERT_EQ(25, d->price());
}

TEST(Drink, isTheSameName) {
    Drink *d = new Drink("南非國寶茶", 100, 25);
    ASSERT_TRUE(d->isTheSameName("南非國寶茶"));
    ASSERT_FALSE(d->isTheSameName("南國寶茶"));
    ASSERT_FALSE(d->isTheSameName("寶茶"));
}



TEST(Drink, drinkLineItem) {
    DrinkLineItem *dline = new DrinkLineItem();
    dline->addDrink(new Drink("南非國寶茶", 100, 25));
    Drink *d = dline->drinks(0);
    int length1 = dline->drinkLength();
    ASSERT_EQ("南非國寶茶", d->name());
    ASSERT_EQ(100, d->calorie());
    ASSERT_EQ(25, d->price());
    // repeat add is not allow
    dline->addDrink(new Drink("南非國寶茶", 100, 25));
    int length2 = dline->drinkLength();
    ASSERT_TRUE(length1 != length2);
}

TEST(Drink, drinkVector) {
    DrinkLineItem *dline = new DrinkLineItem();
    dline->addDrink(new Drink("南非國寶茶", 100, 25));
    dline->addDrink(new Drink("寶茶", 100, 25));
    vector<Drink*> v = dline->drinkVector();

    string name[] = { "南非國寶茶", "寶茶" };    
    for (int i = 0; i < v.size(); i++) {
        Drink *d = v[i];
        ASSERT_EQ(name[i], d->name());
    }
}

TEST(DrinkLineItem, isDuplicateName) {
    DrinkLineItem *dline = new DrinkLineItem();
    dline->addDrink(new Drink("南非茶", 100, 25));
    dline->addDrink(new Drink("南非國寶茶", 100, 25));

    cout << dline->assembleDrinkDataString() << endl;
    ASSERT_TRUE(dline->isTheSameNameInDrinks("南非茶"));
    ASSERT_FALSE(dline->isTheSameNameInDrinks("南茶"));
    ASSERT_TRUE(dline->isTheSameNameInDrinks("南非國寶茶"));
    ASSERT_FALSE(dline->isTheSameNameInDrinks("南非寶茶"));
}

TEST(Drink, dataString) {
    Drink *d = new Drink("南非國寶茶", 100, 25);
    cout << d->getDrinkDataString() << endl;
}

#endif
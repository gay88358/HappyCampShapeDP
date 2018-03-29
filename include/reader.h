#ifndef READER_H
#define READER_H

#include <sstream>
#include <fstream>
#include <string>
#include "drinkLineItem.h"
using std::string;

class Reader {
public:
    Reader(string fileName);
    void readFile();
    DrinkLineItem* getResultDrinkLineItem();
    void splitLineByComman(DrinkLineItem *dline, string line);
private:
    DrinkLineItem* _drinkLineItem = nullptr;
    string _fileName;
};

#endif
#include "../include/reader.h"
#include <iostream>

using std::cout;
using std::endl;

Reader::Reader(string fileName):_fileName(fileName), _drinkLineItem(new DrinkLineItem) {

}

void Reader::splitLineByComman(DrinkLineItem *dline, string line) {
    string segment;
    std::stringstream ss(line);
    vector<string> data;
    while(getline(ss, segment, ','))
        data.push_back(segment);

    dline->addDrink(new Drink(data[0], std::stoi(data[1]), std::stoi(data[2])));
}


void Reader::readFile() {
    string line;
    std::ifstream myfile (this->_fileName);
    if (myfile.is_open())
    {
        cout << "open file" << endl;
        while (getline (myfile,line))
        {
            splitLineByComman(_drinkLineItem, line);
        }
        myfile.close();
    }
}

DrinkLineItem* Reader::getResultDrinkLineItem() {
    return _drinkLineItem;
}
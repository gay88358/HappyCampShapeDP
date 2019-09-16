#include "../include/clothesCatalog.h"



ClothesCatalog::ClothesCatalog() {
    // vector<Clothes*> clothesToAdd;
    // clothesToAdd.push_back();
    Clothes* c1 = new Clothes("hat", "a hat", 100);
    Clothes* c2 = new Clothes("t-shirt", "a t-shirt", 100);
    Clothes* c3 = new Clothes("pants", "a pants", 100);
    Clothes* c4 = new Clothes("socks", "a socks", 100);
    Clothes* c5 = new Clothes("hoodie", "a hoodie", 100);
    
    this->_clothes[c1->getId()] = c1;
    this->_clothes[c2->getId()] = c2;
    this->_clothes[c3->getId()] = c3;
    this->_clothes[c4->getId()] = c4;
    this->_clothes[c5->getId()] = c5;
}

void ClothesCatalog::setClothes(map<int, Clothes*> clothes) {
    this->_clothes = clothes;
}


ClothesCatalog::~ClothesCatalog() {
    for(map<int, Clothes*>::iterator it = _clothes.begin(); it != _clothes.end() ; it++)
        delete (*it).second;
}

int ClothesCatalog::getAmountOfClothes() {
    return this->_clothes.size();   
}


void ClothesCatalog::addNewClothes(string name, double price, string description) {
    Clothes* clothesToAdd = new Clothes(name, description, price);
    this->_clothes[clothesToAdd->getId()] = clothesToAdd;
}

Clothes* ClothesCatalog::findClothesBy(int id) {

    if (_clothes.find(id)->second == nullptr) 
        throw std::invalid_argument("id of clothes: " + std::to_string(id) + " is not in the catalog");
    return _clothes.find(id)->second;
}

string ClothesCatalog::getAllClothesInformation() {
    string result = "";
    for(map<int, Clothes*>::iterator it = _clothes.begin(); it != _clothes.end() ; it++) {
        result +=  ((*it).second)->getInformation();
    } 
    return result;
}

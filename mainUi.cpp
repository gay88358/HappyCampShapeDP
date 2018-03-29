#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

//#include "./include/drinkLineItem.h"
//#include "./include/order.h"
//#include "./include/reader.h"
#include "./include/customer.h"
#include "./include/drinkShop.h"

using std::ifstream;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

void showFunctionality() {
    cout << "1.新增飲料" << endl;
    cout << "2.查看菜單" << endl;
    cout << "3.購買飲料" << endl;
    cout << "4.購買飲料收據" << endl;
    cout << "5.查看點數" << endl;
    cout << "6.查詢購買飲料的歷史收據" << endl;
    cout << "7.結束程式" << endl;
}

template<typename T>
T validInput(string errorMessage) {
    T number;
    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        if (ss >> number)
            if (ss.eof())
                break;
        cout << errorMessage << endl;
    }
    return number;
}

unsigned int inputData(string hint, string errorMessage) {
    cout << hint << endl;
    unsigned int data;
    data = validInput<unsigned int>(errorMessage);
    return data;
}

unsigned int inputCalorie() {
    return inputData("輸入飲料卡路里", "輸入卡路里錯誤，請重新輸入！");
}

unsigned int inputPrice() {
    return inputData("輸入飲料價格", "輸入飲料價格錯誤，請重新輸入！");
}

int validInputDrink(int range) {
    int number;
    string line;
    while (getline(cin, line))
    {
        stringstream ss(line);
        if (ss >> number)
            if (ss.eof()) 
                if ((number >= 0 && number < range) || number == -1)
                    break;        
        cout << "輸入飲料編號錯誤，請重新輸入！" << endl;
    }
    return number;
}

void LookBonusPoint(Customer* c) {
    int bonusPoint = c->getBonusPoint();
    cout << "您的點數為：" << bonusPoint << endl;
}

string inputDrinkName(DrinkShop *shop) {
    cout << "輸入飲料名稱" << endl;
    string name = validInput<string>("");
    while (shop->isTheSameNameInDrinks(name)) {
        cout << "此飲料已經存在，請再重新輸入新的飲料名稱" << endl;
        name = validInput<string>("");
    }
    return name;
}

void handleAddingDrink(DrinkShop *shop) {
    string drinkName = inputDrinkName(shop);
    unsigned int calorie = inputCalorie();
    unsigned int price = inputPrice();
    shop->addDrink(drinkName, calorie, price);
}

void showAllDrinks(DrinkShop *shop) {
    vector<string> menu = shop->getMenu();
    cout << "No." << "\t\t" <<  "飲料名稱" << "\t\t" << "卡路里" << "\t\t" << "價格" << endl;
    for (int i = 0; i < menu.size(); i++) {
        cout << std::to_string(i) << "\t\t"  << menu[i] << endl;
    }
}

void purchaseDrink(DrinkShop *shop) {
    vector<Drink*> drinkList = shop->getDrinks();
    while (1) {
        showAllDrinks(shop);
        cout << "請輸入想買的飲料編號，假如不買了，請輸入-1" << endl;
        int choice = validInputDrink(drinkList.size());
        if (choice == -1) break;
        shop->addDrinkToOrder(drinkList[choice]);
    }
}

void showReceipt(DrinkShop *drinkShop) {
    Order *order = drinkShop->currentOrder();
    if (order->isEmpty()) {
        cout << "並未購買飲料，請先購買飲料" << endl;
    } else {
        if (drinkShop->isEnoughBonusPoint()) {
            cout << "需不需要使用點數換取飲料？(Y/N)" << endl;
            string choice;
            cin >> choice;
            cin.ignore();
            if (choice == "Y") {
                order->setBonusDrink();
            }
        }
        drinkShop->endOrder();
        cout << "No." << "\t\t" <<  "飲料名稱" << "\t\t" << "卡路里" << "\t\t" << "價格" << endl;
        cout << order->receipt() << endl;
    }
}

void LookHistoryReceipt(DrinkShop *drinkShop) {
    string result = "";
    vector<Order*> historyOrder = drinkShop->getOrderVector();
    for (int i = 0; i < historyOrder.size() - 1; i++) {
        string title = "購買收據 " + std::to_string(i + 1) + "\n";
        string subTitle = "NO.\t\t飲料名稱\t\t卡路里\t\t價格\n";
        string header = title + subTitle; 
        result = result + header + historyOrder[i]->receipt() + "\n";
    }
    cout << result << endl;
//    cout << drinkShop->getReceipt() << endl;
}

int main() {
    Customer *c = new Customer("Z-Xuan Hong");
    DrinkShop *drinkShop = new DrinkShop("711");
    drinkShop->createNewOrder(c);

    while(1) {
        showFunctionality();
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            handleAddingDrink(drinkShop);
        } else if (choice == 2) {
            showAllDrinks(drinkShop);
        } else if (choice == 3) {
            purchaseDrink(drinkShop);
        } else if (choice == 4) {
            showReceipt(drinkShop);
        } else if (choice == 5) {
            LookBonusPoint(c);
        } else if (choice == 6) {
            LookHistoryReceipt(drinkShop);
        } else if (choice == 7) {
            break;
        }
    }
    return 0;
}
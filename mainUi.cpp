#include <iostream>
#include <string>
#include <sstream>
#include <utility>      // std::pair, std::make_pair


#include "./include/shopFactory.h"

using std::pair;
using std::stringstream;
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::getline;

void displayUserInterface() {
    cout << "1.新增飲料" << endl;
    cout << "2.查看菜單" << endl;
    cout << "3.購買飲料" << endl;
    cout << "4.購買飲料收據" << endl;
    cout << "5.查看點數" << endl;
    cout << "6.查詢購買飲料的歷史收據" << endl;
    cout << "7.回上一頁" << endl;
}

void handleSystemCommand(DrinkShop *drinkShop) {
    
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

int validInputDrinkIndex(int range) {
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

unsigned int inputData(string hint, string errorMessage) {
    cout << hint << endl;
    unsigned int data;
    data = validInput<unsigned int>(errorMessage);
    return data;
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

void addingDrinkToMenuList(DrinkShop *shop) {
    string drinkName = inputDrinkName(shop);
    unsigned int calorie = inputData("輸入飲料卡路里", "輸入卡路里錯誤，請重新輸入！");
    unsigned int price = inputData("輸入飲料價格", "輸入飲料價格錯誤，請重新輸入！");
    shop->addDrinkToMenu(drinkName, calorie, price);
}

void showDrinkMenu(DrinkShop *shop) {
    vector<string> menu = shop->getMenu();
    cout << "No." << "\t\t" <<  "飲料名稱" << "\t\t" << "卡路里" << "\t\t" << "價格" << endl;
    for (int i = 0; i < menu.size(); i++) {
        cout << std::to_string(i) << "\t\t"  << menu[i] << endl;
    }
}

void purchaseDrink(DrinkShop *shop) {
    vector<Drink*> drinkList = shop->getDrinks();
    while (1) {
        showDrinkMenu(shop);
        cout << "請輸入想買的飲料編號，假如不買了，請輸入-1" << endl;
        int choice = validInputDrinkIndex(drinkList.size());
        if (choice == -1) break;
        shop->addDrinkToOrder(drinkList[choice]);
    }
}

void checkBonusPoint(Customer* c) {
    int bonusPoint = c->getBonusPoint();
    cout << "您的點數為：" << bonusPoint << endl;
}

void handleBonusApplicability(Order *order) {
    cout << "需不需要使用點數換取飲料？(Y/N)" << endl;
    string choice;
    cin >> choice;
    cin.ignore();
    if (choice == "Y") 
        order->setBonusDrink();
} 

void handleReceiptManufacture(DrinkShop *drinkShop) {
    Order *order = drinkShop->currentOrder();
    if (drinkShop->isEnoughBonusPoint())
        handleBonusApplicability(order);
    drinkShop->endOrder();
    cout << "No." << "\t\t" <<  "飲料名稱" << "\t\t" << "卡路里" << "\t\t" << "價格" << endl;
    cout << order->receipt() << endl;
}

void createReceipt(DrinkShop *drinkShop) {
    Order *order = drinkShop->currentOrder();
    if (order->isEmpty()) {
        cout << "並未購買飲料，請先購買飲料" << endl;
    } else {
        handleReceiptManufacture(drinkShop);
    }
}

void showHistoryReceipt(DrinkShop *drinkShop) {
    string result = "";
    vector<Order*> historyOrder = drinkShop->getOrderVector();
    for (int i = 0; i < historyOrder.size() - 1; i++) {
        string title = "購買收據 " + std::to_string(i + 1) + "\n";
        string subTitle = "NO.\t\t飲料名稱\t\t卡路里\t\t價格\n";
        string header = title + subTitle;        
        result = result + header + historyOrder[i]->receipt() + "\n";
    }
    cout << result << endl;
}

void initailizeDrinkShopWithCustomer(vector<DrinkShop*> &drinkShops) {
    ShopFactory *factory = new ShopFactory();
    vector<pair<string, string>> shopData = { pair<string, string>("Jack(VIP)", "ForJack"), 
                                              pair<string, string>("Adela(VIP)", "ForAdela"),
                                              pair<string, string>("Alice", "ForAlice"),
                                              pair<string, string>("Jeff", "ForJeff"),
                                              pair<string, string>("Justin", "ForJustin"), };
    for (int i = 0; i < 2; i++)
        drinkShops.push_back(factory->createVipDrinkShop(shopData[i].first));

    for (int i = 2; i < shopData.size(); i++)
        drinkShops.push_back(factory->createRegularShop(shopData[i].first));
}

void displayCustomer(vector<DrinkShop*> drinkShops) {
    int length = drinkShops.size();
    for (int i = 0; i < length; i++) 
        cout << std::to_string(i+1) << " ." << drinkShops[i]->customerName() << endl;
    cout << std::to_string(length + 1) << ".結束程式" << endl;
}

void serviceCustomer(DrinkShop *drinkShop) {
    while(1) {
        displayUserInterface();
        int choice;
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            addingDrinkToMenuList(drinkShop);
        } else if (choice == 2) {
            showDrinkMenu(drinkShop);
        } else if (choice == 3) {
            purchaseDrink(drinkShop);
        } else if (choice == 4) {
            createReceipt(drinkShop);
        } else if (choice == 5) {
            checkBonusPoint(drinkShop->customer());
        } else if (choice == 6) {
            showHistoryReceipt(drinkShop);
        } else if (choice == 7) {
            break;
        }
    }
}

int main() {
    vector<DrinkShop*> drinkShops;
    initailizeDrinkShopWithCustomer(drinkShops);
    int selectedIndex = 0;
    while (1) {
        displayCustomer(drinkShops);
        cin >> selectedIndex;
        cin.ignore();
        if (selectedIndex == 6)
            break;
        serviceCustomer(drinkShops[selectedIndex - 1]);
    }
    return 0;
}
#include <iostream>
#include <string>
#include "./include/tShop.h"
#include <stdlib.h>     /* abs */
#include <sstream>
using std::string;
using std::cout;
using std::endl;
using std::cin;
using std::stringstream;

void displayCustomerGreeting(TShop *tShop, Customer *customer) {
    if (!tShop->isRegularCustomer(customer))
        cout << "親愛的顧客: " << customer->getName() << "，您好!" << endl;
    else {
        cout << "老客戶: " << customer->getName() << "，您好！" << endl;
        cout << "您每次購買都享有9折優惠" << endl;
    }
}

void displayUserInterface(TShop *tShop) {

    string shopDecorator = "(" + tShop->getName() + ")";
    cout << shopDecorator << "1.新增衣服" << endl;
    cout << shopDecorator << "2.查看所有衣服" << endl;
    cout << shopDecorator << "3.建立新訂單" << endl;
    cout << shopDecorator << "4.購買衣服" << endl;
    cout << shopDecorator << "5.結束訂單" << endl;
    cout << shopDecorator << "6.查看剩餘點數" << endl;
    cout << shopDecorator << "7.查看歷史收據" << endl;
    cout << shopDecorator << "8.離開店家" << endl;
}



string enterChoice() {
    string choice;
    while(true) {
        cin >> choice;
        if (choice != "1" &&
            choice != "2" &&
            choice != "3" &&
            choice != "4" &&
            choice != "5" &&
            choice != "6" &&
            choice != "7" &&
            choice != "8") {
            cout << "請輸入正確選項: " << endl;
            continue;
        }
        break;
    }
    return choice;
}

bool is_digits(const std::string &str)
{
    string s;
    if (str[0] == '-')
        s = str.substr(1, str.size());
    else
        s = str;

    return std::all_of(s.begin(), s.end(), ::isdigit); // C++11
}

int enterNumber(string title, string errorMessage) {
    int id = -1;
    while (true) {
        cout << title;
        string input;
        cin >> input;
        if (!is_digits(input)) {
            cout << errorMessage << endl;
            continue;
        }
        id = std::atoi (input.c_str());
        break;
    }
    return id;
}

int enterId() {
    return enterNumber("請輸入衣服ID, 離開請輸入-1: ",  "數量只能為整數, 請重新輸入");
}

int enterQty() {
    int qty = 0;
    while(true) {
        qty = enterNumber("請輸入衣服數量: ",  "數量只能為整數, 請重新輸入");
        if (qty > 0)
            break;
        cout << "數量一定要大於0" << endl;
    }
    return qty;
}

string enterString() {
    string str;
    cin >> str;
    return str;
}

string enterName() {
    cout << "請輸入衣服名稱: ";
    return enterString();
}

string enterDescription() {
    cout << "請輸入衣服描述: ";
    return enterString();
}

bool isOnlyDouble(const char* str)
{
    char* endptr = 0;
    strtod(str, &endptr);
    if(*endptr != '\0' || endptr == str)
        return false;
    return true;
}

double enterDouble() {
    double d;
    cin >> d;
    return d;
}

double enterPrice() {
    cout << "請輸入價格: ";
    return enterDouble();
}

void displayClothesCatalog(TShop *tShop) {
    string information = tShop->getAllClothesInformation();
    cout << "No.\t衣服名稱\t價格\t描述" << endl;
    cout << information << endl;
}

void makeNewOrder(TShop *tShop, Customer *customer) {
    tShop->makeNewOrder(customer);
    cout << "成功建立新訂單!!!" << endl;
}

void finishOrder(TShop *tShop) {
    try {
        tShop->endOrder();
        cout << "名稱\t數量\t單價\t總價" << endl;
        cout << tShop->getCurrentOrderReceipt() << endl;
    } catch(const std::invalid_argument &e) {
        cout << e.what() << endl;
    }
}


void displayHistory(TShop *tShop, Customer *customer){
    History *history = tShop->findPurchasedHistoryOf(customer);
    cout << customer->getName() << "的歷史購買紀錄: " << endl;
    cout << "名稱\t數量\t單價\t總價" << endl;
    cout << history->getAllRecordInformation() << endl;
}

void displayCustomerPoints(Customer *customer) {
    cout << "您剩餘的點數剩下:" << std::to_string(customer->getCash()) << endl;
}

void purchaseClothes(TShop *tShop) {
    displayClothesCatalog(tShop);

    while(true) {
        int id = enterId();
        if (id == -1)
            break;
        
        int qty = enterQty();

        try {
            tShop->enterItem(id, qty);
        } catch (std::invalid_argument &e) {
            cout << e.what() << endl;
        }
    }
}

void addNewClothesTo(TShop *tShop) {
    string name = enterName();
    string description = enterDescription();
    double price = enterPrice();
    tShop->addNewClothes(name, description, price);
}

vector<Customer*> createCustomers() {
    vector<Customer*> customers;
    Customer *john = new Customer("Amber", "1010");
    Customer *marry = new Customer("Bember", "1010");
    Customer *tom = new Customer("Comber", "1010");
    customers.push_back(john);
    customers.push_back(marry);
    customers.push_back(tom);
    return customers;
}

vector<TShop*> createTShops() {
    TShop *uniqlo = new TShop("UNIQLO");
    TShop *hm = new TShop("H&M");
    TShop *zara = new TShop("ZARA");
    
    vector<TShop*> tShops;
    tShops.push_back(uniqlo);
    tShops.push_back(hm);
    tShops.push_back(zara);
    return tShops;
}

void servingForCustomer(TShop* tShop, Customer* customer) {
    while(true) {
        displayCustomerGreeting(tShop, customer);
        displayUserInterface(tShop);

        cout << "請輸入選擇: ";
        string choice = enterChoice();

        if (choice == "8")
            break;

        if (choice == "1") {
            addNewClothesTo(tShop);
        } else if (choice == "2") {
            displayClothesCatalog(tShop);
        } else if (choice == "3") {
            makeNewOrder(tShop, customer);
        } else if (choice == "4") {
            purchaseClothes(tShop);
        } else if (choice == "5") {
            finishOrder(tShop);
        } else if (choice == "6") {
            displayCustomerPoints(customer);
        } else if (choice == "7") {
            displayHistory(tShop, customer);
        }
    }
}

void display(vector<Customer*> customers) {
    for (int i = 0; i < customers.size(); i++)
        cout << std::to_string(i + 1) << "." << customers[i]->getName() << endl;
    cout << "4.離開" << endl;
}

void display(vector<TShop*> tShops) {
    for (int i = 0; i < tShops.size(); i++)
        cout << std::to_string(i + 1) << "." << tShops[i]->getName() << endl;
}

Customer* select(vector<Customer*> customers) {
    int customerIndex = enterNumber("select customer: ", "please enter integer");
    return customers[customerIndex - 1];
}

int enterTShopIndex(vector<TShop*> tShops) {
    int shopIndex;
    while(true) {
        shopIndex = enterNumber("select TShop: ", "please enter integer");

        if (shopIndex >= 0 && shopIndex <= tShops.size())
            break;
        cout << "請選擇畫面上的店家" << endl;
    }

    return shopIndex;    
}

int enterCustomerIndex(vector<Customer*> customers) {
    int customerIndex;
    while(true) {
        customerIndex = enterNumber("select customer: ", "please enter integer");

        if (customerIndex >= 0 && customerIndex <= customers.size() + 1)
            break;
        cout << "請選擇畫面上的顧客或是離開" << endl;
    }

    return customerIndex;
}

Customer* selectCurrentCustomerFrom(vector<Customer*> customers, int customerIndex) {
    return customers[customerIndex - 1];
}

TShop* selectCurrentTShopFrom(vector<TShop*> tShops, int tShopIndex) {
    return tShops[tShopIndex - 1];
}

int main( int argc , char **argv )
{    
    vector<Customer*> customers = createCustomers();
    vector<TShop*> tShops = createTShops();

    while(true) {
        display(customers);
        int customerIndex = enterCustomerIndex(customers);
        if (customerIndex == 4)
            break;
        Customer *currentCustomer = selectCurrentCustomerFrom(customers, customerIndex);

        display(tShops);
        int tShopIndex = enterTShopIndex(tShops);
        TShop *currentTShop = selectCurrentTShopFrom(tShops, tShopIndex);

        servingForCustomer(currentTShop, currentCustomer);
    }
    return 0;
}

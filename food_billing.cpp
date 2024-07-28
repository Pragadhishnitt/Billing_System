#include <bits/stdc++.h>
#include <unistd.h>  
using namespace std;

class FoodItem {
private:
    string name;
    int price, quantity;
public:
    FoodItem() : name(""), price(0), quantity(0) { }

    FoodItem(string n, int p, int q) : name(n), price(p), quantity(q) { }

    void setName(string n) {
        name = n;
    }

    void setPrice(int p) {
        price = p;
    }

    void setQuantity(int q) {
        quantity = q;
    }

    string getName() const {  
        return name;
    }

    int getPrice() const { 
        return price;
    }

    int getQuantity() const {  
        return quantity;
    }
};

void addItem(vector<FoodItem>& cart) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Add Food Item." << endl;
        cout << "\t2. Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("clear");
            string item;
            int price, quant;

            cout << "\tEnter Food Item Name: ";
            cin >> item;

            cout << "\tEnter Price of Item: ";
            cin >> price;

            cout << "\tEnter Quantity: ";
            cin >> quant;

            cart.push_back(FoodItem(item, price, quant));
            cout << "\tFood Item Added Successfully" << endl;
            sleep(3);
        } else if (choice == 2) {
            system("clear");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            sleep(3);
        }
    }
}

void removeItem(vector<FoodItem>& cart) {
    bool close = false;
    while (!close) {
        int choice;
        cout << "\t1. Remove Food Item." << endl;
        cout << "\t2. Close." << endl;
        cout << "\tEnter Choice: ";
        cin >> choice;

        if (choice == 1) {
            system("clear");
            string item;
            cout << "\tEnter Food Item Name to Remove: ";
            cin >> item;

            auto it = remove_if(cart.begin(), cart.end(), [&item](const FoodItem& food) {
                return food.getName() == item;
            });

            if (it != cart.end()) {
                cart.erase(it, cart.end());
                cout << "\tFood Item Removed Successfully" << endl;
            } else {
                cout << "\tFood Item Not Found" << endl;
            }
            sleep(3);
        } else if (choice == 2) {
            system("clear");
            close = true;
            cout << "\tBack To Main Menu!" << endl;
            sleep(3);
        }
    }
}

void viewCart(const vector<FoodItem>& cart) {
    system("clear");
    if (cart.empty()) {
        cout << "\tYour cart is empty." << endl;
    } else {
        cout << "\tYour Cart:" << endl;
        cout << "\tName\t\tPrice\tQuantity" << endl;
        for (const auto& item : cart) {
            cout << "\t" << item.getName() << "\t\t" << item.getPrice() << "\t" << item.getQuantity() << endl;
        }
    }
    sleep(5);
}

void checkout(const vector<FoodItem>& cart) {
    system("clear");
    int total = 0;
    cout << "\tCheckout" << endl;
    cout << "\tName\t\tPrice\tQuantity\tAmount" << endl;
    for (const auto& item : cart) {
        int amount = item.getPrice() * item.getQuantity();
        total += amount;
        cout << "\t" << item.getName() << "\t\t" << item.getPrice() << "\t" << item.getQuantity() << "\t\t" << amount << endl;
    }
    cout << "\tTotal Amount: " << total << endl;
    sleep(5);
}

int main() {
    vector<FoodItem> cart;

    bool exit = false;
    while (!exit) {
        system("clear");
        int val;

        cout << "\tWelcome To Food App Billing System" << endl;
        cout << "\t**********************************" << endl;
        cout << "\t\t1. Add Food Item to Cart." << endl;
        cout << "\t\t2. Remove Food Item from Cart." << endl;
        cout << "\t\t3. View Cart." << endl;
        cout << "\t\t4. Checkout." << endl;
        cout << "\t\t5. Exit." << endl;
        cout << "\t\tEnter Choice: ";
        cin >> val;

        if (val == 1) {
            system("clear");
            addItem(cart);
            sleep(3);
        } else if (val == 2) {
            system("clear");
            removeItem(cart);
            sleep(3);
        } else if (val == 3) {
            viewCart(cart);
        } else if (val == 4) {
            checkout(cart);
        } else if (val == 5) {
            system("clear");
            exit = true;
            cout << "\tGood Luck!" << endl;
            sleep(3);
        }
    }
}

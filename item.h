#ifndef ITEM_H
#define ITEM_H
#include <string>

using namespace std;

class item {
    private:
        string name;
        int price;
        double boost;

    public:
        item(); // Default constructor
        item(string name, int price, double boost); // Constructor
        string get_name(); // Returns name of item
        int get_price(); // Returns price of item
        double get_boost(); // Returns boost of item
};
#endif 
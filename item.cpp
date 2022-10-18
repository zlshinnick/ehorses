#include "item.h"
    
    item::item() { // Default constructor
        name = "";
        price = 0;
        boost = 0;
    }

    item::item(string name, int price, double boost) { // Constructor
        this->name=name;
        this->price=price;
        this->boost = boost;
    }

    string item::get_name() { // Returns name of item
        return name;
    }
    
    int item::get_price() { // Returns price of item
        return price;
    }

    double item::get_boost() { // Returns boost of item
        return boost;
    }
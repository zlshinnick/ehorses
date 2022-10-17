#include "item.h"
    
    item::item(){
        name = "";
        price = 0;
        boost =0;
    }

    item::item(string name, int price, double boost){
        this->name=name;
        this->price=price;
    }

    string item::get_name(){
        return name;
    }
    int item::get_price(){
        return price;
    }
    double item::get_boost(){
        return boost;
    }
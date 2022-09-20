#include "item.h"

item::item(string name, int level, int price, int rarity ){
    this->name = name;
    this->level = level;
    this->price = price;
    this->rarity = rarity;


}

//accessors
string item::get_name(){return name;}
int item::get_level(){return level;}
int item::get_price(){return price;}
int item::get_rarity(){return rarity;}
#pragma once

#include <iostream>
#include <string>
using namespace std;


class item{
    private:
        string name;
        int level;
        int price;
        int rarity;

    public: 
     item(string name = "NONE", int level = 0, int price = 0, int rarity =0);

    //accessors
    string get_name();
    int get_level();
    int get_price();
    int get_rarity();

    //modifiers


};
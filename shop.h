#ifndef SHOP_H
#define SHOP_H
#include <string>
#include "item.h"
#include <iostream>

using namespace std;

class shop {
    private:
        item items[3];
        int num_items;
    public:
        shop(); // Default constructor
        void initialize(item item1, item item2, item item3); // Function to initialise shop items
        item get_item(); // Function to get an item from the shop
        void print_store(); // Function to print the shop
        void ascii_shop(); // Function to print ascii shop
};

#endif 
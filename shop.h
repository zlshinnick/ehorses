#ifndef SHOP_H
#define SHOP_H
#include <string>
#include "item.h"
#include <iostream>

using namespace std;

class shop{
    private:
        item items[3];
        int num_items;
    public:
        shop();
        void initialize(item item1, item item2, item item3);
        item get_item();
        void print_store();

};

#endif 
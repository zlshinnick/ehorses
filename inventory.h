#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"
class inventory{
    private:
        item* user_inventory;
        int num_of_items;

    public:
        inventory();
        void add_item(item item);
        void print_inventory();
        int get_num_items(){return num_of_items;}

};
#endif
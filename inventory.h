#ifndef INVENTORY_H
#define INVENTORY_H
#include "item.h"

class inventory {
    private:
        item* user_inventory;
        int num_of_items;

    public:
        inventory(); // Default constructor
        void add_item(item item); // Adds item to inventory
        void remove_item(int index); // Removes item from inventory
        void print_inventory(); // Prints inventory
        int get_num_items(){return num_of_items;} // Returns number of items in inventory
        item select_boost(); // Selects boost from inventory
};
#endif
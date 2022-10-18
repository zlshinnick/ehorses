#include "inventory.h"
#include "shop.h"
#include <thread>
#include <iostream>

inventory::inventory() { // Inventory constructor
    user_inventory = new item[10];
    num_of_items = 0;
}

void inventory::add_item(item item) { // Adds item to inventory
    user_inventory[num_of_items] = item;
    num_of_items++;
    cout << "\n" << item.get_name() << " Succesfully Added To Inventory\n" << endl;
    this_thread::sleep_for(chrono::seconds(1)); // Delays for 1 second
}

void inventory::remove_item(int index) { // Removes item from inventory
    user_inventory[index] = item();
}

void inventory::print_inventory() { // Prints inventory

    if (num_of_items == 0) {
        cout << "\nInventory Is Empty!\n";
        cout << "Visit General Store To Buy Boosts" << endl;
        return; // Terminates code if inventory is empty
    } else {
        bool empty;
        for (int i = 0 ; i < num_of_items; i++){
            if (user_inventory[i].get_name() != ""){
                empty = false;
            }
        }
        cout << "**Inventory**\n\n";
    
        int tracker = 0;
        if (empty == false) {
            for (int i = 0; i < num_of_items; i++) {

                if (user_inventory[i].get_name() != "") {
                    cout << tracker << "." << user_inventory[i].get_name() << endl << endl;
                    tracker++;
                }
            
            }
        } else {
            cout << "\nInventory Is Empty!";
            cout << "\nVisit General Store To Buy Boosts"; // No return needed because end of function
        }
    }
}

item inventory::select_boost() { // Selects boost from inventory
        print_inventory();
        cout << "9. Continue" << endl;
        int item_choice;

        cout << "Choice: ";
        cin >> item_choice;
        if (item_choice == 9){
            return item();
        }

        item temp = user_inventory[item_choice];
        remove_item(item_choice);
        return temp;
}
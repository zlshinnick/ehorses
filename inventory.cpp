#include "inventory.h"
#include "shop.h"
#include <thread>
#include <iostream>

inventory::inventory(){
    user_inventory= new item[10];
    num_of_items=0;
}

void inventory::add_item(item item){
    user_inventory[num_of_items]=item;
    num_of_items++;
    cout<<"\n"<<item.get_name()<<" Succesfully Added To Inventory"<<endl<<endl;
    this_thread::sleep_for(chrono::seconds(1));
}

void inventory::remove_item(int index){
    user_inventory[index] = item();
}

void inventory::print_inventory(){

    if(num_of_items==0){
        cout<<"\nInventory Is Empty!";
        cout<<"\n Visit General Store To Buy Boosts";
        return;
    }else{
        bool empty;
        for(int i =0 ; i<num_of_items; i++){
            if(user_inventory[i].get_name()!=""){
                empty = false;
            }
        }
        cout<<"**Inventory** \n \n";
    
        int tracker = 0;
        if(empty ==false){
            for(int i =0; i<num_of_items;i++){

                if(user_inventory[i].get_name()!=""){
                    cout<<tracker<<"."<<user_inventory[i].get_name()<<endl<<endl;
                    tracker++;
                }
            
            }
        } else {
            cout<<"\nInventory Is Empty!";
            cout<<"\nVisit General Store To Buy Boosts";
        }
    }
}

item inventory::select_boost(){
        print_inventory();
        int item_choice;

        cout<<"Select Boost: ";
        cin>>item_choice;

        item temp =  user_inventory[item_choice];

        remove_item(item_choice);
        return temp;
}
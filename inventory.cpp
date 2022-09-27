#include "inventory.h"
#include "shop.h"
inventory::inventory(){
    user_inventory= new item[10];
    num_of_items=0;
}

void inventory::add_item(item item){
    user_inventory[num_of_items]=item;
    num_of_items++;
    cout<<item.get_name()<<" Succesfully Added To Inventory"<<endl<<endl;
}

void inventory::print_inventory(){

    if(num_of_items==0){
        cout<<"Inventory Is Empty"<<endl;
        return;
    }
    for(int i =0; i<num_of_items;i++){
        cout<<"**Inventory** \n \n";
        cout<<"Name: "<<user_inventory[i].get_name()<<endl<<endl;

    }
}
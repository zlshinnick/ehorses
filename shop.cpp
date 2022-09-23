#include "shop.h"

shop::shop(){
    num_items=3;

}

void shop::initialize(item item1, item item2, item item3){
    this->items[0] = item1;
    this->items[1] = item2;
    this->items[2] = item3;

}

item shop::get_item(string name){
    for(int i =0; i< num_items; i++){
        if(name == items[i].get_name()){
            return items[i];
        }
    }
}

void shop::print_store(){
    cout<<"**WELCOME TO THE SHOP**"<<endl<<endl;
    for (int i =0; i<num_items;i++){
        cout<<"Item: "<<items[i].get_name()<<endl;
        cout<<"Price: "<<items[i].get_price()<<endl;
        cout<<endl;
    }
}
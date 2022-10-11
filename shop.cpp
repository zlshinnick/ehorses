#include "shop.h"
#include <chrono>
#include <thread>
shop::shop(){
    num_items=3;

}

void shop::initialize(item item1, item item2, item item3){
    this->items[0] = item1;
    this->items[1] = item2;
    this->items[2] = item3;

}

void shop::print_store(){
    cout<<"\n** Welcome To The Shop **";

       this_thread::sleep_for(chrono::seconds(2));    

    for (int i =0; i<num_items;i++){
        cout<<"\nItem: "<<items[i].get_name()<<endl;
        cout<<"Price: "<<items[i].get_price()<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

item shop::get_item(){
    cout<<"Which Item Would You Like To Purchase?"<<endl;
    int choice_item;
    cout<<"0: Carrot"<<endl;
    cout<<"1: Sugar Cubes"<<endl;
    cout<<"3: Saddle"<<endl;
    cout<<"9: None"<<endl<<endl;
    cout<<"Item To Purchase: ";
    cin>>choice_item;

    while(choice_item != 0 && choice_item != 1 && choice_item != 2 && choice_item != 3&&choice_item != 4 && choice_item != 9){
        cout<<"\nInvalid Input!"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"Item To Purchase: ";
        cin>>choice_item;
    }

    return items[choice_item];

}
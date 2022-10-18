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
    ascii_shop();
    cout<<"\n\n** These are the Items For Sale **\n\n";
    for (int i =0; i<num_items;i++){
        cout<<"\nItem: "<<items[i].get_name()<<endl;
        cout<<"Price: "<<items[i].get_price()<<endl;
        cout<<endl;
        this_thread::sleep_for(chrono::seconds(1));
    }
}

item shop::get_item(){
    cout<<"\n\nWhich Item Would You Like To Purchase?"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    int choice_item;
    cout<<"0: Carrot(boost = 0.5 seconds)"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"1: Sugar (boost = 1 seconds)"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"2: Apple (boost = 2 seconds)"<<endl;
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"9: None";
    this_thread::sleep_for(chrono::seconds(1));
    cout<<"\n\nItem To Purchase: ";
    cin>>choice_item;

    if(choice_item==9){
        return item();
    }

    while(choice_item != 0 && choice_item != 1 && choice_item != 2 && choice_item != 9){
        cout<<"\nInvalid Input!"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"Item To Purchase: ";
        cin>>choice_item;
        num_items++;
    }

    return items[choice_item];

}

void shop::ascii_shop(){
    system("Clear");
    cout<<" /$$$$$$$                                  /$$            /$$$$$$   /$$   "<<endl;
    cout<<"| $$__  $$                                | $$           /$$__  $$ | $$   "<<endl;
    cout<<"| $$  | $$  /$$$$$$   /$$$$$$   /$$$$$$$ /$$$$$$        | $$  |__//$$$$$$    /$$$$$$   /$$$$$$   /$$$$$$ "<<endl;
    cout<<"| $$$$$$$  /$$__  $$ /$$__  $$ /$$_____/|_  $$_/        |  $$$$$$|_  $$_/   /$$__  $$ /$$__  $$ /$$__  $$ "<<endl;
    cout<<"| $$__  $$| $$  | $$| $$  | $$|  $$$$$$   | $$           |____  $$ | $$    | $$  | $$| $$  |__/| $$$$$$$$ "<<endl;
    cout<<"| $$  | $$| $$  | $$| $$  | $$ |____  $$  | $$ /$$       /$$  | $$ | $$ /$$| $$  | $$| $$      | $$_____/ "<<endl;
    cout<<"| $$$$$$$/|  $$$$$$/|  $$$$$$/ /$$$$$$$/  |  $$$$/      |  $$$$$$/ |  $$$$/|  $$$$$$/| $$      |  $$$$$$$"<<endl;
    cout<<"|_______/  |______/  |______/ |_______/    |___/         |______/   |___/   |______/ |__/       |_______/"<<endl;
    this_thread::sleep_for(chrono::seconds(1));


}
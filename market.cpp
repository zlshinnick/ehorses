#include "market.h"

market::market(){

}

void market::initialize(userhorse horse1, userhorse horse2, userhorse horse3,userhorse horse4,userhorse horse5){
    storehorses.push_back(horse1);
    storehorses.push_back(horse2);
    storehorses.push_back(horse3);
    storehorses.push_back(horse4);
    storehorses.push_back(horse5);
}


void market::print_market(){
    cout<<"** Welcome To The Market **"<<endl<<endl;

    for (int i =0; i<storehorses.size();i++){
        cout<<"Horse: "<<storehorses[i].get_name()<<endl;
        cout<<"Top Speed: "<<storehorses[i].get_max()<<endl;
        cout<<"Level: "<<storehorses[i].get_level()<<endl;
        cout<<"Price: "<<i*100<<endl; //need to make a better algorithim for price of horse

        
        cout<<endl;
    }
}
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
        cout<<"Price: "<<storehorses[i].get_price()<<endl; //need to make a better algorithim for price of horse

        
        cout<<endl;
    }
}

userhorse market::get_horse(){
    cout<<"Which Item Would You Like To Purchase?"<<endl;
    int choice_horse;
    cout<<"0: "<<storehorses[0].get_name()<<endl;
    cout<<"1: "<<storehorses[1].get_name()<<endl;
    cout<<"2: "<<storehorses[2].get_name()<<endl;
    cout<<"3: "<<storehorses[3].get_name()<<endl;
    cout<<"4: "<<storehorses[4].get_name()<<endl<<endl;
    cout<<"9: None"<<endl<<endl;

    cout<<"Item To Purchase: ";
    cin>>choice_horse;

    return storehorses[choice_horse];

}
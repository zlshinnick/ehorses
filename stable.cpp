#include "stable.h"
#include "user.h"
#include "horse.h"
#include <chrono>
#include <thread>

stable::stable(){
    max = 0;
    num_of_horses =0;
    array = nullptr;
    
};

void stable::initialize(){
    max = 10;
    num_of_horses = 0;
    array = new userhorse[max];
}

bool stable::add_horse(userhorse h){

    if(num_of_horses<max){
        array[num_of_horses]=h;
        num_of_horses++;
        return true;
    }
    return false;
}

userhorse* stable::get_horses(){
    return array;
}

void stable::print_stable(){
    cout<<endl;
    for(int i=0; i< num_of_horses;i++){
        cout<<"*Horse "<<i+1<<"*"<<endl;
        array[i].print_horse();
        this_thread::sleep_for(chrono::seconds(2));

    }
}

int stable::get_current_num_horses(){
    return num_of_horses;
}

bool stable::add_bred_horse(string _name) {
  //getting parents times
  double p1max = p1.get_max();  
  double p1min = p1.get_min();
  double p2max = p2.get_max();
  double p2min = p2.get_min();

  double bred_max = p1max + p2max; bred_max = bred_max/2;
  double bred_min = p1min + p2min; bred_min = bred_min/2;

  //checking if parents are same gen
  if (p1.get_generation() == p2.get_generation()) {
    
    //setting gen
    int gen = p1.get_generation() + 1;

    //constructing horse and setting its variables
    bred_horse b1 = bred_horse();
    b1.set_bred_horse(_name, bred_max, bred_min, gen);
    b1.set_parents(p1.get_name(), p1.get_max(), p1.get_max(), p2.get_name(), p2.get_max(), p2.get_max());

    //adding horse to stable
    if(num_of_horses<max){
        array[num_of_horses]=b1;
        num_of_horses++;
        return true;
    }

  } else {
    //if not same generation
    return false;
  }
  return false;
}

void stable::set_parents(){
    print_stable();

    int index_first = 0;
    cout<<"\n\n";
    cout<<"Select Parent 1 For Breeding: "<<endl<<endl;

    for(int i = 0; i<num_of_horses;i++){
        cout<<i<<": "<<array[i].get_name()<<endl;
    }
    cout<<"Enter Choice: ";
    cin>>index_first;

    while(index_first>num_of_horses||index_first<0){
        cout<<"Invalid Input"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"Enter Choice: ";
        cin>>index_first;

    }

    p1 = array[index_first];

    int index_second = 0;

    cout<<"Select Parent 2 For Breeding"<<endl<<endl;

    for(int i = 0; i<num_of_horses;i++){
        int tracker =0;
        while (tracker!=index_first)
        cout<<i<<array[i].get_name()<<endl;
        tracker++;
    }

    cout<<"Enter Choice: ";
    cin>>index_second;

        while(index_second>num_of_horses||index_second<0){
        cout<<"Invalid Input"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));
        cout<<"Enter Choice: ";
        cin>>index_second;

    }

    p2 = array[index_second];

}

void stable::breed(){
    if(num_of_horses<2){
        cout<<"You Can Not Breed, You Need At Least 2 Horses";
        return;
    }


    int choice =1 ;
    cout<<"Do You Want To Breed Horses"<<endl<<endl;
    cout<<"1. Yes"<<endl;
    cout<<"2. No"<<endl<<endl;
    cout<<"Choice: ";

    cin>>choice;

    if(choice ==2 ){
        return;
    }

    set_parents();

    string name;
    cout<<"Set Foal Name: ";
    cin>>name;

    bool baby =  add_bred_horse(name);

    if(baby == true){
        this_thread::sleep_for(chrono::seconds(1));
        cout<<p1.get_name()<<"And "<<p2.get_name()<<"Are Fucking Please Wait"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(3));
        cout<<p1.get_name()<<" Has Given Birth"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));


        cout<<name<<" Has Been Born And Added To Stables"<<endl<<endl;
        this_thread::sleep_for(chrono::seconds(2));
    }

    if(baby == false){
        cout<<" Baby Not Born, Parents Cant Be Same Generation!";
    }
}
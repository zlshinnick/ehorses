#include "stable.h"
#include "user.h"
#include "horse.h"
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
    bool add_horse(b1);

    return true;
  
  } else {
    //if not same generation
    return false;
  }
}
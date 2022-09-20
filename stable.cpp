#include "stable.h"
#include "user.h"
#include "horse.h"
stable::stable(){
    capacity = 1;
    num_of_horses =0;
    
};

void stable::add_horse(userhorse new_horse){
    if (num_of_horses < capacity){
        stables.push_back(new_horse);
        num_of_horses++;
    }
}

void stable::print_stable(){
    for(int i = 0; i<num_of_horses;i++){
        cout<<endl;
        cout<<"Name:"<<stables[i].get_name()<<endl;
      //  cout<<"Division:"<<stables[i].get_div()<<endl;

    }
}
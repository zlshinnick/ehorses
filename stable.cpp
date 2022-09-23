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
    array = new horse[max];
}

bool stable::add_horse(horse h){

    if(num_of_horses<max){
        array[num_of_horses]=h;
        num_of_horses++;
        return true;
    }
    return false;
}

horse* stable::get_horses(){
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
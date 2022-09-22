#include "stable.h"
#include "user.h"
#include "horse.h"
stable::stable(){
    max = 0;
    num_of_horses =0;
    array = nullptr;
    
};

stable::stable(int size){
    max = size;
    num_of_horses = 0;
    array = new horse[size];
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
    for(int i=0; i< num_of_horses;i++){
        cout<<array[i].get_name()<<endl;
    }
}
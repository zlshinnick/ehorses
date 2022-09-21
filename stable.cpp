#include "stable.h"
#include "user.h"
#include "horse.h"
stable::stable(){
    capacity = 0;
    num_of_horses =0;
    
};

void stable::add_horse(userhorse new_horse){
    if (num_of_horses < capacity){
        stables.push_back(new_horse);
        num_of_horses++;
    }
}

userhorse stable::operator[](const int index){
    if(index<0||index>num_of_horses){
            throw("Invalid");
    
    }
        return stables[index];
}

void stable::initialize(){
    capacity=1;
    num_of_horses=0;
}


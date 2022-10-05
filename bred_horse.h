#ifndef BRED_HORSE_H
#define BRED_HORSE_H
#include <string>
#include "horse.h"
#include "userhorse.h"
using namespace std;

class bred_horse : public horse, public userhorse {

  public:

    //default constructor
    bred_horse();
    
    //fathers stats
    string dad_name;
    string dad_max_speed;
    string dad_min_speed;

    //mothers stats
    string mum_name;
    string mum_max_speed;
    string mum_min_speed;

    void set_parents(string dad_name, string dad_max, string dad_min);

    

};

#endif
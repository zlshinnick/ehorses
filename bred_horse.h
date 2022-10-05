#ifndef BRED_HORSE_H
#define BRED_HORSE_H
#include <string>
#include "horse.h"
#include "userhorse.h"
using namespace std;

class bred_horse : public userhorse {

  public:

    //default constructor
    bred_horse();
    
    //fathers stats
    string dad_name;
    double dad_max_speed;
    double dad_min_speed;

    //mothers stats
    string mum_name;
    double mum_max_speed;
    double mum_min_speed;

    void set_bred_horse(string _name, double max, double min);
    void set_parents(string dad_name, double dad_max, double dad_min, string mum_name, double mum_max, double mum_min);

};

#endif
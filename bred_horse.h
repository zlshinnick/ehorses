#ifndef BRED_HORSE_H
#define BRED_HORSE_H
#include <string>
#include "horse.h"
#include "userhorse.h"
using namespace std;

class bred_horse : public horse, public userhorse {

  public:

    
    //fathers stats
    string f_name;
    string f_max_speed;
    string f_min_speed;

    //mothers stats
    string m_name;
    string m_max_speed;
    string m_min_speed;

    void set_bred_horse(string _name, userhorse h1, userhorse h2);

};

#endif
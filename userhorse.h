#ifndef USERHORSE_H
#define USERHORSE_H
#include <string>
#include "horse.h"
using namespace std;

class userhorse : public horse {

  public:
  	double max_speed;
    double min_speed;
    int level;

    userhorse();    //default constructor (probably shouldnt use)
    userhorse(double max, double min, int l);    //constructs a horse for a respective race

    void set_max(double max);
    void set_min(double min);
    void set_level(int l);
    double get_max();
    double get_min();
    int get_level();

};
#endif
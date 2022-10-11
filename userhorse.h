#ifndef USERHORSE_H
#define USERHORSE_H
#include <string>
#include "horse.h"
using namespace std;

class userhorse : public horse {

  public:

    userhorse();

    //setting userhorse variables (esstenitally a constructor)
    void set_userhorse(string _name, double max, double min); //, string _gender);

    //get and set each attribute
    void set_max(double max);
    void set_min(double min);
    void set_level(int l);
    void set_points(int p);
    void set_price(int _price);
    double get_max();
    double get_min();
    int get_level();
    int get_points();
    int get_wins();
    int get_price();
    int get_generation();
    //string get_gender();

    //in game functions
    void increment_wins();
    void level_up();

    //sets random race time in max_speed to min_speed interval (call before each race)
    void set_rand_race_time();
    

};
#endif
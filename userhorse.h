#include <string>
#include "horse.h"
#pragma once
using namespace std;

class userhorse : public horse {

  public:

    userhorse();

    //setting userhorse variables (esstenitally a constructor)
    void set_userhorse(string _name, double max, double min);

    //get and set each attribute
    void set_max(double max);
    void set_min(double min);
    void set_level(int l);
    void set_price(int _price);
    double get_max();
    double get_min();
    int get_level();
    int get_wins();
    int get_price();
    int get_generation();
    
    //print functions
    void output_name();
    void output_min();
    void output_max();
    void output_wins();

    //in game functions
    void increment_wins();
    void level_up();
    void add_boost(double t);

    //sets random race time in max_speed to min_speed interval (call before each race)
    void set_rand_race_time();
    
    //functions for when each division is won
    void win_D1();
    void win_D2();
    void win_D3();

};